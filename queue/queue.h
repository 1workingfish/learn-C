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

//��������
void init(QUEUE* pQ);//��ʼ������
bool en_queue(QUEUE* pQ, int val);//���
bool full_queue(QUEUE* pQ);//�ж��Ƿ�Ϊ��
void traverse_queue(QUEUE* pQ);//��������
bool out_queue(QUEUE* pQ, int* val);//����
bool empty_queue(QUEUE* pQ);//�ж��Ƿ�Ϊ��