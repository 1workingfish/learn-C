#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int ElemType;//�Զ�����������

//�����������ݽṹ
typedef struct BSTNode
{
	ElemType data;//������е�Ԫ��
	struct BSTNode* lchild;//ָ����ڵ��ַ��ָ��
	struct BSTNode* rchild;//ָ���ҽڵ��ַ��ָ��
}BSTNode,*BSTree;

//��������
// ����TT�в���ؼ���Ϊee���½�㣨�ݹ�ʵ�֣�������ֵ��0-�����Ѵ��ڹؼ���Ϊee�Ľ�㣻1-�ɹ���
int Insert(BSTree* TT, ElemType* ee);

// ����TT�в���ؼ���Ϊee���½�㣨�ǵݹ�ʵ�֣�������ֵ��0-�����Ѵ��ڹؼ���Ϊee�Ľ�㣻1-�ɹ���
int Insert1(BSTree* TT, ElemType* ee);

// ������arr�е����й�������������TT��
void GreateBST(BSTree* TT, int* arr, int len);

// ����TT�в���ֵΪee�Ľ�㣨�ݹ�ʵ�֣����ɹ����ؽ��ĵ�ַ��ʧ�ܷ���NULL��
BSTNode* Find(BSTree TT, ElemType* ee);

// ����TT�в���ֵΪee�Ľ�㣨�ǵݹ�ʵ�֣����ɹ����ؽ��ĵ�ַ��ʧ�ܷ���NULL��
BSTNode* Find1(BSTree TT, ElemType* ee);

// ����TT��ɾ��ֵΪee�Ľ�㣬�ɹ�����0����㲻���ڷ���1��
int Delete(BSTree* TT, ElemType* ee);

// ��������ĸ߶ȡ�
int TreeDepth(BSTree TT);

// ���ʽ��Ԫ�ء�
void visit(BSTNode* pp);

// ���õݹ�ķ����Զ����������������
void PreOrder(BSTree TT);

// ���õݹ�ķ����Զ����������������
void InOrder(BSTree TT);

// ���õݹ�ķ����Զ������ĺ��������
void PostOrder(BSTree TT);