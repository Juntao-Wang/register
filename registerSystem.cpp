//
//  register.cpp
//  2012h_test
//
//  Created by WANG Juntao on 27/11/2016.
//  Copyright © 2016 WANG Juntao. All rights reserved.
//

#include "registerSystem.h"


//indicates enter to continue.
void registerSystem::enterToCon(){
    cout <<endl;
    cout << "Hit ENTER to continue..."<<endl;
    string input;
    getline(cin, input);
    mainMenu();
}

//check the input. and if it is incorrect ask for reentering.
int registerSystem::numInput(int size){
    string input;
    int integerIn = 0;
    printf("Enter your choice (1-%d): ", size);
    do{
        getline(cin, input);
        if(input.size() != 1){
            reEnter();
            continue;
        }
        integerIn = input[0] - '0';
        if(integerIn <1 || integerIn >size){
            reEnter();
        }
        
    }while(integerIn <1 || integerIn >size);
    return integerIn;
}

//check the input. and if it is incorrect ask for reentering.
string registerSystem::IDInput(){
    string input;
    bool invalid = true;
    cout << "Enter the student ID: ";
    do{
        getline(cin, input);
        if(input.size() != 8){
            reEnter();
            continue;
        }
        for(int i = 0; i < 8; ++i){
            if(input[i] - '0' <0 || input[i] - '0' >9){
                reEnter();
                break;
            }
            if(i == 7) invalid = false;
        }
        
        
    }while(invalid);
    return input;
}

//check the input. and if it is incorrect ask for reentering.
string registerSystem::stuInput(){
    string input;
    cout << "Enter the student name: ";
    do{
        getline(cin, input);
        if(input.size() > 32 || input.size() == 0){
            reEnter();
        }
        
    }while(input.size() > 32 || input.size() == 0);
    return input;
}

//check the input. and if it is incorrect ask for reentering.
string registerSystem::modStuInput(string currName){
    string input;
    printf("Enter the student name [%s]: ", currName.c_str());
    do{
        getline(cin, input);
        if(input.size() > 32 || input.size() == 0){
            reEnter();
        }
        
    }while(input.size() > 32 || input.size() == 0);
    return input;
}

//check the input. and if it is incorrect ask for reentering.
int registerSystem::yearInput(){
    cout << "Enter the student year [1-3]: ";
    string input;
    int integerIn = 0;
    do{
        getline(cin, input);
        if(input.size() != 1){
            reEnter();
            continue;
        }
        integerIn = input[0] - '0';
        if(integerIn < 1 || integerIn > 3){
            reEnter();
        }
    }while(integerIn <1 || integerIn >3);
    return integerIn;
}

int registerSystem::modYearInput(int currYear){
    printf("Enter the student year [%d]: ", currYear);
    string input;
    int integerIn = 0;
    do{
        getline(cin, input);
        if(input.size() != 1){
            reEnter();
            continue;
        }
        integerIn = input[0] - '0';
        if(integerIn < 1 || integerIn > 3){
            reEnter();
        }
    }while(integerIn <1 || integerIn >3);
    return integerIn;
}

//check the input. and if it is incorrect ask for reentering.
string registerSystem::genderInput(){
    string input;
    bool invalid = true;
    cout <<"Enter the student gender [M,F]: ";
    
    do{
        getline(cin, input);
        if(input.size() != 1){
            reEnter();
            continue;
        }
        
        if(input[0] == 'M' || input[0] == 'F'){
            invalid =false;
        }else{
            reEnter();
        }
        
    }while(invalid);
    return input;
}

//check the input. and if it is incorrect ask for reentering.
string registerSystem::modGenderInput(string currGender){
    string input;
    bool invalid = true;
    printf("Enter the student gender [%s]: ",currGender.c_str());
    
    do{
        getline(cin, input);
        if(input.size() != 1){
            reEnter();
            continue;
        }
        
        if(input[0] == 'M' || input[0] == 'F'){
            invalid =false;
        }else{
            reEnter();
        }
        
    }while(invalid);
    return input;
}

