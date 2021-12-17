#define _CRT_SECURE_NO_WARNINGS

#include"Sort.h"
void InitList(SqList* s)
{
	memset(s->r, 0, sizeof(KeyType) * (MAXSIZE + 1));
	s->length = 0;
}

void saveList(SqList* s, int elem)
{
	if (FullList(s) == 1)
	{
		printf("数组元素已满\n");
		return;
	}
	s->length++;
	s->r[s->length].key = elem;
}

int EmptyList(SqList* s)
{
	if (s->length == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int FullList(SqList* s)
{
	if (s->length == MAXSIZE)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}