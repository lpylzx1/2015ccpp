/*
 * SafeArray.cpp
 *
 *  Created on: 2015年4月20日
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
        std::cout << "OverFlow" << std::endl;
        return -1;
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

int& SafeArray::operator [] (int offset)
{
    if (offset < truesize)
    {
        return array[offset];
    }
    else
    {
        std::cout << "OverFlow" << std::endl;
    }

}

std::ostream & operator<<(std::ostream & o, const SafeArray &sa)
{
    for (int i = 0; i < sa.truesize; i+=5)
    {
        for (int j = 0;j <= 4; j++)
        {
            o<<sa.array[i + j]<<"\t";
        }
        o<<"\n";
    }
    return o;
}
