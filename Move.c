#include <stdio.h>
#include <algorithm>
int time = 0;

void Move(int num,int stackOne,int stackTwo,int stackThree)
{
    if (num == 1)
    {
        printf("stack %d->stack %d\n",stackOne,stackThree);
        time++;
    }
    else
    {
        Move(num-1,stackOne,stackThree,stackTwo);
        printf("stack %d->stack %d\n",stackOne,stackThree);
        time++;
        Move(num-1,stackTwo,stackOne,stackThree);
    }

}



int main(int argc, char const *argv[])
{
    int num = 0;
    const int one = 1, two = 2, three = 3;
    scanf("%d",&num);
    Move(num,one,two,three);
    printf("time is = %d \n",time);
    return 0;
}
