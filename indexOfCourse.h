//
//  indexOfCourse.hpp
//  2012h_test
//
//  Created by WANG Juntao on 27/11/2016.
//  Copyright © 2016 WANG Juntao. All rights reserved.
//

#ifndef indexOfCourse_h
#define indexOfCourse_h

#include <stdio.h>
#include <iostream>
#include <string>
#include "Course.h"
#include "courseSelection.h"

using namespace std;
template<typename T>
class node;

class IndexOfCourse : public Course{
private:
    node<courseSelection>* pointer;
public:
    IndexOfCourse(): Course(""), pointer(NULL) {}
    IndexOfCourse(string s, node<courseSelection>* p = 0): Course(s), pointer(p) {}
    node<courseSelection>* Pointer() const {return pointer;}
    
    virtual ostream& doPrint(ostream& os) const;
};
#endif /* indexOfCourse_h */
