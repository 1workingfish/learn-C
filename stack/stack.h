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


//��������
void init(PSTACK psk);//��ʼ��ջ
void push(PSTACK psk, int val);//��ջ
void traverse(PSTACK psk);//����ջ
bool is_empty(PSTACK psk);//�ж��Ƿ�Ϊ��
bool pop(PSTACK psk, int* val);//��ջ
void clear(PSTACK psk);//���

