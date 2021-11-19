#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//int fun(int val)
//{
//	if (val == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return val * fun(val - 1);
//	}	
//}
//
//int g(int n)
//{
//	if (n == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return n + g(n - 1);
//	}
//}
//
//int main()
//{
//	//n的阶乘
//	/*int val = 0;
//	printf("请输入一个数字：\n");
//	printf("val = ");
//	scanf("%d", &val);
//	int k = fun(val);
//	printf("%d\n", k);*/
//
//	printf("%d\n", g(100));
//	return 0;
//}

hannuota(int n, char A, char B, char C)
{
	if (n == 1)
	{
		printf("将编号为%d的盘子直接从%c柱子移动到%c柱子\n", n, A, C);
	}
	else
	{
		hannuota(n - 1, A, C, B);
		printf("将编号为%d的盘子直接从%c柱子移动到%c柱子\n", n, A, C);
		hannuota(n - 1, B, A, C);
	}
}

int main()
{
	char ch1 = 'A';
	char ch2 = 'B';
	char ch3 = 'C';
	int n = 0;
	printf("请输入要移动盘子的数量:");
	scanf("%d", &n);
	hannuota(n,'A','B','C');
	return 0;
}