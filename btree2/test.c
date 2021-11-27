#define _CRT_SECURE_NO_WARNINGS

#include"btree.h"

int main()
{
    TBTTree TT = 0; // ������ָ�������

     /*
     // �ֹ�����һ�����½ṹ�Ķ�������
                1
             /     \
            2       3
           / \     /
          4   5   6
         / \ /   /
        7  8 9  0
     */

     // ������ڵ㡣
    TT = (TBTNode*)malloc(sizeof(TBTNode));
    TT->data = '1';
    TT->lchild = TT->rchild = 0;
    TT->ltag = TT->rtag = 0;

    // �ڶ����һ���ڵ㡣
    TT->lchild = (TBTNode*)malloc(sizeof(TBTNode));
    TT->lchild->data = '2';
    TT->lchild->lchild = TT->lchild->rchild = 0;
    TT->lchild->ltag = TT->lchild->rtag = 0;

    // �ڶ���ڶ����ڵ㡣
    TT->rchild = (TBTNode*)malloc(sizeof(TBTNode));
    TT->rchild->data = '3';
    TT->rchild->lchild = TT->rchild->rchild = 0;
    TT->rchild->ltag = TT->rchild->rtag = 0;

    // �������һ���ڵ㡣
    TT->lchild->lchild = (TBTNode*)malloc(sizeof(TBTNode));
    TT->lchild->lchild->data = '4';
    TT->lchild->lchild->lchild = TT->lchild->lchild->rchild = 0;
    TT->lchild->lchild->ltag = TT->lchild->lchild->rtag = 0;

    // ������ڶ����ڵ㡣
    TT->lchild->rchild = (TBTNode*)malloc(sizeof(TBTNode));
    TT->lchild->rchild->data = '5';
    TT->lchild->rchild->lchild = TT->lchild->rchild->rchild = 0;
    TT->lchild->rchild->ltag = TT->lchild->rchild->rtag = 0;

    // ������������ڵ㡣
    TT->rchild->lchild = (TBTNode*)malloc(sizeof(TBTNode));
    TT->rchild->lchild->data = '6';
    TT->rchild->lchild->lchild = TT->rchild->lchild->rchild = 0;
    TT->rchild->lchild->ltag = TT->rchild->lchild->rtag = 0;

    // ���Ĳ��һ���ڵ㡣
    TT->lchild->lchild->lchild = (TBTNode*)malloc(sizeof(TBTNode));
    TT->lchild->lchild->lchild->data = '7';
    TT->lchild->lchild->lchild->lchild = TT->lchild->lchild->lchild->rchild = 0;
    TT->lchild->lchild->lchild->ltag = TT->lchild->lchild->lchild->rtag = 0;

    // ���Ĳ�ڶ����ڵ㡣
    TT->lchild->lchild->rchild = (TBTNode*)malloc(sizeof(TBTNode));
    TT->lchild->lchild->rchild->data = '8';
    TT->lchild->lchild->rchild->lchild = TT->lchild->lchild->rchild->rchild = 0;
    TT->lchild->lchild->rchild->ltag = TT->lchild->lchild->rchild->rtag = 0;

    // ���Ĳ�������ڵ㡣
    TT->lchild->rchild->lchild = (TBTNode*)malloc(sizeof(TBTNode));
    TT->lchild->rchild->lchild->data = '9';
    TT->lchild->rchild->lchild->lchild = TT->lchild->rchild->lchild->rchild = 0;
    TT->lchild->rchild->lchild->ltag = TT->lchild->rchild->lchild->rtag = 0;

    // ���Ĳ���ĸ��ڵ㡣
    TT->rchild->lchild->rchild = (TBTNode*)malloc(sizeof(TBTNode));
    TT->rchild->lchild->rchild->data = '0';
    TT->rchild->lchild->rchild->lchild = TT->rchild->lchild->rchild->rchild = 0;
    TT->rchild->lchild->rchild->ltag = TT->rchild->lchild->rchild->rtag = 0;

    //////////////////////////////////////////////////////////
    // �����������������
    printf("������������"); PreOrder(TT); printf("\n");

    // �����������������
    printf("������������"); InOrder(TT); printf("\n");

    // �������ĺ��������
    printf("������������"); PostOrder(TT); printf("\n");
    // ���ϱ����������Ĵ���Ҫ����������֮ǰ��
    //////////////////////////////////////////////////////////

    // ���������������������������
    CrtInThread(TT);

    printf("�������������������ұ��������"); InOrder1(TT); printf("\n");
    printf("�����������������ҵ�����������"); InOrder2(TT); printf("\n");

    return 0;
}