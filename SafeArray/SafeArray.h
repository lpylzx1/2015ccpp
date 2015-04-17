/*
 * SafeArray.h
 *
 *  Created on: 2015年4月14日
 *      Author: lc4t
 */

#ifndef SAFEARRAY_H_
#define SAFEARRAY_H_

class SafeArray
{
    public:
        SafeArray();
        SafeArray (int size);
        int Set(int index, int data);
        int Get(int index);
    private:
        int *array;
        int truesize;
        ~SafeArray();
};


#endif /* SAFEARRAY_H_ */
