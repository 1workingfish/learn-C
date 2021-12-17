#define _CRT_SECURE_NO_WARNINGS


#include"Sort.h"

int main()
{
	SqList s;
	InitList(&s);
	saveList(&s, 49);
	saveList(&s, 38);
	saveList(&s, 65);
	saveList(&s, 97);
	saveList(&s, 76);
	saveList(&s, 13);
	saveList(&s, 27);
	saveList(&s, 49);
	saveList(&s, 6);
	//for (int i = 1; i < MAXSIZE + 1; i++)
	//{
	//	printf("%d\n", s.r[i].key);
	//}
	// Ö±½Ó²åÈëÅÅÐò
	//InsertSort(&s);
	// ÕÛ°ë²åÈëÅÅÐò
	//BInsertSort(&s);
	//Ï£¶ûÅÅÐò
	/*int dk[3] = { 0 };
	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &dk[i]);
	}
	ShellSort(&s, dk, 3);*/
	//Ã°ÅÝÅÅÐò
	//BubbleSort(&s);
	// ¿ìËÙÅÅÐò
	//QuickSort(&s);
	//¼òµ¥Ñ¡ÔñÅÅÐò
	//SelectSort(&s);
	//¶ÑÅÅÐò
	//HeapSort(&s);

	//MergeSort(&s);
	for (int i = 1; i < MAXSIZE + 1; i++)
	{
		printf("%-3d", s.r[i].key);
	}
	return 0;
}