/*
 * Queue.cpp
 *
 *  Created on: 2015年4月24日
 *      Author: lc4t
 */

#include "Queue.h"
#include "It.h"


Queue::Queue() {
    // TODO Auto-generated constructor stub
    value = new int[100];
    index = 0;
}

Queue::~Queue() {
    // TODO Auto-generated destructor stub
}




void Queue::Append(int data)
{
    value[index++] = data;
}

It* Queue::CreateIterator()
{

    It* it = new It;
    it->value = this->value;
    it->trueSize = index;
    return it;
}
