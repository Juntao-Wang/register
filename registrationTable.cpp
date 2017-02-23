//
//  registrationTable.cpp
//  2012h_test
//
//  Created by WANG Juntao on 27/11/2016.
//  Copyright © 2016 WANG Juntao. All rights reserved.
//

#include "registrationTable.h"
#include <iostream>
#include <string>

using namespace std;

void registrationTable::clear(){
    table.clear();
    studentIndexTable.clear();
    courseIndexTable.clear();
}

void registrationTable::putStudentOutput(string studentID){
    //firstly, clear up the output table.
    courseOfStudent.clear();
    //use index of student to find all the course taken by the student.
    IndexOfStudent studentIndex = IndexOfStudent(studentID);
    //use the iterator to examine through the courseSelection information.
    Deque<IndexOfStudent>::Iterator itr = studentIndexTable.findElem(studentIndex, studentIndex.getKey(NUM_STU_I_BUCKETS));
    while(itr.get() != NULL){//here itr.get() would return the address, to which itr points.
        if(studentIndex == *itr){//the student ID is matched.
            //put the course taken by the same student into the courseOfStudent, so that it can be used to output in sequence.
            node<courseSelection>* temp = (*itr).Pointer();//find the courseSelection information.
            courseOfStudent.insert(temp->elem);//insert the record.
        }
        itr++;
    }
    
}

void registrationTable::putCourseOutput(string courseCode){
    //firstly, clear up the output table.
    studentOfCourse.clear();
    //use index of student to find all the course taken by the student.
    IndexOfCourse courseIndex = IndexOfCourse(courseCode);
    //use the iterator to examine through the courseSelection information.
    Deque<IndexOfCourse>::Iterator itr = courseIndexTable.findElem(courseIndex, courseIndex.getKey(NUM_COU_I_BUCKETS));
    while(itr.get() != NULL){//here itr.get() would return the address, to which itr points.
        if(courseIndex == *itr){//the student ID is matched.
            //put the course taken by the same student into the courseOfStudent, so that it can be used to output in sequence.
            node<courseSelection>* temp = (*itr).Pointer();//find the courseSelection information.
            studentOfCourse.insert(temp->elem);//insert the record.
        }
        itr++;
    }
}

void registrationTable::removeCourseOfStu(string studentID){
    //firstly, resorting to outputTable, we could find all the course that the student takes.
    putStudentOutput(studentID);
    //then we drop them all by using iterator.
    Deque<courseSelection>::Iterator itr = studentOutIter();
    while (itr.get() != NULL){
        drop(studentID, (*itr).getCourse());
        itr++;
    }
}

void registrationTable::removeStuOfCourse(string courseCode){
    //firstly, resorting to outputTable, we could find all the student that the course has.
    putCourseOutput(courseCode);
    //then we drop them all by using iterator.
    Deque<courseSelection>::Iterator itr = courseOutIter();
    while (itr.get() != NULL){
        drop((*itr).getID(), courseCode);
        itr++;
    }
}


node<courseSelection>* registrationTable::findByStudent(string studentID, string courseCode){
    //the information of the student and course.
    courseSelection target = courseSelection(studentID, courseCode);
    
    //use index of student to find the courseSelection information.
    IndexOfStudent studentIndex = IndexOfStudent(studentID);
    
    //we need to find out the address where courseSelection stored.
    node<courseSelection>* addr = 0;
    //use the iterator to examine through the courseSelection information.
    Deque<IndexOfStudent>::Iterator itr = studentIndexTable.findElem(studentIndex, studentIndex.getKey(NUM_STU_I_BUCKETS));
    
    //now we need to find the address of the courseSelection.
    //so we examine through the studentIndex list with the same ID.
    while(itr.get() != NULL){//here itr.get() would return the address, to which itr points.
        
        if(studentIndex == *itr){//the student ID is matched.
            node<courseSelection>* temp = (*itr).Pointer();//find the courseSelection information.
            if(temp->elem == target){//if the information is matched.
                addr = temp;
                break;
            }
        }
        itr++;
    }
    return addr;
}

