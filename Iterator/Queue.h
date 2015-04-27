/*
 * Queue.h
 *
 *  Created on: 2015年4月27日
 *      Author: lc4t
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "It.h"

class Queue {
public:
    Queue();
    void Append(int data);
    It* CreateIterator();
    virtual ~Queue();
    friend class It;
private:
    int* value;
    int  index;
};

#endif /* QUEUE_H_ */
