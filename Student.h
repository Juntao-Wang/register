//
//  Student.h
//  2012h_test
//
//  Created by WANG Juntao on 22/11/2016.
//  Copyright © 2016 WANG Juntao. All rights reserved.
//

#ifndef Student_h
#define Student_h

#include <string>
#include <iostream>

using namespace std;

#define BASE 10
#define ID_LEN 8

class Student{
private:
    string ID;
    string name;
    int year;
    string gender;
public:
    
    //consctructors.
    Student();
    ~Student();
    Student(string i, string n = "", int y = 0, string g = ""): ID(i), name(n), year(y), gender(g) {}
    Student(const Student& s):ID(s.getID()), name(s.getName()), year(s.getYear()), gender(s.getGender()) {}
    
    //int: get the key value of the student, and the hashtable's number of buckets is numOfBuckets.
    int getKey(int numOfBuckets) const;
    //string: return the ID of the student.
    string getID() const {return ID;}
    //string: return the name of the student.
    string getName() const {return name;}
    //int: return the year of the student.
    int getYear() const {return year;}
    //string: return the gender of the student.
    string getGender() const {return gender;}
    
    //this function is used to return the integer value at the string position i.
    int getDigitAt(int i) const;
    
    //set functions provided to changed a student's informaiton.
    void setName(string s) {name = s;}
    void setID(string i) {ID = i;}
    void setYear(int y) {year = y;}
    void setGender(string g) {gender = g;}
    
    
    //operator overload.
    virtual ostream& doPrint(ostream& os) const;
    friend ostream& operator<<(ostream& os, const Student& s);
    //the comparision is only based on the student ID.
    virtual bool operator==(const Student& s2);
    virtual bool operator<(const Student& s2);
    virtual bool operator>(const Student& s2);
    virtual bool operator<=(const Student& s2);
    virtual bool operator>=(const Student& s2);
    
    
    
};
#endif /* Student_h */
