#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//队列的数据结构，循环队列的最大长度
#define MAXSIZE 30

//二叉树的数据结构
typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
}BiTNode,*BiTree;

//自定义队列的数组元素为二叉树类型
typedef BiTree ElemType;

typedef struct
{
	ElemType data[MAXSIZE];
	int front;
	int rear;
}SeqQueue,*PSeqQueue;

//声明函数
// 循环队列QQ的初始化操作
void InitQueue(PSeqQueue QQ);

// 元素入队，返回值：0-失败；1-成功
int InQueue(PSeqQueue QQ, ElemType* ee);

// 元素出队，返回值：0-失败；1-成功
int OutQueue(PSeqQueue QQ, ElemType* ee);

// 求循环队列的长度，返回值：>=0-队列QQ元素的个数
int  Length(PSeqQueue QQ);

// 清空循环队列
void Clear(PSeqQueue QQ);

// 判断循环队列是否为空，返回值：1-空，0-非空或失败
int  IsEmpty(PSeqQueue QQ);

// 判断循环队列是否已满，返回值：1-已满，0-未满或失败
int IsFull(PSeqQueue QQ);

// 二叉树的层次遍历
void LevelOrder(BiTree TT);

// 访问出队元素
void visit(BiTNode* pp);