//check the input. and if it is incorrect ask for reentering.
string registerSystem::CodeInput(){
    string input;
    bool invalid = true;
    cout <<"Enter the course code: ";
    do{
        getline(cin, input);
        if(input.size() != 7 && input.size() != 8){
            reEnter();
            continue;
        }
        for(int i = 0; i <input.size(); ++i){
            //first four digit should be upper case letters.
            if(i < 4){
                if(input[i] - 'A' <0 || input[i] - 'A' >25){
                    reEnter();
                    break;
                }
            }else if(i < input.size()){
                if((input[i] - '0' <0 || input[i] - '0' >9 ) &&
                   (input[i] - 'A' <0 || input[i] - 'A' >25)){
                    reEnter();
                    break;
                }
            }
            
            if( i == input.size() -1) invalid = false;
        }
        
    }while(invalid);
    return input;
    
}

//check the input. and if it is incorrect ask for reentering.
string registerSystem::courseInput(){
    string input;
    cout <<"Enter the course name: ";
    do{
        getline(cin, input);
        if(input.size() > 50 || input.size() == 0){
            reEnter();
        }
        
    }while(input.size() > 50 || input.size() == 0);
    return input;
}

//check the input. and if it is incorrect ask for reentering.
string registerSystem::modCourseInput(string currName){
    string input;
    printf("Enter the course name[%s]: ", currName.c_str());
    do{
        getline(cin, input);
        if(input.size() > 50 || input.size() == 0){
            reEnter();
        }
        
    }while(input.size() > 50 || input.size() == 0 );
    return input;
}


//check the input. and if it is incorrect ask for reentering.
int registerSystem::creditInput(){
    string input;
    int integerIn = -1;
    cout << "Enter the course credit [0-5]: ";
    
    do{
        getline(cin, input);
        if(input.size() != 1){
            reEnter();
            continue;
        }
        integerIn = input[0] - '0';
        if(integerIn < 0 || integerIn > 5){
            reEnter();
        }
        
    }while(integerIn <0 || integerIn >5);
    return integerIn;
}

//check the input. and if it is incorrect ask for reentering.
int registerSystem::modCreditInput(int currCredit){
    string input;
    int integerIn = -1;
    printf("Enter the course credit [%d]: ", currCredit);
    
    do{
        getline(cin, input);
        if(input.size() != 1){
            reEnter();
            continue;
        }
        integerIn = input[0] - '0';
        if(integerIn<0 || integerIn > 5){
            reEnter();
        }
        
    }while(integerIn <0 || integerIn >5);
    return integerIn;
}

void registerSystem::mainMenu(){
    clearScreen();
    cout << "HKUST Course Registration System" <<endl;
    cout << "--------------------------------" <<endl;
    cout << endl;
    cout << "1. Student Management" << endl;
    cout << "2. Course Management" <<endl;
    cout << "3. Course Registration" <<endl;
    cout << "4. Report Management" <<endl;
    cout << "5. File Management" <<endl;
    cout << "6. Exit" <<endl;
    cout <<endl;
    
    int input = numInput(6);
    
    switch(input){
        case 1:
            studentMenu();
            break;
        case 2:
            courseMenu();
            break;
        case 3:
            courseRegMenu();
            break;
        case 4:
            reportMenu();
            break;
        case 5:
            fileMenu();
            break;
        case 6:
            exit(0);
            break;
        default:
            break;
    }
    
    
}

bool registerSystem::insertStudent(){
    string ID = IDInput();
    Student temp = Student(ID);
    if(hashStudent.findElem(temp, temp.getKey(NUM_STU_BUCKETS))){
        cout << "Student already exist"<<endl;
        return false;
    }else{//if no such student we can create his information.
        string name = stuInput();
        int year = yearInput();
        string gender = genderInput();
        Student newStudent = Student(ID, name, year, gender);
        hashStudent.insert(newStudent, newStudent.getKey(NUM_STU_BUCKETS));
        cout << "Creation of student record successful" <<endl;
        return true;
    }
}

void registerSystem::modifyStudent(){
    string ID = IDInput();
    Student temp = Student(ID);
    node<Student>* addr = hashStudent.findElem(temp, temp.getKey(NUM_STU_BUCKETS));
    if(addr){//if we can find him.
        (addr->elem).setName(modStuInput((addr->elem).getName()));
        (addr->elem).setYear(modYearInput((addr->elem).getYear()));
        (addr->elem).setGender(modGenderInput((addr->elem).getGender()));
        cout << "Modification of student record successful" <<endl;
    }else{
        cout <<"Student not exist" <<endl;
    }
}

void registerSystem::queryStudent(){
    string ID = IDInput();
    Student temp = Student(ID);
    node<Student>* addr = hashStudent.findElem(temp, temp.getKey(NUM_STU_BUCKETS));
    if(addr){
        cout << addr->elem <<endl;
    }else{
        cout <<"Student not exist" <<endl;
    }
}

