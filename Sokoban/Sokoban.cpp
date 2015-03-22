#include <stdio.h>
#include <stdlib.h>
#define N 10
#define USER_WIN 0x01
#define USER_STEP_TO_WALL 0x02
#define USER_STEP_TO_BOUNDARY 0x03
#define USER_CAN_NOT_MOVE 0x04
#define BOX_CAN_MOVE 0x10
#define BOX_CAN_NOT_MOVE 0x11
#define MOVE_SUCCESS 0x100
#define MOVE_FAIL 0x200
#define MOVE_WITHOUT_BOX 0x300
#define MOVE_TO_BOX 0x400

int BoxMoveJudge(char (*sokobanMap)[N + 2], int X, int Y);
int UserMove(char (*sokobanMap)[N + 2], int &X, int &Y, char userInput);
int UserMoveJudge(char (*sokobanMap)[N + 2], int X, int Y);
void PrintMap(char sokobanMap[N + 2][N + 2], int sizeOfStringX, int sizeOfStringY);

char sokobanMap[N + 2][N + 2] = {
        {'-','-','-','-','-','-','-','-','-','-','-','-'},
        {'-','*','*','*','-','*','*','*','*','*','*','-'},
        {'-','*',' ',' ',' ',' ',' ','*',' ','M','F','-'},
        {'-','*',' ',' ',' ','S',' ',' ',' ','*','*','-'},
        {'-','*',' ',' ',' ',' ',' ',' ',' ','*','*','-'},
        {'-','*',' ',' ',' ',' ',' ',' ',' ','*','*','-'},
        {'-','*',' ',' ',' ',' ',' ',' ',' ','*','*','-'},
        {'-','*',' ',' ',' ',' ',' ',' ',' ','*','*','-'},
        {'-','*',' ',' ',' ',' ',' ',' ',' ','*','*','-'},
        {'-','*','*','*','*','*','*','*','*','*','*','-'},
        {'-','-','-','-','-','-','-','-','-','-','-','-'}
};



int main(int argc, char const *argv[])
{
    PrintMap(sokobanMap, 12,12);
    int X = 3, Y = 5;
    char userInput;
    for (int userStay;;)
    {
        scanf("%c",&userInput);
        getchar();
        userStay = UserMove(sokobanMap, X, Y, userInput);
        {
            if (userStay == MOVE_SUCCESS)
            {
                system("cls");
                PrintMap(sokobanMap, 12,12);
                printf("go on\n");
                continue;
            }
            if (userStay == MOVE_FAIL)
            {
                printf("wrong input\n");
                continue;
            }
            if (userStay == USER_WIN)
            {
                printf("you win\n");
                break;
            }
            if (userStay == USER_STEP_TO_BOUNDARY)
            {
                printf("where are you going?\n");
                continue;
            }
            if (userStay == USER_STEP_TO_WALL)
            {
                printf("are you hurt?\n");
                continue;
            }
         }
     }
     return 0;
 }


void PrintMap(char sokobanMap[N + 2][N + 2], int sizeOfStringX, int sizeOfStringY)
{

    for (int i = 0;i < sizeOfStringX;i++)
    {
        for (int j = 0;j < sizeOfStringY;j++)
        {
            printf("%c",sokobanMap[i][j]);
        }
        printf("\n");
    }
}


int UserMove(char (*sokobanMap)[N + 2], int &X, int &Y, char userInput)
{
    int userMoveResult, boxMoveResult;
    int moveX = 0, moveY = 0;
    switch(userInput)
    {
        case 'w':
        case 'W':
        {
            moveX = -1;
            break;
        }
        case 's':
        case 'S':
        {
            moveX = 1;
            break;
        }
        case 'a':
        case 'A':
        {
            moveY = -1;
            break;
        }
        case 'd':
        case 'D':
        {
            moveY = 1;
            break;
        }
    }
    userMoveResult = UserMoveJudge(sokobanMap, X + moveX, Y + moveY);
    if (userMoveResult == USER_STEP_TO_WALL)
    {
        return USER_STEP_TO_WALL;
    }
    if (userMoveResult == USER_STEP_TO_BOUNDARY)
    {
        return USER_STEP_TO_BOUNDARY;
    }
    if (userMoveResult == MOVE_WITHOUT_BOX)
    {
        sokobanMap[X][Y] = ' ';
        X = X + moveX;
        Y = Y + moveY;
        sokobanMap[X][Y] = 'S';
        return MOVE_SUCCESS;
    }
    if (userMoveResult == USER_CAN_NOT_MOVE)
    {
        return MOVE_FAIL;
    }
    boxMoveResult = BoxMoveJudge(sokobanMap, X + moveX + moveX,Y + moveY + moveY);
    if (userMoveResult = MOVE_TO_BOX)
    {
        if (boxMoveResult == BOX_CAN_MOVE)
        {
            sokobanMap[X][Y] = ' ';
            X = X + moveX;
            Y = Y + moveY;
            sokobanMap[X][Y] = 'S';
            sokobanMap[X - 1][Y] = 'M';
            return MOVE_SUCCESS;
        }
        if (boxMoveResult == BOX_CAN_NOT_MOVE)
        {
            return MOVE_FAIL;
        }
        if (boxMoveResult == USER_WIN)
        {
            return USER_WIN;
        }
    }
}

int UserMoveJudge(char (*sokobanMap)[N + 2], int X, int Y)
{
    switch(sokobanMap[X][Y])
    {
        case 'M':
        {
            return MOVE_TO_BOX;
        }
        case ' ':
        {
            return MOVE_WITHOUT_BOX;
        }
        case '-':
        {
            return USER_STEP_TO_BOUNDARY;
        }
        case '*':
        {
            return USER_STEP_TO_WALL;
        }
    }
    return MOVE_FAIL;
}


int BoxMoveJudge(char (*sokobanMap)[N + 2], int X, int Y)
{
    switch(sokobanMap[X][Y])
    {
        case '*':
        case '-':
        {
            return BOX_CAN_NOT_MOVE;
        }
        case ' ':
        {
            return BOX_CAN_MOVE;
        }
        case 'F':
        {
            return USER_WIN;
        }
    }
}