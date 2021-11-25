#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define MAXSIZE 100//数组总存放最大元素的个数

typedef struct BiTNode
{
	char data;//存放结点元素
	struct BiTNode* lchild;//指向左子结点地址的指针
	struct BiTNode* rchild;//指向右子结点地址的指针
}BiTNode,*BiTree;

typedef BiTree ElemType;//自定义数组元素类型

typedef struct
{
	ElemType date[MAXSIZE];//用数组存储顺序栈中的元素
	int top;//栈顶指针，从0到MAXSIZE，-1表示空栈
}Seqstack,*PSeqstack;

//声明函数
void InitStack(PSeqstack SS);//初始化栈
void Clear(PSeqstack SS);//清空栈
int Is_Full(PSeqstack SS);//判断是否为满
int Is_Empty(PSeqstack SS);//判断是否为空
int Length(PSeqstack SS);//计算长度
int Pop(PSeqstack SS, ElemType* ee);//出栈
int Push(PSeqstack SS, ElemType* ee);//入栈
void PrintfStack(PSeqstack SS);//打印元素
int GetTop(PSeqstack SS, ElemType* ee);//获取栈顶元素

//二叉树
void visit(BiTree TT);//访问结点元素
//采用递归遍历二叉树
void PreOrder(BiTree TT);//先序遍历
void InOrder(BiTree TT);//中序遍历
void PostOrder(BiTree TT);//后序遍历
//不采用递归遍历二叉树
void PreOrder1(BiTree TT);
void InOrder1(BiTree TT);
void PostOrder1(BiTree TT);
int TreeDepth(BiTree TT);//求二叉树的高度