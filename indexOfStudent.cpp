//
//  index.cpp
//  2012h_test
//
//  Created by WANG Juntao on 27/11/2016.
//  Copyright © 2016 WANG Juntao. All rights reserved.
//

#include <stdio.h>
#include "indexOfStudent.h"
#include "Student.h"

//this function is mainly used to check the corretness.
ostream& IndexOfStudent::doPrint(ostream& os) const{
    os <<getID() << " " << pointer;
    return os;
}