node<courseSelection>* registrationTable::findByCourse(string studentID, string courseCode){
    //the information of the student and course.
    courseSelection target = courseSelection(studentID, courseCode);
    
    //use index of course to find the courseSelection information.
    IndexOfCourse courseIndex = IndexOfCourse(courseCode);
    
    //we need to find out the address where courseSelection stored.
    node<courseSelection>* addr = 0;
    //use the iterator to examine through the courseSelection information.
    Deque<IndexOfCourse>::Iterator itr = courseIndexTable.findElem(courseIndex, courseIndex.getKey(NUM_COU_I_BUCKETS));
    
    //now we need to find the address of the courseSelection.
    //so we examine through the studentIndex list with the same ID.
    while(itr.get() != NULL){//here itr.get() would return the address, to which itr points.
        if(courseIndex == *itr){//the course code is matched.
            node<courseSelection>* temp = (*itr).Pointer();//find the courseSelection information.
            if(temp->elem == target){//if the information is matched.
                addr = temp;
                break;
            }
        }
        itr++;
    }
    return addr;
    
    
}

node<courseSelection>* registrationTable::findReg(string studentID, string courseCode ){
    courseSelection test = courseSelection(studentID, courseCode);
    node<courseSelection>* temp = table.findOut(test);
    return temp;
}

bool registrationTable::enroll(string studentID, string courseCode, Student s, Course c){

    node<courseSelection>* addr = findByStudent(studentID, courseCode);
    if(addr){
        //if it can be found.
        return false;
    }else{
        courseSelection newEnroll = courseSelection(studentID, courseCode, s, c);
        node<courseSelection>* p = table.insert(newEnroll);
        IndexOfStudent studentIndex = IndexOfStudent(studentID, p);
        IndexOfCourse courseIndex = IndexOfCourse(courseCode, p);
        studentIndexTable.insert(studentIndex, studentIndex.getKey(NUM_STU_I_BUCKETS));
        courseIndexTable.insert(courseIndex, courseIndex.getKey(NUM_COU_I_BUCKETS));
        
        //insert successfully.
        return true;
    }
}

bool registrationTable::drop(string studentID, string courseCode){
    
    node<courseSelection>* addr = findByStudent(studentID, courseCode);
    if(addr){
        //if it can be found.
        table.remove(addr);
        IndexOfStudent studentIndex = IndexOfStudent(studentID, addr);
        IndexOfCourse courseIndex = IndexOfCourse(courseCode, addr);
        //here we notice that we have to do some trade-off.
        //because we did not overload the operator==, in order to find the courses (students) of a student (course) more easily.
        //we have to rewrite the remove function in order to delete the right studentIndex.
        Deque<IndexOfStudent>::Iterator itrOfStu = studentIndexTable.itrOfBucket(studentIndex.getKey(NUM_STU_I_BUCKETS));
        Deque<IndexOfCourse>::Iterator itrOfCou = courseIndexTable.itrOfBucket(courseIndex.getKey(NUM_COU_I_BUCKETS));
        
        while(itrOfStu.get() != NULL){
            if(studentIndex == *itrOfStu && (*itrOfStu).Pointer() == studentIndex.Pointer()){
                studentIndexTable.removeElem(itrOfStu.get(), studentIndex.getKey(NUM_STU_I_BUCKETS));
                break;
            }
            itrOfStu++;
        }
        
        while(itrOfCou.get() != NULL){
            if(courseIndex == *itrOfCou && (*itrOfCou).Pointer() == courseIndex.Pointer()){
                courseIndexTable.removeElem(itrOfCou.get(), courseIndex.getKey(NUM_COU_I_BUCKETS));
                break;
            }
            itrOfCou++;
        }
        
        return true;
    }else{
        
        //no record.
        return false;
    }
    
}

bool registrationTable::modify(string studentID, string courseCode, string score){
    node<courseSelection>* addr = findByStudent(studentID, courseCode);
    
    if(addr == 0) return false;
    addr->elem.setExam(score);
    return true;
    
}
