#pragma once

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>


typedef int bool;
#define true 1
#define false 0

typedef struct Node
{
	int date;
	struct Node* pNext;
}NODE,*PNODE;

typedef struct stack
{
	PNODE pTop;
	PNODE pBotton;
}STACK,*PSTACK;


//声明函数
void init(PSTACK psk);//初始化栈
void push(PSTACK psk, int val);//出栈
void traverse(PSTACK psk);//遍历栈
bool is_empty(PSTACK psk);//判断是否为空
bool pop(PSTACK psk, int* val);//出栈
void clear(PSTACK psk);//清空

