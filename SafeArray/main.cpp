#include <iostream>
#include "SafeArray.h"
using namespace std;

int main()
{
    SafeArray a (100);
    a[99] = 100;
    std::cout << a;
    return 0;
}
