#pragma once

#include<stdio.h>
#include<string.h>


#define MAXSIZE 20

typedef int KeyType;//自定义数据类型

typedef struct
{
	KeyType key;
	//InfoType otherInfo 其他数据项
}RedType;
typedef struct
{
	RedType r[MAXSIZE + 1];//r[0]闲置或做哨兵单元
	int length;//顺序表的长度
}SqList;


//声明函数

//初始化顺序表
void InitList(SqList* s);

//存放元素
void saveList(SqList* s,int elem);

//判断是否为空
int EmptyList(SqList* s);

//判断是否已满
int FullList(SqList* s);

//1.插入排序
//直接插入排序
void InsertSort(SqList* s);

//折半插入排序
void BInsertSort(SqList* s);

//希尔排序
void ShellInsert(SqList* s, int dk);
void ShellSort(SqList* s, int dk[], int t);

//2.交换排序
//冒泡排序
void BubbleSort(SqList* s);

//快速排序
void QuickSort(SqList* s);
void QSort(SqList* s, int low, int high);
int Partition(SqList* s, int low, int high);

//3.选择排序
//简单选择排序
void SelectSort(SqList* s);

//堆排序
void HeapAdjust(SqList* s, int n,int m);
void CreatHeap(SqList* s);
void HeapSort(SqList* s);

//归并排序
void MergeSort(SqList* s);
void MSort(RedType R[], RedType T[], int low, int high);
void Merge(RedType R[], RedType T[], int low, int mid, int high);