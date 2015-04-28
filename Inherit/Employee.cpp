/*
 * Employee.cpp
 *
 *  Created on: 2015年4月28日
 *      Author: lc4t
 */

#include "Employee.h"
//#include <iostream>
Employee::Employee() {
    name = "";
    level = 0;
//  cout<<"Nothing init Employee"<<endl;
}


Employee::Employee(string name,int level)
{
    this->name = name;
    this->level = level;
}

void Employee::setLevel(int level)
{
    this->level = level;
}

void Employee::setName(string name)
{
    this->name = name;
}

int Employee::getLevel()
{
    return level;
}

string Employee::getName()
{
    return name;
}

int Employee::calcSalary()
{
    return getLevel() * 3000;
}

Employee::~Employee() {
    // TODO Auto-generated destructor stub
}

