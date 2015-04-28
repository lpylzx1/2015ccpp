#include <iostream>
#include "Employee.h"
#include "Sales.h"

int main(int argc, char const *argv[])
{
    Employee e("pig",0);
    e.setLevel(5);
    cout<<e.getName()<<" has "<<e.calcSalary()<<endl;
    cout<<e.getName()<<" is level "<<e.getLevel()<<endl;
    Sales s;
    s.setName("dog");
    s.setLevel(10);
    cout<<s.getName()<<" has "<<s.setSaleCount()<<endl;

}
