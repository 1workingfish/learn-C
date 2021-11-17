#define _CRT_SECURE_NO_WARNINGS

#include"stack.h"

void init(PSTACK psk)
{
	PNODE p = (PNODE)malloc(sizeof(NODE));
	if (p == NULL)
	{
		printf("·ÖÅäÊ§°Ü£¬ÍË³ö³ÌÐò£¡\n");
		exit(-1);
	}
	psk->pTop = p;
	psk->pBotton = psk->pTop;
	psk->pTop = NULL;
}

void push(PSTACK psk,int val)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (pNew == NULL)
	{
		printf("·ÖÅäÊ§°Ü£¬ÍË³ö³ÌÐò\n");
		exit(-1);
	}
	pNew->date = val;
	pNew->pNext = psk->pTop;
	psk->pTop = pNew;
}

void traverse(PSTACK psk)
{
	PNODE p = psk->pTop;
	while (p != psk->pBotton)
	{
		printf("%d ", p->date);
		p = p->pNext;
	}
	printf("\n");
}

bool is_empty(PSTACK psk)
{
	if (psk->pTop == psk->pBotton)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

bool pop(PSTACK psk, int* val)
{
	if (is_empty(psk) != 0)
	{
		return false;
	}
	PNODE p = psk->pTop;
	*val = p->date;
	psk->pTop = p->pNext;
	free(p);
	p = NULL;
	return true;
}

void clear(PSTACK psk)
{
	if (is_empty(psk))
	{
		return;
	}
	else
	{
		PNODE p = psk->pTop;
		PNODE q = NULL;
		while (p != psk->pBotton)
		{
			q = p->pNext;
			free(p);
			p = q;
		}
		psk->pTop = psk->pBotton;
	}
}