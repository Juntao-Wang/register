//
//  registrationTable.hpp
//  2012h_test
//
//  Created by WANG Juntao on 27/11/2016.
//  Copyright © 2016 WANG Juntao. All rights reserved.
//

#ifndef registrationTable_h
#define registrationTable_h

#include <stdio.h>
#include "courseSelection.h"
#include "Deque.h"
#include "indexOfCourse.h"
#include "indexOfStudent.h"
#include "hashTable.h"


//define the number of buckets of the index tables.
#define NUM_STU_I_BUCKETS 29
#define NUM_COU_I_BUCKETS 17

class registrationTable{
private:
    Deque<courseSelection> table;
    hashTable<IndexOfStudent> studentIndexTable;
    hashTable<IndexOfCourse> courseIndexTable;
    
    //this two sorted doubly linked list are used to output the sorted data.
    Deque<courseSelection> courseOfStudent;
    Deque<courseSelection> studentOfCourse;
    
public:
    registrationTable(): table(), studentIndexTable(hashTable<IndexOfStudent>(NUM_STU_I_BUCKETS)),
                            courseIndexTable(hashTable<IndexOfCourse>(NUM_COU_I_BUCKETS)) {}
    
    //find the course registration based on the information of the student.
    node<courseSelection>* findByStudent(string studentID, string courseCode);
    //find the course registration based on the information of the course.
    node<courseSelection>* findByCourse(string studentID, string courseCode);
    //find  the registration.
    node<courseSelection>* findReg(string studentID, string courseCode);
    //enroll a course.
    bool enroll(string studentID, string courseCode, Student s, Course c);
    //drop a course.
    bool drop(string studentID, string courseCode);
    //modify a registration.
    bool modify(string studentID, string courseCode, string score);
    
    //clear the registration table.
    void clear();
    
    //put the student or the course in a ordered way. used to output the information.
    void putStudentOutput(string studentID);
    void putCourseOutput(string courseCode);
    
    //remove all the courses of a student.
    void removeStuOfCourse(string courseCode);
    //remove all the students of a course.
    void removeCourseOfStu(string studentID);
    
    //return the number of output informations.
    int numOfSelection() const {return table.size();}
    
    //iterators are provided for some operations.
    Deque<courseSelection>::Iterator studentOutIter() {return courseOfStudent.iterator();}
    Deque<courseSelection>::Iterator courseOutIter() {return studentOfCourse.iterator();}
    Deque<courseSelection>::Iterator selectionOutIter() {return table.iterator();}
    
    
    
    
    
};
#endif /* registrationTable_h */
