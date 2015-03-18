#include <stdio.h>

void Move(int num,int stackFrom,int stackBuffer,int stackTo,int &times);



int main(int argc, char const *argv[])
{
    int num = 0,times = 0;
    const int from = 1, buffer = 2, to = 3;
    scanf("%d",&num);
    Move(num,from,buffer,to,times);
    printf("time is = %d \n",times);
    return 0;
}




void Move(int num,int stackFrom,int stackBuffer,int stackTo,int &times)
{
    if (num == 1)
    {
        printf("stack %d->stack %d\n",stackFrom,stackTo);
        ++times;
    }
    else
    {
        Move(num-1,stackFrom,stackTo,stackBuffer,times);
        printf("stack %d->stack %d\n",stackFrom,stackTo);
        Move(num-1,stackBuffer,stackFrom,stackTo,++times);
    }
}