/*
 * Sales.h
 *
 *  Created on: 2015年4月28日
 *      Author: lc4t
 */

#ifndef SALES_H_
#define SALES_H_
#include "Employee.h"

class Sales:public Employee
{
public:
    Sales();
    Sales(string name,int level);
    int setSaleCount();
    virtual ~Sales();
private:
    string name;
    int level;
};

#endif /* SALES_H_ */
