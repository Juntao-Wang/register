//
//  fileGen.cpp
//  2012h_test
//
//  Created by WANG Juntao on 30/11/2016.
//  Copyright © 2016 WANG Juntao. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "registerSystem.h"

using namespace std;

//output menu information.
void registerSystem::fileMenu(){
    clearScreen();
    cout << "HKUST Course Registration System  (File Menu)" <<endl;
    cout << "---------------------------------------------" <<endl;
    cout <<endl;
    cout << "1. Save Database" <<endl;
    cout << "2. Load Database" <<endl;
    cout << "3. Go back to main menu" <<endl;
    cout << endl;
    int input = numInput(3);
    switch(input){
        case 1:
            saveFile();
            break;
        case 2:
            loadFile();
            break;
        case 3:
            mainMenu();
            break;
        default:
            break;
    }
}

//verify the whether the input is correct.
bool registerSystem::verifyInt(string in){
    bool has_only_digits = (in.find_first_not_of( "0123456789" ) == string::npos);
    if(has_only_digits){
        return true;
    }else{
        return false;
    }
    
}

//verify the whether the input is correct.
bool registerSystem::verifyID(string ID){
    if(ID.size() != 8){
        return false;
    }
    for(int i = 0; i < 8; ++i){
        if(ID[i] - '0' <0 || ID[i] - '0' >9){
            return false;
        }
    }
    return true;
}

//verify the whether the input is correct.
bool registerSystem::verifyStudentName(string name){
    if(name.size() == 0 || name.size() > 32) return false;
    
    return true;
}

//verify the whether the input is correct.
bool registerSystem::verifyYear(string year){
    if(year.size() != 1) return false;
    if(year[0] -'0' < 1 || year[0] - '0' > 3) return false;
    return true;
}

//verify the whether the input is correct.
bool registerSystem::verifyGender(string gender){
    if(gender.size() != 1) return false;
    if(gender[0] == 'M' || gender[0] == 'F') return true;
    return false;
}

//verify the whether the input is correct.
bool registerSystem::verifyCode(string code){
    if(code.size() != 7 && code.size() != 8){
        return false;
    }
    for(int i = 0; i <code.size(); ++i){
        //first four digit should be upper case letters.
        if(i < 4){
            if(code[i] - 'A' <0 || code[i] - 'A' >25){
                return false;
            }
        }else if(i < code.size()){//left could be digits or upper case letters.
            if((code[i] - '0' <0 || code[i] - '0' >9 ) &&
               (code[i] - 'A' <0 || code[i] - 'A' >25)){
                return false;
            }
            
        }
    }
    return true;
}

//verify the whether the input is correct.
bool registerSystem::verifyCourseName(string name){
    if(name.size() == 0 || name.size() > 50) return false;
    return true;
}

//verify the whether the input is correct.
bool registerSystem::verifyCredit(string credit){
    if(credit.size() !=1) return false;
    if(credit[0] - '0' < 0 || credit[0] - '0' > 5) return false;
    return true;
}

//verify the whether the input is correct.
bool registerSystem::verifyExam(string score){
    //firstly, we need to know whether he has score.
    string noScore = "N/A";
    if(score == noScore) return true;
    //otherwise check the score range.
    bool has_only_digits = (score.find_first_not_of( "0123456789" ) == string::npos);
    if(!has_only_digits) return false;
    int s = stoi(score);
    if(s < 0 || s > 100){
        return false;
    }
    return true;
}


void registerSystem::saveFile(){
    ofstream outputFile;
    
    cout << "Enter the filename: ";
    string input;
    getline(cin, input);
    
    outputFile.open(input);
    
    //firstly, write the student information.
    hashStudent.putInOutput();
    Deque<Student>::Iterator itr_stu = hashStudent.outputIter();
    //output the number of total students.
    int numOfStudent = hashStudent.numOfOutput();
    outputFile << numOfStudent <<endl;
    while(itr_stu.get() != NULL){
        outputFile << (*itr_stu).getID() << endl;
        outputFile << (*itr_stu).getName() << endl;
        outputFile << (*itr_stu).getYear() << endl;
        outputFile << (*itr_stu).getGender() << endl;
        itr_stu++;
    }
    
    //secondly, write the course information.
    hashCourse.putInOutput();
    Deque<Course>::Iterator itr_cou = hashCourse.outputIter();
    //output the number of total courses.
    int numOfCourse = hashCourse.numOfOutput();
    outputFile << numOfCourse <<endl;
    while(itr_cou.get() != NULL){
        outputFile << (*itr_cou).getCode() << endl;
        outputFile << (*itr_cou).getName() << endl;
        outputFile << (*itr_cou).getCredit() << endl;
        itr_cou++;
    }
    
    //thirdly, write the courseSelection information.
    Deque<courseSelection>::Iterator itr_sel = regTable.selectionOutIter();
    //output the number of total selection information.
    int numOfSelection = regTable.numOfSelection();
    outputFile << numOfSelection <<endl;
    
    while(itr_sel.get() != NULL){
        //the courseSelection contains the information of student and course and the exam mark.
        //so we need to output the information of the student and the information of the course.
        outputFile << (*itr_sel).getID() <<endl;
        outputFile << (*itr_sel).getStudentName() <<endl;
        outputFile << (*itr_sel).getYear() <<endl;
        outputFile << (*itr_sel).getGender() <<endl;
        
        outputFile << (*itr_sel).getCourse() <<endl;
        outputFile << (*itr_sel).getCourseName() <<endl;
        outputFile << (*itr_sel).getCredit() <<endl;
        
        //finally, output the exam mark.
        outputFile << (*itr_sel).getExam() <<endl;
        itr_sel++;
    }
    
    outputFile.close();
    cout << "save successfully!" <<endl;
    enterToCon();
}


