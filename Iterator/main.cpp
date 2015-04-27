#include <iostream>
#include <cassert>
#include "It.h"
#include "Queue.h"
using namespace std;

int main(int argc, char const *argv[])
{
    Queue q;
    q.Append(100);
    q.Append(200);

    It* it1 = q.CreateIterator();
    cout << *(it1 -> next()) << *(it1 -> next()) << endl;
    assert(!it1 -> next());

    It* it2 = q.CreateIterator();
    cout << *(it2 -> next()) << endl;
    assert(*(it2 -> next()) == 200);

}
