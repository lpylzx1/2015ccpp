/******************************************************************************
Author:lpylzx1
Usage:
	N ---------> 	How many kinds of computer
	enum PC -->	Have N element, from 0 to (N - 1)
	and,
		you need update the function "Name"

******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
typedef char* string;
enum PC{Mac, Yoga, ThinkPad, Other};

void Init(int *computer, int n);
string Name(int number);
void SetNumber(int *ptr, int things, int number);
int VisitNumber(int *ptr, int things);
int NumberClac(int *ptr,int things);
void Usage(int n);
void NumberUpdata(int *computer, int id);
void Read(int *computer,int n);
int Save(int *computer, int n);
void Run(int *computer, int n);
void Outputall(int *computer, int n);

#define N 			4
#define ERROR		-1






int main(int argc, char const *argv[])
{
	int *computer;
	computer = (int *)malloc(sizeof(int) * (N + 1));
	Run(computer, N);

	return 0;

}

// from number return string
string Name(int number)
{
	switch(number)
	{
		case -2:
			return "show data";
		case -1:
			return "Save & Exit";
		case 0:
			return "Mac";
		case 1:
			return "Yoga";
		case 2:
			return "ThinkPad";
		case 3:
			return "Other";
	}
}

//first start
void Init(int *computer, int n)
{
	printf("Creating the data file,Please wait...\n");
	FILE *fp;
	fp = fopen("data","w+");
	for(int id = 0; id < n; id++)
	{
		fprintf(fp,"%d:0 \n",id);
	}
	printf("Init Success\n");
}



// set the data
void SetNumber(int *ptr, int things, int number)
{
	ptr[things] = number;
}

//return the value
int VisitNumber(int *ptr, int things)
{
	return ptr[things];
}

//running,change the value
int NumberClac(int *ptr,int things)
{
	int number;
	printf("How many %s you will change?\n",Name(things));
	scanf("%d",&number);
	ptr[things] += number;
}

//user usage
void Usage(int n)
{
	printf("Please input the number\n");
	for (int id = -2; id < n; id++)
	{
		printf("%s:%d ",Name(id), id);
	}
	printf("\n");
}

//after change,alert the user the now number
void NumberUpdata(int *computer, int id)
{
	printf("you have: %s %d\n",Name(id), VisitNumber(computer, id));
}

//save to file
int Save(int *computer, int n)
{
	FILE *fp;
	fp = fopen("data", "w+");
	for (int things = 0; things < n; things++)
	{
		fprintf(fp,"%d:%d \n",things, VisitNumber(computer, things));
	}
	fclose(fp);
}

//read from file
void Read(int *computer,int n)
{
	if (access("data",0) == -1)
	{
		Init(computer, n);
	}
	FILE *fp;
	fp = fopen("data", "r");
	if (fp == NULL)
	{
		Init(computer,n);
	}
	int id,number;
	for (int id = 0;id < n;id++)
	{
		fscanf(fp,"%d:%d ",&id, &number);
		SetNumber(computer,id,number);
	}

	fclose(fp);
}

// run....input & control
void Run(int *computer, int n)
{
	Read(computer, n);
	Outputall(computer, n);
	for(int id = 0;;)
	{
		Usage(n);
		scanf("%d",&id);
		if (id == -2)
		{
			Outputall(computer, n);
		}
		else if (id == -1)
		{
			printf("Thanks!We will exit\n");
			Save(computer, n);
			printf("Save in \"data\"\n");
			exit(0);
		}
		else
		{
			NumberClac(computer, id);
			NumberUpdata(computer, id);
		}
	}
}

//output all list
void Outputall(int *computer, int n)
{
	for (int id = 0; id < n; id++)
	{
		NumberUpdata(computer, id);
	}
}
