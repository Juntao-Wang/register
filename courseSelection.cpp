//
//  courseSelection.cpp
//  2012h_test
//
//  Created by WANG Juntao on 27/11/2016.
//  Copyright © 2016 WANG Juntao. All rights reserved.
//

#include "courseSelection.h"

#include <iostream>
#include <string>

using namespace std;

//this operator could be used to output the information of the registration information, when client requests a query.
ostream& operator<<(ostream& os, const courseSelection& c){
    os << "student ID:  " << c.getID() <<endl;
    os << "course Code: " << c.getCourse() <<endl;
    os << "exam Mark:   " << c.getExam() <<endl;
    return os;
}

//overload the operators.
bool operator<(const courseSelection& c1, const courseSelection& c2){
    if(c1.studentID == c2.studentID) return c1.courseCode < c2.courseCode;
    return c1.studentID < c2.studentID;
}

bool operator>(const courseSelection& c1, const courseSelection& c2){
    if(c1.studentID == c2.studentID) return c1.courseCode > c2.courseCode;
    return c1.studentID > c2.studentID;
}

bool operator<=(const courseSelection& c1, const courseSelection& c2){
    if(c1.studentID == c2.studentID) return c1.courseCode <= c2.courseCode;
    return c1.studentID <= c2.studentID;
}

bool operator>=(const courseSelection& c1, const courseSelection& c2){
    if(c1.studentID == c2.studentID) return c1.courseCode >= c2.courseCode;
    return c1.studentID >= c2.studentID;
}

bool operator==(const courseSelection& c1, const courseSelection& c2){
    if(c1.studentID == c2.studentID) return c1.courseCode == c2.courseCode;
    return false;
}

