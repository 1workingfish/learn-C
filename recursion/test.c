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
//	//n�Ľ׳�
//	/*int val = 0;
//	printf("������һ�����֣�\n");
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
		printf("�����Ϊ%d������ֱ�Ӵ�%c�����ƶ���%c����\n", n, A, C);
	}
	else
	{
		hannuota(n - 1, A, C, B);
		printf("�����Ϊ%d������ֱ�Ӵ�%c�����ƶ���%c����\n", n, A, C);
		hannuota(n - 1, B, A, C);
	}
}

int main()
{
	char ch1 = 'A';
	char ch2 = 'B';
	char ch3 = 'C';
	int n = 0;
	printf("������Ҫ�ƶ����ӵ�����:");
	scanf("%d", &n);
	hannuota(n,'A','B','C');
	return 0;
}