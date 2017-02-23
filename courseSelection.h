//
//  courseSelection.hpp
//  2012h_test
//
//  Created by WANG Juntao on 27/11/2016.
//  Copyright © 2016 WANG Juntao. All rights reserved.
//

#ifndef courseSelection_h
#define courseSelection_h

#include <stdio.h>
#include <iostream>
#include <string>
#include "Student.h"
#include "Course.h"

using namespace std;

class courseSelection{
private:
    string studentID;
    string courseCode;
    string examMark;
    Student student;
    Course course;
public:
    courseSelection(): studentID(""), courseCode(""), examMark("N/A"), student(), course() {}
    courseSelection(string s, string c, Student stu = Student(), Course cour = Course(), string e = "N/A"): studentID(s), courseCode(c), student(stu), course(cour), examMark(e) {}
    void setExam(string e) {examMark = e;}
    
    //get functions.
    string getID() const {return studentID;}
    string getStudentName() const {return student.getName();}
    int getYear() const {return student.getYear();}
    string getGender() const {return student.getGender();}
    string getCourse() const {return courseCode;}
    string getCourseName() const {return course.getName();}
    int getCredit() const {return course.getCredit();}
    string getExam() const {return examMark;}
    
    //operators overload.
    friend ostream& operator<<(ostream& os, const courseSelection& c);
    friend bool operator<(const courseSelection& c1, const courseSelection& c2);
    friend bool operator>(const courseSelection& c1, const courseSelection& c2);
    friend bool operator<=(const courseSelection& c1, const courseSelection& c2);
    friend bool operator>=(const courseSelection& c1, const courseSelection& c2);
    friend bool operator==(const courseSelection& c1, const courseSelection& c2);
    
    
    
};
#endif /* courseSelection_h */
