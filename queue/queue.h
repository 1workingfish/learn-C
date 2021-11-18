#pragma once

#include<stdio.h>
#include<malloc.h>

typedef int bool;
#define true 1
#define false 0

typedef struct Queue
{
	int* pBase;
	int front;
	int rear;
}QUEUE;

//声明函数
void init(QUEUE* pQ);//初始化队列
bool en_queue(QUEUE* pQ, int val);//入队
bool full_queue(QUEUE* pQ);//判断是否为满
void traverse_queue(QUEUE* pQ);//遍历队列
bool out_queue(QUEUE* pQ, int* val);//出队
bool empty_queue(QUEUE* pQ);//判断是否为空