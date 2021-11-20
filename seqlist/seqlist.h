#pragma once

#include <stdio.h>
#include<string.h>

#define MAXSIZE 100//˳����д��Ԫ�ص���󳤶�
typedef int ElemType;

typedef struct
{
	ElemType date[MAXSIZE];//��������˳����е�Ԫ��
	int length;//˳�����Ԫ�صĸ���
}SeqList,*PSeqList;


//��������
//��ʼ��˳���
void InitList(PSeqList LL);
//����˳���
void DestroyList(PSeqList LL);
//�ڵ�ii��λ�ò���Ԫ��ee  ����ֵ��0-ʧ�� 1-�ɹ�
int InsertList(PSeqList LL, int ii, ElemType* ee);
//�ڱ�ͷ����
int PushFront(PSeqList LL, ElemType* ee);
//�ڱ�β����
int PushBack(PSeqList LL, ElemType* ee);
//�󳤶�
int LengthList(PSeqList LL);
//��ȡԪ��
int GetElem(PSeqList LL, int ii, ElemType* ee);
//���˳���
void ClearList(PSeqList LL);
//�ж��Ƿ�Ϊ��
int IsEmpty(PSeqList LL);
//��ӡ˳���
void PrintfList(PSeqList LL);
//����ee��˳����е�λ��
int LocateList(PSeqList LL, ElemType* ee);
//ɾ����ii��Ԫ��
int DeleteElem(PSeqList LL, int ii);
//ɾ��ͷԪ��
int PopFront(PSeqList LL);
//ɾ��βԪ��
int PopBack(PSeqList LL);
//�鲢  �����������ϲ���һ��
int MergeList(PSeqList La, PSeqList Lb, PSeqList Lc);
