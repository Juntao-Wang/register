//
//  indexOfCourse.cpp
//  2012h_test
//
//  Created by WANG Juntao on 27/11/2016.
//  Copyright © 2016 WANG Juntao. All rights reserved.
//

#include "indexOfCourse.h"

//this function is mainly used to check the corretness.
ostream& IndexOfCourse::doPrint(ostream& os) const{
    os <<getCode() << " " << pointer;
    return os;
}

