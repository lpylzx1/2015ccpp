/*
 * SafeArray.cpp
 *
 *  Created on: 2015年4月14日
 *      Author: lc4t
 */
#include "SafeArray.h"
#include <iostream>
using namespace std;

SafeArray::SafeArray()
{

}

SafeArray::SafeArray(int size)
{
    array = new int[size];
    truesize = size;
}   

SafeArray::~SafeArray()
{
    delete [] array;
}

int SafeArray::Set(int index, int data)
{
    if (index < 0 || index >= truesize)
    {
        throw("OverFlow\n");
    }
    else
    {
        array[index] = data;
        return 1;
    }
}

int SafeArray::Get(int index)
{
    if (index >= truesize || index < 0)
    {
        return -1;
    }
    else
    {
        return array[index];
    }
}



