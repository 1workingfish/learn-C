#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int ElemType;//自定义数据类型

//二叉树的数据结构
typedef struct BSTNode
{
	ElemType data;//存放树中的元素
	struct BSTNode* lchild;//指向左节点地址的指针
	struct BSTNode* rchild;//指向右节点地址的指针
}BSTNode,*BSTree;

//声明函数
// 在树TT中插入关键字为ee的新结点（递归实现），返回值：0-树中已存在关键字为ee的结点；1-成功。
int Insert(BSTree* TT, ElemType* ee);

// 在树TT中插入关键字为ee的新结点（非递归实现），返回值：0-树中已存在关键字为ee的结点；1-成功。
int Insert1(BSTree* TT, ElemType* ee);

// 用数组arr中的序列构建二叉排序树TT。
void GreateBST(BSTree* TT, int* arr, int len);

// 在树TT中查找值为ee的结点（递归实现），成功返回结点的地址，失败返回NULL。
BSTNode* Find(BSTree TT, ElemType* ee);

// 在树TT中查找值为ee的结点（非递归实现），成功返回结点的地址，失败返回NULL。
BSTNode* Find1(BSTree TT, ElemType* ee);

// 在树TT中删除值为ee的结点，成功返回0，结点不存在返回1。
int Delete(BSTree* TT, ElemType* ee);

// 求二叉树的高度。
int TreeDepth(BSTree TT);

// 访问结点元素。
void visit(BSTNode* pp);

// 采用递归的方法对二叉树的先序遍历。
void PreOrder(BSTree TT);

// 采用递归的方法对二叉树的中序遍历。
void InOrder(BSTree TT);

// 采用递归的方法对二叉树的后序遍历。
void PostOrder(BSTree TT);