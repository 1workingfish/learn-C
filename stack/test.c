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
		printf("��ջ�ɹ��������Ԫ��Ϊ%d\n", val);
	}
	else
	{
		printf("��ջʧ��\n");
	}*/

	traverse(&s);
	clear(&s);

	traverse(&s);
	return 0;
}