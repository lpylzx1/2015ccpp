/*
 * It.h
 *
 *  Created on: 2015年4月27日
 *      Author: lc4t
 */

#ifndef IT_H_
#define IT_H_



class It
{
    public:
        It();
        virtual ~It();
        int* next();
        friend class Queue;
    private:
        int* value;
        int  index;
        int  trueSize;
};
#endif /* IT_H_ */
