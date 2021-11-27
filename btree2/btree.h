#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//�����������Ľṹ��
typedef struct TBTNode
{
	char data;//��Ž�������Ԫ��
	struct TBTNode* lchild;//ָ�����ӽڵ��ַ��ָ��
	struct TBTNode* rchild;//ָ�����ӽ���ַ��ָ��
	int ltag;
	int rtag;//����ָ������ͣ�������ָ��-0 ����ָ��-1
}TBTNode,*TBTTree;

//��������
void visit(TBTTree TT);//���ʽ��Ԫ��
void PreOrder(TBTTree TT);//�ݹ��������
void InOrder(TBTTree TT);//�ݹ��������
void PostOrder(TBTTree TT);//�ݹ�������
void InThread(TBTTree TT, TBTTree* pre);//������������
void CrtInThread(TBTTree TT);//��������������������
TBTNode* FirstNode(TBTTree TT);
TBTNode* NextNode(TBTTree TT);
void InOrder1(TBTTree TT);
TBTNode* LastNode(TBTTree TT);
TBTNode* PriorNode(TBTTree TT);
void InOrder2(TBTTree TT);