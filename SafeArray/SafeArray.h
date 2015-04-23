/*
 * SafeArray.h
 *
 *  Created on: 2015年4月20日
 *      Author: lc4t
 */

#ifndef SAFEARRAY_H_
#define SAFEARRAY_H_
#include <iostream>

class SafeArray
{
    public:
    int* array;

        SafeArray();
        SafeArray (int size);
        int Set(int index, int data);
        int Get(int index);
        ~SafeArray();
        int & operator [] (int offset);
        friend std::ostream & operator<<(std::ostream & o, const SafeArray &sa);

    private:
        int truesize;

};


#endif /* SAFEARRAY_H_ */
