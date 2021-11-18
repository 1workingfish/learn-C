#define _CRT_SECURE_NO_WARNINGS

#include"queue.h"

int main()
{
	QUEUE Q;
	int val;
	init(&Q);
	en_queue(&Q, 1);
	en_queue(&Q, 2);
	en_queue(&Q, 3);
	en_queue(&Q, 4);
	en_queue(&Q, 5);
	en_queue(&Q, 6);
	en_queue(&Q, 7);
	traverse_queue(&Q);
	out_queue(&Q, &val);
	traverse_queue(&Q);
	return 0;
}