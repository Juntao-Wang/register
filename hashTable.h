//
//  hashTable.h
//  2012h_test
//
//  Created by WANG Juntao on 22/11/2016.
//  Copyright © 2016 WANG Juntao. All rights reserved.
//

#ifndef hashTable_h
#define hashTable_h
#include "Deque.h"
#include <iostream>
#include <string>


using namespace std;
template<typename T>
class hashTable{
private:
    int numOfBuckets;
    Deque<T>* table;
    //this is the outputTable used by some output function to output all the data in sequence.
    Deque<T> outputTable;
public:
    hashTable(): numOfBuckets(1), table(new Deque<T>[1]), outputTable() {}
    hashTable(int n): numOfBuckets(n), table(new Deque<T>[n]), outputTable() {}
    ~hashTable() {delete [] table;}
    //given a correct hashedKey, insert element into the hashTable.
    void insert(T, int hashedKey);
    //given a correct hashedKey, find element in the hashTable.
    node<T>* findElem(T&, int hashedKey);
    //given a correct hashedKey, remove element from the hashTable.
    void removeElem(T&, int hashedKey);
    //given the address in the hashTable, and the correct hashedkey we could also delete it.
    void removeElem(node<T>* addr, int hashedKey);
    //put all the element into the outputTable.
    void putInOutput();
    //return the number of element in the outputTable.
    int numOfOutput() const {return outputTable.size();}
    //clear the hashTable.
    void clear();
    //this iterator is provided to output the data.
    typename Deque<T>::Iterator outputIter() {return outputTable.iterator();}
    //this iterator is provided to operate the element in buckets.
    typename Deque<T>::Iterator itrOfBucket(int pos);
};


template<typename T>
void hashTable<T>::insert(T item, int hashedKey){
    //the hashedKey is calculated by the ojbect provided that a correct number of buckets.
    int pos = hashedKey;
    table[pos].insert(item);
}

template<typename T>
node<T>* hashTable<T>::findElem(T& item, int hashedKey){
    //the hashedKey is calculated by the ojbect provided that a correct number of buckets.
    int pos = hashedKey;
    return table[pos].findOut(item);
}

template<typename T>
void hashTable<T>::removeElem(T& item, int hashedKey){
    //the hashedKey is calculated by the ojbect provided that a correct number of buckets.
    int pos = hashedKey;
    table[pos].remove(item);
}

template<typename T>
void hashTable<T>::removeElem(node<T>* addr, int hashedKey){
    int pos = hashedKey;
    table[pos].remove(addr);
}

template<typename T>
void hashTable<T>::putInOutput(){
    outputTable.clear();
    for(int i = 0; i < numOfBuckets; ++i){
        typename Deque<T>::Iterator itr = table[i].iterator();
        while(itr.get() != NULL){
            outputTable.insert(*itr);
            itr++;
        }
    }
}


template<typename T>
void hashTable<T>::clear(){
    for(int i = 0; i < numOfBuckets; ++i){
        //clear every bucket.
        table[i].clear();
    }
}

template<typename T>
typename Deque<T>::Iterator hashTable<T>::itrOfBucket(int pos){
    if(pos > numOfBuckets || pos < 0) throw runtime_error("the position is beyond the scope!");
    return table[pos].iterator();
}
#endif /* hashTable_h */
