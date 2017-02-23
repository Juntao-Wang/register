//
//  Student.cpp
//  2012h_test
//
//  Created by WANG Juntao on 22/11/2016.
//  Copyright © 2016 WANG Juntao. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <math.h>
#include "Student.h"

using namespace std;

Student::Student(){
    ID = "";
    name = "";
    year = 0;
    gender = "";
}

Student::~Student(){
    
}

int Student::getDigitAt (int index) const {
    int intID = stoi(ID);
    int pos = ID_LEN - 1 - index;
    int numSeg = (intID/(pow(BASE,pos)));
    if(pos == 0) return intID % 10;
    return numSeg % 10;
}

int Student::getKey(int numOfBuckets) const{
    int sum = 0;
    for(int i = 0; i < ID_LEN; ++i){//for each position, we calculate its corresponding value.
        //in case overflow, each time multiplication we should mod it.
        //we construct a temp to calculate the mod value of base exponential term.
        //temp firstly is the corresponding value at position i.
        int temp = getDigitAt(i);
        for(int j = 0; j < i; ++j){
            temp = (temp * BASE) % numOfBuckets;
        }
        sum += temp % numOfBuckets;
    }
    return (sum % numOfBuckets);
}


//the comparision is only based on their ID.
bool Student::operator==(const Student& s2){
    return stoi(ID) == stoi(s2.ID);
}
//the comparision is only based on their ID.
bool Student::operator<(const Student& s2){
    return stoi(ID) < stoi(s2.ID);
}
//the comparision is only based on their ID.
bool Student::operator>(const Student& s2){
    return stoi(ID) > stoi(s2.ID);
}
//the comparision is only based on their ID.
bool Student::operator<=(const Student& s2){
    return stoi(ID) <= stoi(s2.ID);
}
//the comparision is only based on their ID.
bool Student::operator>=(const Student& s2){
    return stoi(ID) >= stoi(s2.ID);
}

//overload the output stream in this way could enable the polymorphism.
ostream& Student::doPrint(ostream& os) const{
    os << "studentID: " << ID <<endl;
    os << "name:      " << name <<endl;
    os << "year:      " << year <<endl;
    if(gender == "M"){
        os << "gender:    " << "Male" <<endl;
    }else if(gender == "F"){
        os << "gender:    " << "Female" <<endl;
    }
    return os;
}

ostream& operator<<(ostream& os, const Student& s){
    return s.doPrint(os);
}

