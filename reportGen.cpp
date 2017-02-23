//
//  reportGen.cpp
//  2012h_test
//
//  Created by WANG Juntao on 28/11/2016.
//  Copyright © 2016 WANG Juntao. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "registerSystem.h"

void registerSystem::reportMenu(){
    clearScreen();
    cout << "HKUST Course Registration System  (Report Generation Menu)" <<endl;
    cout << "----------------------------------------------------------" <<endl;
    cout << endl;
    cout << "1. List all student information" <<endl;
    cout << "2. List all course information" <<endl;
    cout << "3. List all courses of a student" <<endl;
    cout << "4. List all students of a course" <<endl;
    cout << "5. Go back to main menu" <<endl;
    cout << endl;
    int input = numInput(5);
    switch(input){
        case 1:
            listStudent();
        case 2:
            listCourse();
        case 3:
            listCourseOfStudent();
        case 4:
            listStudentOfCourse();
        case 5:
            mainMenu();
        default:
            break;
    }
}

//write the output file in some format.
void registerSystem::listStudent(){
    ofstream file;
    file.open("Students.html");
    
    hashStudent.putInOutput();
    Deque<Student>::Iterator itr = hashStudent.outputIter();
    
    file << "<HTML>" <<endl;
    file << "<HEAD>" <<endl;
    file << "<HEAD>" <<endl;
    file << "<TITLE>All Students List</TITLE>" <<endl;
    file << "</HEAD>" <<endl;
    file << "<BODY bgColor=#ffffcc>" <<endl;
    file << "<H1><FONT color=#6600ff>HKUST Course Registration System</FONT></H1>" <<endl;
    file << "<H2>All Students List</H2>" <<endl;
    file << "<P>" <<endl;
    
    if(itr.get() == NULL){//if no student could be found.
        file <<"No student found" <<endl;
        file << "</P>" <<endl;
        file <<"</BODY>" <<endl;
        file <<"</HTML>" <<endl;
        
        file.close();
        cout << "output successfully!" <<endl;
        enterToCon();
        return;
        
    }
    file << "<TABLE cellSpacing=1 cellPadding=1 border=1>" <<endl;
    file <<endl;
    file << "<TR>" <<endl;
    file << "<TD>Student ID</TD>" <<endl;
    file << "<TD>Student Name</TD>" <<endl;
    file << "<TD>Year</TD>" <<endl;
    file << "<TD>Gender</TD>" <<endl;
    file << "</TR>" <<endl;
    file << endl;
    
    
    while(itr.get() != NULL){//processing all the students.
        file <<"<TR>" <<endl;
        file << "<TD>"<< (*itr).getID() <<"</TD>" <<endl;
        file << "<TD>"<< (*itr).getName() <<"</TD>" <<endl;
        file << "<TD>"<< (*itr).getYear() <<"</TD>" <<endl;
        if((*itr).getGender() == "M"){
            file << "<TD>"<< "Male"<<"</TD>" <<endl;
        }else if((*itr).getGender() == "F"){
            file << "<TD>"<< "Female"<<"</TD>" <<endl;
        }
        file << "</TR>" <<endl;
        file <<endl;
        
        itr++;
    }
    
    file << "</TABLE>" <<endl;
    file << "</P>" <<endl;
    file << "</BODY>" <<endl;
    file << "</HTML>" <<endl;
    
    file.close();
    
    cout << "output successful!" <<endl;
    
    enterToCon();
}

//write the output file in some format.
void registerSystem::listCourse(){
    ofstream file;
    file.open("Courses.html");
    
    hashCourse.putInOutput();
    Deque<Course>::Iterator itr = hashCourse.outputIter();
    
    file << "<HTML>" <<endl;
    file << "<HEAD>" <<endl;
    file << "<HEAD>" <<endl;
    file << "<TITLE>All Course List</TITLE>" <<endl;
    file << "</HEAD>" <<endl;
    file << "<BODY bgColor=#ffffcc>" <<endl;
    file << "<H1><FONT color=#6600ff>HKUST Course Registration System</FONT></H1>" <<endl;
    file << "<H2>All Courses List</H2>" <<endl;
    file << "<P>" <<endl;
    
    if(itr.get() == NULL){//if no curse could be found.
        file <<"No course found" <<endl;
        file << "</P>" <<endl;
        file <<"</BODY>" <<endl;
        file <<"</HTML>" <<endl;
        
        file.close();
        cout << "output successfully!" <<endl;
        enterToCon();
        return;
        
    }
    
    file << "<TABLE cellSpacing=1 cellPadding=1 border=1>" <<endl;
    file <<endl;
    file << "<TR>" <<endl;
    file << "<TD>Course Code</TD>" <<endl;
    file << "<TD>Course Name</TD>" <<endl;
    file << "<TD>Credit</TD>" <<endl;
    file << "</TR>" <<endl;
    file << endl;

    
    while(itr.get() != NULL){//processing all the courses.
        file << "<TR>" <<endl;
        file << "<TD>"<< (*itr).getCode() <<"</TD>" <<endl;
        file << "<TD>"<< (*itr).getName() <<"</TD>" <<endl;
        file << "<TD>"<< (*itr).getCredit() <<"</TD>" <<endl;
        file << "</TR>" <<endl;
        file <<endl;
        
        itr++;
    }
    
    file << "</TABLE>" <<endl;
    file << "</P>" <<endl;
    file << "</BODY>" <<endl;
    file << "</HTML>" <<endl;
    
    file.close();
    
    cout << "output successfully!" <<endl;
    
    enterToCon();
}

