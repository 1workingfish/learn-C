#define _CRT_SECURE_NO_WARNINGS

#include"queue.h"

void init(QUEUE* pQ)
{
	pQ->pBase = (int*)malloc(sizeof(int) * 6);
	pQ->front = 0;
	pQ->rear = 0;
}

bool en_queue(QUEUE* pQ, int val)
{
	if (full_queue(pQ) == 1)
	{
		return false;
	}
	else
	{
		pQ->pBase[pQ->rear] = val;
		pQ->rear = (pQ->rear + 1) % 6;
		return true; 
	}
}

bool full_queue(QUEUE* pQ)
{
	if ((pQ->rear + 1) % 6 == pQ->front)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void traverse_queue(QUEUE* pQ)
{
	int i = pQ->front;
	while (i != pQ->rear)
	{
		printf("%d ", pQ->pBase[i]);
		i = (i + 1) % 6;
	}
	printf("\n");
}

bool out_queue(QUEUE* pQ, int* val)
{
	if (empty_queue(pQ) == 1)
	{
		return false;
	}
	else
	{
		*val = pQ->pBase[pQ->front];
		pQ->front = (pQ->front + 1) % 6;
		return true;
	}
}

bool empty_queue(QUEUE* pQ)
{
	if (pQ->front == pQ->rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}