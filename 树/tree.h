#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//���е����ݽṹ��ѭ�����е���󳤶�
#define MAXSIZE 30

//�����������ݽṹ
typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
}BiTNode,*BiTree;

//�Զ�����е�����Ԫ��Ϊ����������
typedef BiTree ElemType;

typedef struct
{
	ElemType data[MAXSIZE];
	int front;
	int rear;
}SeqQueue,*PSeqQueue;

//��������
// ѭ������QQ�ĳ�ʼ������
void InitQueue(PSeqQueue QQ);

// Ԫ����ӣ�����ֵ��0-ʧ�ܣ�1-�ɹ�
int InQueue(PSeqQueue QQ, ElemType* ee);

// Ԫ�س��ӣ�����ֵ��0-ʧ�ܣ�1-�ɹ�
int OutQueue(PSeqQueue QQ, ElemType* ee);

// ��ѭ�����еĳ��ȣ�����ֵ��>=0-����QQԪ�صĸ���
int  Length(PSeqQueue QQ);

// ���ѭ������
void Clear(PSeqQueue QQ);

// �ж�ѭ�������Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ��
int  IsEmpty(PSeqQueue QQ);

// �ж�ѭ�������Ƿ�����������ֵ��1-������0-δ����ʧ��
int IsFull(PSeqQueue QQ);

// �������Ĳ�α���
void LevelOrder(BiTree TT);

// ���ʳ���Ԫ��
void visit(BiTNode* pp);