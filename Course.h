//
//  Course.h
//  2012h_test
//
//  Created by WANG Juntao on 22/11/2016.
//  Copyright © 2016 WANG Juntao. All rights reserved.
//

#ifndef Course_h
#define Course_h
#include <iostream>
#include <string>

#define COURSE_BASE 36
#define CODE_LEN 8
using namespace std;

class Course{
private:
    string code;
    string name;
    int credit;
    
public:
    Course();
    Course(string c, string n = "", int cr = -1): code(c), name(n), credit(cr) {}
    Course(const Course& c): code(c.getCode()), name(c.getName()), credit(c.getCredit()) {}
    //get functions.
    string getCode() const {return code;}
    string getName() const {return name;}
    int getCredit() const {return credit;}
    
    //int: return the hashed key value, based on the numOfBuckets.
    int getKey(int numOfBuckets) const;
    
    //set functions.
    void setCode(string c) {code = c;}
    void setName(string n) {name = n;}
    void setCredit(int i) {credit = i;}
    
    //operators overload.
    virtual ostream& doPrint(ostream& os) const;
    friend ostream& operator<<(ostream& os, const Course& c);
    virtual bool operator<(const Course& c2);
    virtual bool operator>(const Course& c2);
    virtual bool operator<=(const Course& c2);
    virtual bool operator>=(const Course& c2);
    virtual bool operator==(const Course& c2);
    
};
#endif /* Course_h */
