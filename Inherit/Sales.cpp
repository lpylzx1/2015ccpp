/*
 * Sales.cpp
 *
 *  Created on: 2015年4月28日
 *      Author: lc4t
 */

#include "Sales.h"
//#include <iostream>
Sales::Sales() {
    name = "";
    level = 0;
//  cout<<"Nothing init Sales"<<endl;
}



Sales::Sales(string name,int level)
{
    this->name = name;
    this->level = level;
}


int Sales::setSaleCount()
{
    return calcSalary() * 2;
}

Sales::~Sales() {
    // TODO Auto-generated destructor stub
}

