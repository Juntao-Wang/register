//
//  register.hpp
//  2012h_test
//
//  Created by WANG Juntao on 27/11/2016.
//  Copyright © 2016 WANG Juntao. All rights reserved.
//

#ifndef register_h
#define register_h

#include <iostream>
#include <string>
#include "Deque.h"
#include "hashTable.h"
#include "Student.h"
#include "Course.h"
#include "indexOfCourse.h"
#include "indexOfStudent.h"
#include "courseSelection.h"
#include "registrationTable.h"
#include <math.h>

#define NUM_STU_BUCKETS 29
#define NUM_COU_BUCKETS 17

class registerSystem{
private:
    hashTable<Student> hashStudent;
    hashTable<Course> hashCourse;
    registrationTable regTable;
public:
    registerSystem(): hashStudent(hashTable<Student>(NUM_STU_BUCKETS)), hashCourse(hashTable<Course>(NUM_COU_BUCKETS)),regTable() { mainMenu();}
    
    //used to clean the screen.
    void clearScreen(){cout << "\033[2J\033[1;1H";}
    //used to inform the incorrect input.
    void reEnter(){cout << "Invalid input, re-enter again: ";}
    
    //used to require correct number input.
    int numInput(int size);
    //used to output the message enter to continue.
    void enterToCon();
    
    //used to require correct ID input.
    string IDInput();
    //used to require correct student name input.
    string stuInput();
    //used to require correct modify student name input.
    string modStuInput(string currName);
    //used to require correct year input.
    int yearInput();
    //used to require correct modify year input.
    int modYearInput(int currYear);
    //used to require correct gender input.
    string genderInput();
    //used to require correct modify gender input.
    string modGenderInput(string currGender);
    
    //insert student.
    bool insertStudent();
    //modify student.
    void modifyStudent();
    //query student.
    void queryStudent();
    //delete student.
    void deleteStudent();
    
    //insert course.
    bool insertCourse();
    //modify course.
    void modifyCourse();
    //query course.
    void queryCourse();
    //delete course.
    void deleteCourse();
    
    //verify the file number input.
    bool verifyInt(string in);
    //verify the file ID input.
    bool verifyID(string ID);
    //verify the file student input.
    bool verifyStudentName(string name);
    //verify the file year input.
    bool verifyYear(string year);
    //verify the file gender input.
    bool verifyGender(string gender);
    
    //verify the file code input.
    bool verifyCode(string code);
    //verify the file course name input.
    bool verifyCourseName(string name);
    //verify the file course credit input.
    bool verifyCredit(string credit);
    //verify the file exam mark input.
    bool verifyExam(string score);
    
    //load file.
    void loadError();
    
    //used to require correct course code input.
    string CodeInput();
    //used to require correct course name input.
    string courseInput();
    //used to require correct modify course name input.
    string modCourseInput(string currName);
    int creditInput();
    //used to require correct modify credit input.
    int modCreditInput(int currCredit);
    //used to require correct modify exam input.
    string modExamInput(string currMark);
    
    //add course.
    bool addCourse();
    //drop course.
    void dropCourse();
    //modify exam.
    void modifyExam();
    //query registration.
    void queryReg();
    
    //list all student.
    void listStudent();
    //list all course.
    void listCourse();
    //list the courses of a student.
    void listCourseOfStudent();
    //list the students of a course.
    void listStudentOfCourse();
    
    //menus.
    void mainMenu();
    void studentMenu();
    void courseMenu();
    void courseRegMenu();
    void reportMenu();
    void fileMenu();
    
    //save and load file.
    void saveFile();
    void loadFile();
};
#endif /* register_h */
