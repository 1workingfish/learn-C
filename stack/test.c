#define _CRT_SECURE_NO_WARNINGS

#include"stack.h"
int main()
{
	STACK s;
	//int val;

	init(&s);
	push(&s, 54);
	push(&s, 31);
	push(&s, 59);
	push(&s, 100);
	push(&s, 3);
	/*if (pop(&s, &val))
	{
		printf("出栈成功，输出的元素为%d\n", val);
	}
	else
	{
		printf("出栈失败\n");
	}*/

	traverse(&s);
	clear(&s);

	traverse(&s);
	return 0;
}