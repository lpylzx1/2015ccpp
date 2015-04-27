#include <vector>
using namespace std;
#ifndef CLASS_INTSTACK
#define CLASS_INTSTACK

class IntStack
{
    public:
        IntStack();
        void Push(int data);
        int Pop();
        int Length();
        void NewNumber(int size);
    private:
        vector<int> dataOfIntStack;
};

#endif