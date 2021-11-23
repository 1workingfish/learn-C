#define _CRT_SECURE_NO_WARNINGS

#include"tree.h"

int main()
{
    BiTree TT = 0; // ������ָ�������

  /*
  // �ֹ�����һ�����½ṹ�Ķ�������
             1
          /     \
         2       3
        / \     /
       4   5   6
      / \ / \
     7  8 9  0
  */

  // ������ڵ㡣
    TT = (BiTNode*)malloc(sizeof(BiTNode));
    TT->data = '1';
    TT->lchild = TT->rchild = 0;

    // �ڶ����һ���ڵ㡣
    TT->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    TT->lchild->data = '2'; 
    TT->lchild->lchild = TT->lchild->rchild = 0;

    // �ڶ���ڶ����ڵ㡣
    TT->rchild = (BiTNode*)malloc(sizeof(BiTNode));
    TT->rchild->data = '3'; 
    TT->rchild->lchild = TT->rchild->rchild = 0;

    // �������һ���ڵ㡣
    TT->lchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    TT->lchild->lchild->data = '4'; 
    TT->lchild->lchild->lchild = TT->lchild->lchild->rchild = 0;

    // ������ڶ����ڵ㡣
    TT->lchild->rchild = (BiTNode*)malloc(sizeof(BiTNode));
    TT->lchild->rchild->data = '5';
    TT->lchild->rchild->lchild = TT->lchild->rchild->rchild = 0;

    // ������������ڵ㡣
    TT->rchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    TT->rchild->lchild->data = '6'; 
    TT->rchild->lchild->lchild = TT->rchild->lchild->rchild = 0;

    // ���Ĳ��һ���ڵ㡣
    TT->lchild->lchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    TT->lchild->lchild->lchild->data = '7';
    TT->lchild->lchild->lchild->lchild = TT->lchild->lchild->lchild->rchild = 0;

    // ���Ĳ�ڶ����ڵ㡣
    TT->lchild->lchild->rchild = (BiTNode*)malloc(sizeof(BiTNode));
    TT->lchild->lchild->rchild->data = '8';
    TT->lchild->lchild->rchild->lchild = TT->lchild->lchild->rchild->rchild = 0;

    // ���Ĳ�������ڵ㡣
    TT->lchild->rchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    TT->lchild->rchild->lchild->data = '9'; 
    TT->lchild->rchild->lchild->lchild = TT->lchild->rchild->lchild->rchild = 0;

    // ���Ĳ���ĸ��ڵ㡣
    TT->lchild->rchild->rchild = (BiTNode*)malloc(sizeof(BiTNode));
    TT->lchild->rchild->rchild->data = '0';
    TT->lchild->rchild->rchild->lchild = TT->lchild->rchild->rchild->rchild = 0;

    // ��������α�����
    printf("��α��������"); 
    LevelOrder(TT); 
    printf("\n");
	return 0;
}