void registerSystem::deleteStudent(){
    string ID = IDInput();
    Student temp = Student(ID);
    node<Student>* addr = hashStudent.findElem(temp, temp.getKey(NUM_STU_BUCKETS));
    if(addr){
        //if the student takes some courses, delete the records.
        regTable.removeCourseOfStu(ID);
        //remove it from the records.
        hashStudent.removeElem(temp, temp.getKey(NUM_STU_BUCKETS));
        cout << "Deletion of student record successful" <<endl;
    }else{
        cout <<"Student not exist" <<endl;
    }
}

void registerSystem::studentMenu(){
    clearScreen();
    cout << "HKUST Course Registration System  (Student Menu)" <<endl;
    cout << "------------------------------------------------" <<endl;
    cout << endl;
    cout << "1. Insert Student Record" << endl;
    cout << "2. Modify Student Record" <<endl;
    cout << "3. Delete Student Record" <<endl;
    cout << "4. Query Student Record" <<endl;
    cout << "5. Go back to main menu" <<endl;
    cout << endl;
    
    int input = numInput(5);
    switch(input){
        case 1:
            insertStudent();
            break;
        case 2:
            modifyStudent();
            break;
        case 3:
            deleteStudent();
            break;
        case 4:
            queryStudent();
            break;
        case 5:
            mainMenu();
            break;
        default:
            break;
    }
    enterToCon();
    
}

void registerSystem::courseMenu(){
    clearScreen();
    cout << "HKUST Course Registration System  (Course Menu)" <<endl;
    cout << "-----------------------------------------------" <<endl;
    cout << endl;
    cout << "1. Insert Course Record" << endl;
    cout << "2. Modify Course Record" <<endl;
    cout << "3. Delete Course Record" <<endl;
    cout << "4. Query Course Record" <<endl;
    cout << "5. Go back to main menu" <<endl;
    cout <<endl;
    
    int input = numInput(5);
    switch(input){
        case 1:
            insertCourse();
            break;
        case 2:
            modifyCourse();
            break;
        case 3:
            deleteCourse();
            break;
        case 4:
            queryCourse();
            break;
        case 5:
            mainMenu();
            break;
        default:
            break;
    }
    enterToCon();
    
}

bool registerSystem::insertCourse(){
    string code = CodeInput();
    Course temp = Course(code);
    if(hashCourse.findElem(temp, temp.getKey(NUM_COU_BUCKETS))){
        cout << "Course already exist"<<endl;
        return false;
    }else{
        string name = courseInput();
        int credit = creditInput();
        Course newCourse = Course(code, name, credit);
        hashCourse.insert(newCourse, newCourse.getKey(NUM_COU_BUCKETS));
        cout << "Creation of course record successful" <<endl;
        return true;
    }
}

void registerSystem::modifyCourse(){
    string code = CodeInput();
    Course temp = Course(code);
    node<Course>* addr = hashCourse.findElem(temp, temp.getKey(NUM_COU_BUCKETS));
    if(addr){//if we can find the course.
        (addr->elem).setName(modCourseInput((addr->elem).getName()));
        (addr->elem).setCredit(modCreditInput((addr->elem).getCredit()));
        cout << "Modification of course record successful" <<endl;
    }else{
        cout <<"Course not exist" <<endl;
    }
}

void registerSystem::queryCourse(){
    string code = CodeInput();
    Course temp = Course(code);
    node<Course>* addr = hashCourse.findElem(temp, temp.getKey(NUM_COU_BUCKETS));
    if(addr){
        cout << addr->elem <<endl;
    }else{
        cout <<"Course not exist" <<endl;
    }
}

void registerSystem::deleteCourse(){
    string code = CodeInput();
    Course temp = Course(code);
    node<Course>* addr = hashCourse.findElem(temp, temp.getKey(NUM_COU_BUCKETS));
    if(addr){
        //if some students have registered this course, delete them.
        regTable.removeStuOfCourse(code);
        //remove it from the records.
        hashCourse.removeElem(temp, temp.getKey(NUM_COU_BUCKETS));
        cout << "Deletion of course record successful" <<endl;
    }else{
        cout <<"Course not exist" <<endl;
    }
}

