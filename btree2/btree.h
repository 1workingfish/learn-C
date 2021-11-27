#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//线索二叉树的结构体
typedef struct TBTNode
{
	char data;//存放结点的数据元素
	struct TBTNode* lchild;//指向左子节点地址的指针
	struct TBTNode* rchild;//指向右子结点地址的指针
	int ltag;
	int rtag;//左右指针的类型，非线索指针-0 线索指针-1
}TBTNode,*TBTTree;

//声明函数
void visit(TBTTree TT);//访问结点元素
void PreOrder(TBTTree TT);//递归先序遍历
void InOrder(TBTTree TT);//递归中序遍历
void PostOrder(TBTTree TT);//递归后序遍历
void InThread(TBTTree TT, TBTTree* pre);//线索化二叉树
void CrtInThread(TBTTree TT);//线索化二叉树的主函数
TBTNode* FirstNode(TBTTree TT);
TBTNode* NextNode(TBTTree TT);
void InOrder1(TBTTree TT);
TBTNode* LastNode(TBTTree TT);
TBTNode* PriorNode(TBTTree TT);
void InOrder2(TBTTree TT);