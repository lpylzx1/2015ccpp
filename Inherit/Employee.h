/*
 * Employee.h
 *
 *  Created on: 2015年4月28日
 *      Author: lc4t
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <string>
using namespace std;
class Employee {
public:
    Employee();
    Employee(string name,int level);
    void setLevel(int level);
    int getLevel();

    void setName(string name);
    string getName();

    int calcSalary();

    virtual ~Employee();
private:
    string name;
    int level;
};

#endif /* EMPLOYEE_H_ */