void registerSystem::loadError(){
    //print out the error messages.
    cout << "Error: Load File Error (File not exist / File Corrupted / Incorrect Format)" <<endl;
    enterToCon();
}

void registerSystem::loadFile(){
    //firstly, clear up the current tables.
    hashCourse.clear();
    hashStudent.clear();
    regTable.clear();
    
    ifstream inputFile;
    cout << "Enter the filename: ";
    string input;
    getline(cin, input);
    
    inputFile.open(input);
    
    if(!inputFile.is_open()){
        cout << "Error opening! File not exist!" <<endl;
        enterToCon();
        return;
    }
    
    //the reading process follows the outputing format.
    //and the format could be found in the saveFile function.
    
    int numOfStudent;
    //the first line of the file should be the number of the total student.
    string buffer;
    getline(inputFile, buffer);
    if(verifyInt(buffer)){
        numOfStudent = stoi(buffer);
    }else{
        inputFile.close();
        loadError();
        return;
    }
    for(int i = 0; i < numOfStudent; ++i){//i could indicate the line we are processing.
        string ID, name, year, gender;
        getline(inputFile, ID);
        getline(inputFile, name);
        getline(inputFile, year);
        getline(inputFile, gender);
        if(verifyID(ID) && verifyStudentName(name) && verifyYear(year) && verifyGender(gender)){
            Student s(ID, name, stoi(year), gender);
            hashStudent.insert(s, s.getKey(NUM_STU_BUCKETS));
        }else{
            inputFile.close();
            loadError();
            return;
        }
    }
    
    //the reading process follows the outputing format.
    //and the format could be found in the saveFile function.
    
    int numOfCourse;
    getline(inputFile, buffer);
    if(verifyInt(buffer)){
        numOfCourse = stoi(buffer);
    }else{
        inputFile.close();
        loadError();
        return;
    }
    for(int i = 0; i < numOfCourse; ++i){//i could indicate the line we are processing.
        string code, name, credit;
        getline(inputFile, code);
        getline(inputFile, name);
        getline(inputFile, credit);
        if(verifyCode(code) && verifyCourseName(name) && verifyCredit(credit)){
            Course c(code, name, stoi(credit));
            hashCourse.insert(c, c.getKey(NUM_COU_BUCKETS));
        }else{
            inputFile.close();
            loadError();
            return;
        }
    }
    
    //the reading process follows the outputing format.
    //and the format could be found in the saveFile function.
    
    int numOfSelection;
    getline(inputFile, buffer);
    if(verifyInt(buffer)){
        numOfSelection = stoi(buffer);
    }else{
        inputFile.close();
        loadError();
        return;
    }
    for(int i = 0; i < numOfSelection; ++i){//i could indicate the line we are processing.
        string ID, studentName, year, gender;
        getline(inputFile, ID);
        getline(inputFile, studentName);
        getline(inputFile, year);
        getline(inputFile, gender);
        
        string code, courseName, credit;
        getline(inputFile, code);
        getline(inputFile, courseName);
        getline(inputFile, credit);
        
        string exam;
        getline(inputFile, exam);
        
        //verify all the information that write in the file is correct.
        if(verifyID(ID) &&
           verifyStudentName(studentName) &&
           verifyYear(year) &&
           verifyGender(gender) &&
           verifyCode(code) &&
           verifyCourseName(courseName) &&
           verifyCredit(credit) &&
           verifyExam(exam)){
            Student s(ID, studentName, stoi(year), gender);
            Course c(code, courseName, stoi(credit));
            regTable.enroll(s.getID(), c.getCode(), s,c);
            regTable.modify(s.getID(), c.getCode(), exam);
            
        }else{
            inputFile.close();
            loadError();
            return;
        }
    }
    
    //the reading process follows the outputing format.
    //and the format could be found in the saveFile function.
    
    inputFile.close();
    cout << "load successfully!"<<endl;
    enterToCon();
}
