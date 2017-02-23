
#ifndef Deque_h
#define Deque_h
#include <iostream>
#include <stdexcept>

using namespace std;
using std::runtime_error;


template<typename T>
struct node{
    T elem;
    node<T>* next;
    node<T>* prev;
};


template<typename T>
class Deque{
public:
    //constructor.
    Deque();
    //desctructor.
    ~Deque();
    //clear up the whole list.
    void clear();
    //return: if deque is empty or not.
    bool isEmpty() const;
    //return: the size of deque.
    int size() const;
    //add element to deque in the front.
    node<T>* addFirst(T);
    //add element to deque at the end.
    node<T>* addLast(T);
    //insert a new element in order. This function ensure that the list is sorted in increasing order.
    node<T>* insert(T);
    //this will return the address of the target element. If the element does not exist, then it will return 0.
    node<T>* findOut(T&);
    //remove a element that in the list. If it does not exist, then nothing would happend.
    void remove(T&);
    //if the address of the element can be given, then the element could also be deleted.
    void remove(node<T>*);
    //remoe the first element.
    T removeFirst();
    //remoe the last element.
    T removeLast();
    //iterator class, which can be applied to algorithms implementation.
    class Iterator;
    //return the position of the first element.
    Iterator iterator();
    
private:
    int length;
    node<T>* first;
    node<T>* last;
    
};

template<typename T>
void Deque<T>::clear(){
    while(!isEmpty()){
        removeLast();
    }
}


template <typename T>
node<T>* Deque<T>::insert(T item){
    //use iterator to insert the element.
    Deque<T>::Iterator itr = this->iterator();
    if(itr.get() == NULL){
        //if the list is empty. we insert it in the front.
        return addFirst(item);
    }
    //else it must in between two elements.
    for(int i = 0; i < this->size(); ++i, ++itr){//run through the whole list.
        node<T>* curP = itr.get();//get the current node pointed by the iterator.
        if(item >= (curP->elem)){//if the item is larger than one element in the list.
            if(i == this->size() -1) {
                //if the element is at the last position.
                return addLast(item);
            }
            if(item < ((curP->next)->elem)){//and if the item is smaller than the next element.
                //we would insert it between the them.
                node<T>* newNode = new node<T>;
                newNode->elem = item;
                newNode->next = curP->next;
                newNode->prev = curP;
                (curP->next)->prev = newNode;
                curP->next = newNode;
                length++;
                return newNode;
            }
            
        }else if(item < (curP->elem)){//if the item is smaller than one element in the list.
            if(i == 0) {
                //if the element is at the beginning.
                return addFirst(item);
            }
            //else it must be in between two elements.
            if(item >= (curP->prev)->elem){//and if the item is larger than the previous element in the list.
                //then we insert the item between them.
                node<T>* newNode = new node<T>;
                newNode->elem = item;
                newNode->next = curP;
                newNode->prev = curP->prev;
                (curP->prev)->next = newNode;
                curP->prev = newNode;
                length++;
                return newNode;
            }
        }
    }
    //in case fail to insert.
    return NULL;
}

/**Iterator implementation**/
template<typename T>
class Deque<T>::Iterator{
public:
    //constructor.
    Iterator();
    Iterator(node<T>*);
    Iterator(const Iterator&);
    ~Iterator();
    
    //arithmtic operator.
    Iterator operator++();
    Iterator operator++(int);
    Iterator operator--();
    Iterator operator--(int);
    Iterator operator=(const Iterator&);
    
    //dereference operator
    T& operator*();
    T& operator->();
    
    node<T>* get() const {return curN;}
private:
    node<T>* curN;
    
};

template<typename T>
Deque<T>::Iterator::Iterator(){
    curN = NULL;
}

template<typename T>
Deque<T>::Iterator::Iterator(node<T>* p){
    curN = p;
}

template<typename T>
Deque<T>::Iterator::Iterator(const Iterator& itr){
    curN = itr.get();
}

template<typename T>
Deque<T>::Iterator::~Iterator(){
    curN = NULL;
}

template<typename T>
typename Deque<T>::Iterator Deque<T>::Iterator::operator++(){
    if(curN == NULL) return *this;//prevent the iterator exceeding the range of the list.
    
    curN = curN->next;
    return *this;
}

template<typename T>
typename Deque<T>::Iterator Deque<T>::Iterator::operator++(int){
    Iterator temp = *this;
    if(curN != NULL){//prevent the iterator exceeding the range of the list.
        curN = curN->next;
    }
    return temp;
}


template<typename T>
typename Deque<T>::Iterator Deque<T>::Iterator::operator--(){
    if(curN->prev != NULL){//prevent the iterator exceeding the range of the list.
        curN = curN->prev;
    }
    return *this;
}

template<typename T>
typename Deque<T>::Iterator Deque<T>::Iterator::operator--(int){
    Iterator temp = *this;
    if(curN->prev != NULL){//prevent the iterator exceeding the range of the list.
        curN = curN->prev;
    }
    return temp;
}


template<typename T>
typename Deque<T>::Iterator Deque<T>::Iterator::operator=(const Iterator& itr){
    curN = itr.get();
    return *this;
}


template<typename T>
T& Deque<T>::Iterator::operator*(){//dereference would return the object.
    return curN->elem;
}

