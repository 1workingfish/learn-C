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
	// ֱ�Ӳ�������
	//InsertSort(&s);
	// �۰��������
	//BInsertSort(&s);
	//ϣ������
	/*int dk[3] = { 0 };
	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &dk[i]);
	}
	ShellSort(&s, dk, 3);*/
	//ð������
	//BubbleSort(&s);
	// ��������
	//QuickSort(&s);
	//��ѡ������
	//SelectSort(&s);
	//������
	//HeapSort(&s);

	//MergeSort(&s);
	for (int i = 1; i < MAXSIZE + 1; i++)
	{
		printf("%-3d", s.r[i].key);
	}
	return 0;
}