void registerSystem::courseRegMenu(){
    clearScreen();
    cout << "HKUST Course Registration System  (Registration Menu)" <<endl;
    cout << "-----------------------------------------------------" <<endl;
    cout << endl;
    cout << "1. Add Course" << endl;
    cout << "2. Drop Course" <<endl;
    cout << "3. Modify Exam Mark" <<endl;
    cout << "4. Query Registration" <<endl;
    cout << "5. Go back to main menu" <<endl;
    cout <<endl;
    
    int input = numInput(5);
    switch(input){
        case 1:
            addCourse();
            break;
        case 2:
            dropCourse();
            break;
        case 3:
            modifyExam();
            break;
        case 4:
            queryReg();
            break;
        case 5:
            mainMenu();
            break;
        default:
            break;
    }
    enterToCon();
    
}

string registerSystem::modExamInput(string currMark){
    string input;
    bool invalid  =true;
    printf("Enter the exam mark[%s]:", currMark.c_str());
    do{
        getline(cin, input);
        if(input.size() == 0){//cannot input a NULL string.
            reEnter();
            continue;
        }
        //this could be used to check whether the input is pure number.
        bool has_only_digits = (input.find_first_not_of( "0123456789" ) == string::npos);
        if(has_only_digits){//if the input is pure number.
            int temp = stoi(input);//we can convert it into integer.
            if(temp>=0 && temp <=100){//the score should be between 0 and 100.
                invalid = false;
            }else{//if the input is invalid.
                reEnter();
            }
        }else{//if the input is not a pure number.
            reEnter();
        }
    }while(invalid);
    return input;
}

bool registerSystem::addCourse(){
    string ID= IDInput();
    Student student(ID);
    node<Student>* addrOfStudent = hashStudent.findElem(student, student.getKey(NUM_STU_BUCKETS));
    if(!addrOfStudent){
        cout << "student not exist" <<endl;
        return false;
    }
    string code = CodeInput();
    Course course(code);
    node<Course>* addrOfCourse = hashCourse.findElem(course, course.getKey(NUM_COU_BUCKETS));
    if(!hashCourse.findElem(course, course.getKey(NUM_COU_BUCKETS))){
        cout << "course not exist" <<endl;
        return false;
    }
    
    if(regTable.enroll(ID, code, addrOfStudent->elem, addrOfCourse->elem)){
        cout << "Add course successful" <<endl;
        return true;
    }else{
        cout << "The student already registered the course" <<endl;
        return false;
    }
    
}

void registerSystem::dropCourse(){
    string ID= IDInput();
    Student student(ID);
    if(!hashStudent.findElem(student, student.getKey(NUM_STU_BUCKETS))){
        cout << "student not exist" <<endl;
        return;
    }
    string code = CodeInput();
    Course course(code);
    if(!hashCourse.findElem(course, course.getKey(NUM_COU_BUCKETS))){
        cout << "course not exist" <<endl;
        return;
    }
    
    if(regTable.drop(ID, code)){
        cout << "Drop course successful" <<endl;
    }else{
        cout << "The registration record not exist" <<endl;
    }
    
}

void registerSystem::modifyExam(){
    string ID= IDInput();
    Student student(ID);
    if(!hashStudent.findElem(student, student.getKey(NUM_STU_BUCKETS))){
        cout << "student not exist" <<endl;
        return;
    }
    string code = CodeInput();
    Course course(code);
    if(!hashCourse.findElem(course, course.getKey(NUM_COU_BUCKETS))){
        cout << "course not exist" <<endl;
        return;
    }
    
    node<courseSelection>* temp = regTable.findByStudent(ID, code);
    if(temp){
        string input = modExamInput((temp->elem).getExam());
        (temp->elem).setExam(input);
    }else{
        cout << "student did not take this course" <<endl;
        return;
    }
    
    cout << "Modification of exam record successful" <<endl;
    
}

void registerSystem::queryReg(){
    string ID= IDInput();
    Student student(ID);
    if(!hashStudent.findElem(student, student.getKey(NUM_STU_BUCKETS))){
        cout << "student not exist" <<endl;
        return;
    }
    string code = CodeInput();
    Course course(code);
    if(!hashCourse.findElem(course, course.getKey(NUM_COU_BUCKETS))){
        cout << "course not exist" <<endl;
        return;
    }
    
    node<courseSelection>* temp = regTable.findByStudent(ID, code);
    if(temp){
        cout <<endl;
        cout << (temp->elem) <<endl;
    }else{
        cout << "The registration record not exist" << endl;
    }
    
}






