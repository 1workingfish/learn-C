#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define MAXSIZE 100//�����ܴ�����Ԫ�صĸ���

typedef struct BiTNode
{
	char data;//��Ž��Ԫ��
	struct BiTNode* lchild;//ָ�����ӽ���ַ��ָ��
	struct BiTNode* rchild;//ָ�����ӽ���ַ��ָ��
}BiTNode,*BiTree;

typedef BiTree ElemType;//�Զ�������Ԫ������

typedef struct
{
	ElemType date[MAXSIZE];//������洢˳��ջ�е�Ԫ��
	int top;//ջ��ָ�룬��0��MAXSIZE��-1��ʾ��ջ
}Seqstack,*PSeqstack;

//��������
void InitStack(PSeqstack SS);//��ʼ��ջ
void Clear(PSeqstack SS);//���ջ
int Is_Full(PSeqstack SS);//�ж��Ƿ�Ϊ��
int Is_Empty(PSeqstack SS);//�ж��Ƿ�Ϊ��
int Length(PSeqstack SS);//���㳤��
int Pop(PSeqstack SS, ElemType* ee);//��ջ
int Push(PSeqstack SS, ElemType* ee);//��ջ
void PrintfStack(PSeqstack SS);//��ӡԪ��
int GetTop(PSeqstack SS, ElemType* ee);//��ȡջ��Ԫ��

//������
void visit(BiTree TT);//���ʽ��Ԫ��
//���õݹ����������
void PreOrder(BiTree TT);//�������
void InOrder(BiTree TT);//�������
void PostOrder(BiTree TT);//�������
//�����õݹ����������
void PreOrder1(BiTree TT);
void InOrder1(BiTree TT);
void PostOrder1(BiTree TT);
int TreeDepth(BiTree TT);//��������ĸ߶