template<typename T>
T& Deque<T>::Iterator::operator->(){//dereference would return the object.
    return curN->elem;
}

template<typename T>
typename Deque<T>::Iterator Deque<T>::iterator(){//return the first element position.
    Deque<T>::Iterator iter(first);
    return iter;
}

/**Deque implementation**/
template<typename T>
Deque<T>::Deque(){//initialize deque.
    length = 0;
    first = NULL;
    last = NULL;
}

template<typename T>
Deque<T>::~Deque(){
    while(length != 0){
        removeLast();//if deque is not empty, keep deleting elements in it.
        //when we delete the last element, allocated space would also be freed.
    }
}

template<typename T>
bool Deque<T>::isEmpty() const{
    if(length == 0){//if the length is 0, deque is empty.
        return true;
    }
    return false;
}

template<typename T>
int Deque<T>::size() const{
    return length;//return the number of the objects.
}

template<typename T>
node<T>* Deque<T>::addFirst(T item){
    if(first == NULL){//if deque is empty.
        first = new node<T>;//allocate new space for first.
        last = first;//for only one element, both first and last point to it.
        first->elem = item;//store the element into it.
        first->next = NULL;
        first->prev = NULL;
    }else{//if deque is non-empty.
        node<T>* ptrNew = new node<T>;//allocate new space for a new pointer.
        ptrNew->elem = item;//store the element into it.
        //changed their relations, such that newly inserted object become the first one.
        ptrNew->next = first;
        ptrNew->prev = NULL;
        first->prev = ptrNew;
        first = ptrNew;
    }
    length++;
    return first;
}


template<typename T>
node<T>* Deque<T>::addLast(T item){
    if(first == NULL){//if deque is empty.
        last = new node<T>;//allocate new space for last.
        first = last;//for only one element, both first and last point to it.
        last->elem = item;//store the element into it.
        last->next = NULL;
        last->prev = NULL;
    }else{//if the list is non-empty.
        node<T>* ptrNew = new node<T>;//allocate new space for a new pointer.
        ptrNew->elem = item;//store the element into it.
        //changed their relations, such that newly inserted object become the last one.
        ptrNew->prev = last;
        ptrNew->next = NULL;
        last->next = ptrNew;
        last = ptrNew;
        
    }
    length++;
    return last;
}

template<typename T>
node<T>* Deque<T>::findOut(T& item){
    //we starting the finding process at the beginning of the list.
    node<T>* temp = first;
    //if the list is empty. return 0.
    if(temp == NULL) return 0;
    for(int i = 0; i < size(); ++i){//go through the whole list.
        if(temp->elem == item){
            return temp;//if found return the address.
        }
        temp = temp->next;//proceeding the element.
    }
    return 0;//not found.
}

template<typename T>
void Deque<T>::remove(T& item){
    //starting from the beginning of the list.
    node<T>* temp = first;
    int pos = 0;
    for(;pos < size(); ++pos){
        if(temp->elem == item){
            //if the element is found, the position and the address would be record.
            break;
        }
        
        if(pos == size() -1){//if the whole list has been examined and the element does not exist.
            //we do nothing but return.
            return;
        }
        temp = temp->next;
    }
    
    if(pos == 0){
        //if the element is at the beginning.
        removeFirst();
        return;
    }
    if(pos == size() - 1){
        //it the element is at the last position.
        removeLast();
        return;
    }
    
    //the element is in the middle.
    (temp->prev)->next = temp->next;
    (temp->next)->prev = temp->prev;
    
    delete temp;
    length--;
}

template<typename T>
void Deque<T>::remove(node<T>* addr){
    //according to the position of the element. we do different operation.
    if(addr == first){
        //at the beginning.
        removeFirst();
        return;
    }
    if(addr == last){
        //at the last position.
        removeLast();
        return;
    }
    
    //at the middle.
    (addr->prev)->next = addr->next;
    (addr->next)->prev = addr->prev;
    length --;
    delete addr;
}

template<typename T>
T Deque<T>::removeFirst(){
    if(first == NULL) throw runtime_error("no element to remove!!");
    T DelItem = first->elem;
    node<T>* temp = first;
    if(first->next == NULL){
        //if the list has only one element left, both last and first pointer are pointing to this elment.
        //delete one more time, the whole list is empty, so both last and first pointer should be set to be NULL.
        last = NULL;
        first = NULL;
        delete temp;
        length--;
        return DelItem;
    }else{
        first = first->next;
        first->prev = NULL;
        delete temp;
        length--;
        return DelItem;
    }
}

template<typename T>
T Deque<T>::removeLast(){
    if(last == NULL) throw runtime_error("no element to remove!!");
    T DelItem = last->elem;
    node<T>* temp = last;
    if(last->prev == NULL){
        //if the list has only one element left, both last and first pointer are pointing to this elment.
        //delete one more time, the whole list is empty, so both last and first pointer should be set to be NULL.
        first = NULL;
        last = NULL;
        delete temp;
        length--;
        return DelItem;
    }else{
        node<T>* temp = last;
        last = last->prev;
        last->next = NULL;
        delete temp;
        length--;
        return DelItem;
    }
}








#endif /* Deque_h */