//write the output file in some format.
void registerSystem::listCourseOfStudent(){
    string input = IDInput();
    
    Student s(input);
    node<Student>* addr =hashStudent.findElem(s, s.getKey(NUM_STU_BUCKETS));
    if(!addr){
        cout << "Student not exists." <<endl;
        cout << "failed to output." <<endl;
        enterToCon();
        return;
    }
    
    string studentName = (addr->elem).getName();
    
    regTable.putStudentOutput(input);
    Deque<courseSelection>::Iterator itr = regTable.studentOutIter();
    ofstream file;
    string fileName = input + ".html";
    file.open(fileName);
    
    file << "<HTML>" <<endl;
    file << "<HEAD>" <<endl;
    file << "<HEAD>" <<endl;
    file << "<TITLE>Course Records for Student "<<input <<"</TITLE>" <<endl;
    file << "</HEAD>" <<endl;
    file << "<BODY bgColor=#ffffcc>" <<endl;
    file << "<H1><FONT color=#6600ff>HKUST Course Registration System</FONT></H1>" <<endl;
    file << "<H2>Course Records for Student:"<< studentName<< " ("<< input <<")" << "</H2>" <<endl;
    file << "<P>" <<endl;
    
    if(itr.get() == NULL){//if no course.
        file <<"No course found" <<endl;
        file << "</P>" <<endl;
        file <<"</BODY>" <<endl;
        file <<"</HTML>" <<endl;
        
        file.close();
        cout << "output successfully!" <<endl;
        enterToCon();
        return;
        
    }
    
    file << "<TABLE cellSpacing=1 cellPadding=1 border=1>" <<endl;
    file << endl;
    file << "<TR>" <<endl;
    file << "<TD>Course Code</TD>" <<endl;
    file << "<TD>Course Name</TD>" <<endl;
    file << "<TD>Credit</TD>" <<endl;
    file << "<TD>Exam Mark</TD>" <<endl;
    file << "</TR>" <<endl;
    file <<endl;
    
    while(itr.get() != NULL){
        file << "<TR>" <<endl;
        file << "<TD>"<< (*itr).getCourse() <<"</TD>" <<endl;
        file << "<TD>"<< (*itr).getCourseName()<<"</TD>" <<endl;
        file << "<TD>"<< (*itr).getCredit()<<"</TD>" <<endl;
        file << "<TD>"<< (*itr).getExam()<<"</TD>" <<endl;
        file << "</TR>" <<endl;
        file <<endl;
        
        itr++;
    }
    
    file <<"</TABLE>" <<endl;
    file <<"</P>" <<endl;
    file <<"</BODY>" <<endl;
    file <<"</HTML>" <<endl;
    
    file.close();
    cout << "output successfully!" <<endl;
    
    enterToCon();
    
}

//write the output file in some format.
void registerSystem::listStudentOfCourse(){
    string input =CodeInput();
    
    Course c(input);
    node<Course>* addr =hashCourse.findElem(c, c.getKey(NUM_COU_BUCKETS));
    if(!addr){//if the course does not exist.
        cout << "Course not exists." <<endl;
        cout << "failed to output." <<endl;
        enterToCon();
        return;
    }
    
    string courseName = (addr->elem).getName();
    regTable.putCourseOutput(input);
    Deque<courseSelection>::Iterator itr = regTable.courseOutIter();
    
    ofstream file;
    string fileName = input + ".html";
    file.open(fileName);
    
    file << "<HTML>" <<endl;
    file << "<HEAD>" <<endl;
    file << "<HEAD>" <<endl;
    file << "<TITLE>Student Records for Course "<<input <<"</TITLE>" <<endl;
    file << "</HEAD>" <<endl;
    file << "<BODY bgColor=#ffffcc>" <<endl;
    file << "<H1><FONT color=#6600ff>HKUST Course Registration System</FONT></H1>" <<endl;
    file << "<H2>Student Records for Course:"<< courseName<< " ("<< input <<")" << "</H2>" <<endl;
    file << "<P>" <<endl;
    
    if(itr.get() == NULL){//if no student is found.
        file <<"No student found" <<endl;
        file << "</P>" <<endl;
        file <<"</BODY>" <<endl;
        file <<"</HTML>" <<endl;
        
        file.close();
        cout << "output successfully!" <<endl;
        enterToCon();
        return;
        
    }
    
    file << "<TABLE cellSpacing=1 cellPadding=1 border=1>" <<endl;
    file << endl;
    file << "<TR>" <<endl;
    file << "<TD>Student ID</TD>" <<endl;
    file << "<TD>Student Name</TD>" <<endl;
    file << "<TD>Year</TD>" <<endl;
    file << "<TD>Gender</TD>" <<endl;
    file << "<TD>Exam Mark</TD>" <<endl;
    file << "</TR>" <<endl;
    file <<endl;
    while(itr.get() != NULL){//proceeding until all the students have been processed.
        file << "<TR>" <<endl;
        file << "<TD>"<< (*itr).getID() <<"</TD>" <<endl;
        file << "<TD>"<< (*itr).getStudentName()<<"</TD>" <<endl;
        file << "<TD>"<< (*itr).getYear()<<"</TD>" <<endl;
        if((*itr).getGender() == "M"){
            file << "<TD>"<< "Male"<<"</TD>" <<endl;
        }else if((*itr).getGender() == "F"){
            file << "<TD>"<< "Female"<<"</TD>" <<endl;
        }
        file << "<TD>"<< (*itr).getExam()<<"</TD>" <<endl;
        file << "</TR>" <<endl;
        file <<endl;
        
        itr++;
    }
    
    file <<"</TABLE>" <<endl;
    file <<"</P>" <<endl;
    file <<"</BODY>" <<endl;
    file <<"</HTML>" <<endl;
    
    file.close();
    cout << "output successfully!" <<endl;
    
    enterToCon();
    
}



