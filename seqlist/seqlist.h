#pragma once

#include <stdio.h>
#include<string.h>

#define MAXSIZE 100//顺序表中存放元素的最大长度
typedef int ElemType;

typedef struct
{
	ElemType date[MAXSIZE];//用数组存放顺序表中的元素
	int length;//顺序表中元素的个数
}SeqList,*PSeqList;


//声明函数
//初始化顺序表
void InitList(PSeqList LL);
//销毁顺序表
void DestroyList(PSeqList LL);
//在第ii个位置插入元素ee  返回值：0-失败 1-成功
int InsertList(PSeqList LL, int ii, ElemType* ee);
//在表头插入
int PushFront(PSeqList LL, ElemType* ee);
//在表尾插入
int PushBack(PSeqList LL, ElemType* ee);
//求长度
int LengthList(PSeqList LL);
//获取元素
int GetElem(PSeqList LL, int ii, ElemType* ee);
//清空顺序表
void ClearList(PSeqList LL);
//判断是否为空
int IsEmpty(PSeqList LL);
//打印顺序表
void PrintfList(PSeqList LL);
//查找ee在顺序表中的位置
int LocateList(PSeqList LL, ElemType* ee);
//删除第ii个元素
int DeleteElem(PSeqList LL, int ii);
//删除头元素
int PopFront(PSeqList LL);
//删除尾元素
int PopBack(PSeqList LL);
//归并  把两个升序表合并成一个
int MergeList(PSeqList La, PSeqList Lb, PSeqList Lc);
