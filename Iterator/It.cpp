/*
 * It.cpp
 *
 *  Created on: 2015年4月24日
 *      Author: lc4t
 */

#include "It.h"
It::It()
{
    index = 0;
}



It::~It()
{
    // TODO Auto-generated destructor stub
}

int* It::next()
{
    if (index < trueSize)
    {
        return (value+(index++));
    }
    else
    {
        return (int*)0;
    }

}
