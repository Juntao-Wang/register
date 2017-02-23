  Project name: Register
  =============================================================
  Author
  ==============================================================
  Name: WANG Juntao
  Student ID: 20255651
  email: jwangcc@ust.hk
  
  How-to-compile-and-run
  ==============================================================

  >gmake
  >./Register
  
  Technical Details
  ==============================================================
  
  Deviation from sample program
    for some output format, it may deviate in the number of spacing
    lines between two output information messages.
    and some successful and failed messages may have slightly difference.
    Also, once a course or a student is deleted, related registration
    information would also be deleted.
  
  Design of the project:
    detailed design requirments could be found in 
    https://course.cse.ust.hk/comp2012h/Password_Only/projects/register/index.html
    so here I would only talk about extra design.

    Firstly,
    Deque.h:
    the doubly linked list, namely Deque, is desgned as a template class. 
    The method functions of this class is simliar to a doubly linked queue
    (Deque). Based on the basic functions of Deque, I have implemented 
    four important functions:
      1. node<T>* insert(T)
      this function is the extension of the addFirst and addLast, and 
      we can ensure that the inserted element would be in an ordered
      sequence. And the return type of this function is the address 
      of the inserted element. Based on this, we could easily satisfy
      the requirment, which a studentIndex type (detailed can be found
      in the website) should have a pointer pointing to a newly inserted 
      element.
      2. void remove(T)
      I also extended the removeLast and removeFirst to a function called 
      void remove(T). Based on this, we could remove the element at the any 
      position.
      3. void remove(node<T>*)
      I also implemented a remove function which takes address of the element,
      so that we could delete the element in a very fast and accurate way.
      And this also make the deletion of any information easier.
      4. bool findOut(T)
      iterator is used by this function to examine through the whole list to 
      find out the required element.

    secondly, hashTable is implemented based on the template class Deque. The 
    operations of the hashTable are based on the Deque operations.
    also, when we make the hashTable a template class, the hashmap function implementation
    become difficult.
    To solve this problem, instead of the traditional way which make hashMap a 
    template class. I embed the hashmap function into the Student and Course type,
    if the correct number of hashTable buckets is provided, then the hashed value 
    could be calculated correctly inside the Student and Course type.

    thirdly, registration table is implemented as required. And the registration 
    table stored all the registration information. 

    fourthly, because the data stored in hashTable would lose their order.
    To output the required data in sequence, I would insert the data into a newly 
    generated Deque, in this way, the data in deque are guarantee to be ordered.

    fifthly, the kernel parts of the program have already been introduced. 
    And the remaining part is the tedious work, we have to check to input information
    from the user and give them feedback. Also we also write up the .html report output 
    and .dat data base output in some certain formats.

    all these are about the design of this project.
    detailed implementation could be found in the source code.





