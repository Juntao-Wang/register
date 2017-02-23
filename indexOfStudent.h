//
//  index.h
//  2012h_test
//
//  Created by WANG Juntao on 27/11/2016.
//  Copyright © 2016 WANG Juntao. All rights reserved.
//

#ifndef index_h
#define index_h

#include <iostream>
#include <string>
#include "Student.h"
#include "Course.h"
#include "courseSelection.h"

using namespace std;

template<typename T>
class node;

class IndexOfStudent : public Student{
private:
    node<courseSelection>* pointer;
public:
    IndexOfStudent(): Student(""), pointer(NULL) {}
    IndexOfStudent(string s, node<courseSelection>* p = 0): Student(s), pointer(p) {}
    node<courseSelection>* Pointer() const{return pointer;}
    
    virtual ostream& doPrint(ostream& os) const;
    
};



#endif /* index_h */
