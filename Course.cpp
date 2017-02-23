//
//  Course.cpp
//  2012h_test
//
//  Created by WANG Juntao on 22/11/2016.
//  Copyright © 2016 WANG Juntao. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include "Course.h"

using namespace std;

Course::Course(){
    code = "";
    name = "";
    credit = 0;
}

int Course::getKey(int numOfBuckets) const{
    //we have assumed that the first Four digit of the course code is uppercase letter, and three number follow, then the last character is either "" or alphabet character.
    int sum = 0;
    for(int i = 0; i < 4; ++i){
        int value = (code[i] - 'A' + 1) + 10;
        //the corresponding value at position i.
        //in case overflow, each time multiplication we should mod it.
        //we construct a temp to calculate the mod value of base exponential term.
        int temp = value;
        for(int j = 0; j < i; ++j){
            temp = (temp * COURSE_BASE) % numOfBuckets;
        }
        sum += temp % numOfBuckets;
        
    }
    
    for(int i = 4; i < code.size(); ++i){
        int value = 0;
        if(code[i] - 'A' >= 0 && code[i] - 'A' <=25){//If it is a character.
            value = (code[i] - 'A' + 1) + 10;
        }else{//else it should be a integer.
            value = code[i] - '0';
        }
        //the corresponding value at position i.
        //in case overflow, each time multiplication we should mod it.
        int temp = value;
        for(int j = 0; j < i; ++j){
            temp = (temp * COURSE_BASE) % numOfBuckets;
        }
        sum += temp % numOfBuckets;
        
    }
    return (sum % numOfBuckets);
}

//overload the output stream in this way could enable the polymorphism.
ostream& Course::doPrint(ostream& os) const{
    os << "course code: " << code <<endl;
    os << "course name: " << name <<endl;
    os << "credit:      " << credit <<endl;
    return os;
}

ostream& operator<<(ostream& os, const Course& c){
    return c.doPrint(os);
}

//the comparision is only based on their code.
bool Course::operator<(const Course& c2){
    return code < c2.code;
}
//the comparision is only based on their code.
bool Course::operator>(const Course& c2){
    return code > c2.code;
}
//the comparision is only based on their code.
bool Course::operator<=(const Course& c2){
    return code <= c2.code;
}
//the comparision is only based on their code.
bool Course::operator>=(const Course& c2){
    return code >= c2.code;
}
//the comparision is only based on their code.
bool Course::operator==(const Course& c2){
    return code == c2.code;
}
