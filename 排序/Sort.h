#pragma once

#include<stdio.h>
#include<string.h>


#define MAXSIZE 20

typedef int KeyType;//�Զ�����������

typedef struct
{
	KeyType key;
	//InfoType otherInfo ����������
}RedType;
typedef struct
{
	RedType r[MAXSIZE + 1];//r[0]���û����ڱ���Ԫ
	int length;//˳���ĳ���
}SqList;


//��������

//��ʼ��˳���
void InitList(SqList* s);

//���Ԫ��
void saveList(SqList* s,int elem);

//�ж��Ƿ�Ϊ��
int EmptyList(SqList* s);

//�ж��Ƿ�����
int FullList(SqList* s);

//1.��������
//ֱ�Ӳ�������
void InsertSort(SqList* s);

//�۰��������
void BInsertSort(SqList* s);

//ϣ������
void ShellInsert(SqList* s, int dk);
void ShellSort(SqList* s, int dk[], int t);

//2.��������
//ð������
void BubbleSort(SqList* s);

//��������
void QuickSort(SqList* s);
void QSort(SqList* s, int low, int high);
int Partition(SqList* s, int low, int high);

//3.ѡ������
//��ѡ������
void SelectSort(SqList* s);

//������
void HeapAdjust(SqList* s, int n,int m);
void CreatHeap(SqList* s);
void HeapSort(SqList* s);

//�鲢����
void MergeSort(SqList* s);
void MSort(RedType R[], RedType T[], int low, int high);
void Merge(RedType R[], RedType T[], int low, int mid, int high);