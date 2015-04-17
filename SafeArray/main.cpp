#include <iostream>
#include "SafeArray.h"
using namespace std;

int main(int argc, char const *argv[])
{
    SafeArray a(100);
    a.Set(0,100);
    a.Set(20,2000);
    a.Set(100,300);
    cout<<a.Get(0)<<endl;
    cout<<a.Get(1000)<<endl;
    return 0;
}
