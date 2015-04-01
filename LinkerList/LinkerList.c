#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define OK 1
#define ERROR 0

typedef int Elem;
typedef int Status;

// Llist is named
typedef struct LNode
{
	Elem data;
	struct LNode *next;
} LNode, *Llist;


//init Llist
void InitLlist(Llist *list)
{
	*list = (Llist) malloc(sizeof(Llist));
	if (list == NULL)
	{
		exit(OVERFLOW);
	}
	(*list)->next = NULL;
}

//destroy Llist
void DestroyLlist(Llist *list)
{
	Llist p;
	while(*list)
	{
		p = (*list)->next;
		free(*list);
		*list = p;
	}
}

void CleatLlist(Llist list)
{
	Llist p = list->next;
	list->next = NULL;
	DestroyLlist(&p);
}

//is the Llist is empty
Status IsEmpty(Llist list)
{
	if(list->next)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

//get length of Llist
int GetLength(Llist list)
{
	int i = 0;
	Llist p = list->next;
	while(p)
	{
		i++;
		p = p->next;
	}
	return i;
}

//get elem from i
Status GetElem(Llist L, int i, Elem *e)
{
	int j = 1;
	Llist p = L->next;
	while (p && j < i)
	{
		j++;
		p = p->next;
	}
	if (p == NULL || j > i)
	{
		return ERROR;
	}
	*e = p->data;
	return OK;
}

//compare two elem is equle
Status CompareIfEqual(Elem e1, Elem e2)
{
	if (e1 == e2)
	{
		return 0;
	}
	else if(e1 < e2)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

//search elem
int FindElem(Llist list, Elem e, Status (*CompareIfEqual)(Elem, Elem))
{
	int i = 0;
	Llist p = list->next;
	while (p)
	{
		i++;
		if(!CompareIfEqual(p->data, e))
		{
			return i;
		}
		p = p->next;
	}
	return 0;
}


//insert elem
Status InsertElem(Llist list, int i, Elem e)
{
	int j = 0;
	Llist s, p = list;
	while(p && j < i - 1)
	{
		j++;
		p = p->next;
	}
	if (p == NULL || j > i - 1)
	{
		return ERROR;
	}
	s = (Llist)malloc(sizeof(Llist));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

//Delete the elem and return it

Status DeleteElem(Llist list, int i, Elem *e)
{
	int j = 0;
	Llist q, p = list;
	while(p->next && j < i -1)
	{
		j++;
		p = p->next;
	}
	if (p->next == NULL || j >i - 1)
	{
		return ERROR;
	}
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;
}

//previous elem
Status PreElem(Llist list, Elem cur_e, Elem *pre_e)
{
	Llist q, p = list->next;
	while(p->next)
	{
		q = p->next;
		if (q->data == cur_e)
		{
			*pre_e == p->data;
			return OK;
		}
		p = q;
	}
	return ERROR;
}

//next elem
Status NextElem(Llist list, Elem cur_e, Elem *next_e)
{
	Llist q, p = list->next;
	while(p->next)
	{
		q = p->next;
		if (q->data == cur_e)
		{
			*next_e == p->next->data;
			return OK;
		}
		p = p->next;
	}
	return ERROR;
}


// print an elem
void Visit(Elem e)
{
	printf("%d ", e);
}


//print the list from 0 to when next is NULL
void TraverseList(Llist list, void (*Visit)(Elem))
{
	Llist p = list->next;
	while(p)
	{
		Visit(p->data);
		p = p->next;
	}
}




int main(int argc, char const *argv[])
{
	Llist list;
	InitLlist(&list);
	Elem e;
	int i;
	if (list)
	{
		printf("init success\n");
	}
	if (IsEmpty(list))
	{
		printf("list is empty\n");
	}

	for (int i = 0; i < 10; i++)
	{
		InsertElem(list, i + 1, i);
	}


	if(GetElem(list, 1, &e))
	{
		printf("The first element is %d\n", e);
	}

	printf("length is %d\n", GetLength(list));

	printf("the 5 at %d\n", FindElem(list, 5, *CompareIfEqual));

	PreElem(list, 6, &e);
	printf("The 6's previous element is %d\n", e);

	DeleteElem(list, 1, &e);
	printf("delete first element is %d\n", e);

	printf("list:");
	TraverseList(list, Visit);

	DestroyLlist(&list);
	if (list == NULL)
	{
		printf("\ndestroy success\n");
	}


	return 0;
}