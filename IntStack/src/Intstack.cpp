#include <IntStack.h>
IntStack::IntStack()
{

}

void IntStack::Push(int data)
{
    NewNumber(1);
    *sp++=data;
}

void IntStack::NewNumber(int size)
{
    dataOfIntStack = new int(size);
}


int IntStack::Pop()
{
    return *(--sp);
    delete (dataOfIntStack[length()]);
}

int IntStack::Length()
{
    return ((sp - dataOfIntStack) / sizeof(int));
}

