#include "IntStack.h"
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    IntStack stack;
    stack.Push(1);
    cout<<stack.Pop()<<endl;
    cout<<stack.Pop()<<endl;
    return 0;
}