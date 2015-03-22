#include <stdio.h>
#include <stdlib.h>

#define N 10
#define OK 1
#define WRONG_INPUT 0
#define YOU_WIN 8
#define STEP_INTO_WALL -1
#define WIN_THE_GAME 1
#define OK_STEP 0
#define STEP_TO_WALL 2
#define STEP_TO_BOUNDARY 2


int PrintMap(char mazeMap[N + 2][N + 2]);
int UserConsoleMap(char mazeMap[N + 2][N + 2], char userInput, int &X, int &Y);
int IsWin(char mazeMap[N + 2][N + 2], int X, int Y);

int main(int argc, char const *argv[])
{
    char mazeMap[N + 2][N + 2] =                    // the map
    {
        {'-','-','-','-','-','-','-','-','-','-','-','-'},
        {'-','*','*','*','*','*','*','F','*','*','*','-'},
        {'-','*',' ',' ',' ',' ',' ',' ',' ',' ','*','-'},
        {'-','*',' ',' ',' ','S','*','*','*','*','*','-'},
        {'-','*',' ',' ',' ',' ',' ',' ',' ','*','*','-'},
        {'-','*',' ',' ',' ',' ',' ',' ',' ','*','*','-'},
        {'-','*',' ',' ',' ',' ',' ',' ',' ','*','*','-'},
        {'-','*',' ',' ',' ',' ',' ',' ',' ','*','*','-'},
        {'-','*',' ',' ',' ',' ',' ',' ',' ','*','*','-'},
        {'-','*','*','*','*','*','*','*','*','*','*','-'},
        {'-','-','-','-','-','-','-','-','-','-','*','-'}
    };
    PrintMap(mazeMap);
    char userInput;
    int X = 3;              // start at (3,5)
    int Y = 5;
    int userConsoleResult = 0;
    for(;;)
    {
        scanf("%c",&userInput);     // if you give me more than one char, I will be not happy
        getchar();                  // so I will anger with you
        userConsoleResult = UserConsoleMap(mazeMap, userInput, X, Y);
        if (userConsoleResult == YOU_WIN)
        {
            printf("you win!\n");
            break;
        }
        else if (userConsoleResult == STEP_INTO_WALL)
        {
            printf("Will you into the wall?\n");
            continue;
        }
        else if (userConsoleResult == OK)
        {
            system("cls");
            PrintMap(mazeMap);
            printf("go on\n");
            continue;
        }
        else if (userConsoleResult == WRONG_INPUT)
        {
            system("cls");
            PrintMap(mazeMap);
            printf("wrong input\n");
            continue;
        }
        else
        {
            printf("ERROR!\n");
        }
    }

    return 0;
}







// print the map
int PrintMap(char mazeMap[N + 2][N + 2])
{
    for (int i= 1;i <= N;i++)       // print map start
    {
        for (int j = 1;j <= N;j++)
        {
            printf("%c",mazeMap[i][j]);
        }
        printf("\n");
    }                               // print map end
    return 1;                       // OK
}


// user console
int UserConsoleMap(char mazeMap[N + 2][N + 2],char userInput, int &X, int &Y)
{
    // wall -1
    // win 8
    // OK step 1
    // flase input 0
    int toThisDirection;
    switch (userInput)
    {
        case 'W':
        {
            toThisDirection = IsWin(mazeMap, X - 1, Y) ;
            if (toThisDirection == WIN_THE_GAME)
            {
                return YOU_WIN;              //Win
            }
            else if (toThisDirection == OK_STEP)
            {
                mazeMap[X][Y] = ' ';
                mazeMap[--X][Y] = 'S';

                return OK;
            }
            else if (toThisDirection == STEP_TO_WALL)
            {
                return STEP_INTO_WALL;          // wall
            }
        }
        break;

        case 'A':
        {
            toThisDirection = IsWin(mazeMap, X, Y - 1);
            if (toThisDirection == WIN_THE_GAME)
            {
                return YOU_WIN;              //Win
            }
            else if (toThisDirection == OK_STEP)
            {
                mazeMap[X][Y] = ' ';
                mazeMap[X][--Y] = 'S';

                return OK;
            }
            else if (toThisDirection == STEP_TO_WALL)
            {
                return STEP_INTO_WALL;          // wall
            }
        }
        break;

        case 'D':
        {
            toThisDirection = IsWin(mazeMap, X , Y + 1);
            if (toThisDirection == WIN_THE_GAME)
            {
                return YOU_WIN;              //Win
            }
            else if (toThisDirection == OK_STEP)
            {
                mazeMap[X][Y] = ' ';
                mazeMap[X][++Y] = 'S';
                return OK;
            }
            else if (toThisDirection == STEP_TO_WALL)
            {
                return STEP_INTO_WALL;          // wall
            }
        }
        break;

        case 'S':
        {
            toThisDirection = IsWin(mazeMap, X + 1 , Y) ;
            if (toThisDirection == WIN_THE_GAME)
            {
                return YOU_WIN;              //Win
            }
            else if (toThisDirection == OK_STEP)
            {
                mazeMap[X][Y] = ' ';
                mazeMap[++X][Y] = 'S';
                return OK;
            }
            else if (toThisDirection == STEP_TO_WALL)
            {
                return STEP_INTO_WALL;          // wall
            }
        }
        break;
    }
    return 0;
}


// judge the step is OK
int IsWin(char mazeMap[N + 2][N + 2],int X, int Y)
{
    switch(mazeMap[X][Y])
    {
        case 'F':
        {
            return WIN_THE_GAME;       // WIN
        }

        case '-':
        {
            return STEP_TO_BOUNDARY;       //boundary
        }

        case '*':
        {
            return STEP_TO_WALL;
        }

        case ' ':
        {
            return OK_STEP;
        }
    }
    //  ERROR here, but can't come here
}