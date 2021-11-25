#define _CRT_SECURE_NO_WARNINGS

#include"btree.h"

int main()
{
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
    BiTree TT = 0;

    //������ڵ�
    TT = (BiTNode*)malloc(sizeof(BiTNode));
    TT->data = '1';
    TT->lchild = TT->rchild = 0;
    //�����һ������
    TT->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    TT->lchild->data = '2';
    TT->lchild->lchild = TT->lchild->rchild = 0;
    //�����һ���ҽ��
    TT->rchild = (BiTNode*)malloc(sizeof(BiTNode));
    TT->rchild->data = '3';
    TT->rchild->lchild = TT->rchild->rchild = 0;
    //�ڶ����һ�����
    TT->lchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    TT->lchild->lchild->data = '4';
    TT->lchild->lchild->lchild = TT->lchild->lchild->rchild = 0;
    //�ڶ���ڶ������
    TT->lchild->rchild = (BiTNode*)malloc(sizeof(BiTNode));
    TT->lchild->rchild->data = '5';
    TT->lchild->rchild->lchild = TT->lchild->rchild->rchild = 0;
    //�ڶ�����������
    TT->rchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    TT->rchild->lchild->data = '6';
    TT->rchild->lchild->lchild = TT->rchild->lchild->rchild = 0;
    //�������һ�����
    TT->lchild->lchild->lchild= (BiTNode*)malloc(sizeof(BiTNode));
    TT->lchild->lchild->lchild->data = '7';
    TT->lchild->lchild->lchild->lchild = TT->lchild->lchild->lchild->rchild = 0;
    //������ڶ������
    TT->lchild->lchild->rchild = (BiTNode*)malloc(sizeof(BiTNode));
    TT->lchild->lchild->rchild->data = '8';
    TT->lchild->lchild->rchild->lchild = TT->lchild->lchild->rchild->rchild = 0;
    //��������������
    TT->lchild->rchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    TT->lchild->rchild->lchild->data = '9';
    TT->lchild->rchild->lchild->lchild = TT->lchild->rchild->lchild->rchild = 0;
    //��������ĸ����
    TT->lchild->rchild->rchild = (BiTNode*)malloc(sizeof(BiTNode));
    TT->lchild->rchild->rchild->data = '0';
    TT->lchild->rchild->rchild->lchild = TT->lchild->rchild->rchild->rchild = 0;

    // �����������������
    printf("����������1��"); PreOrder(TT); printf("\n");
    printf("����������2��"); PreOrder1(TT); printf("\n");

    // �����������������
    printf("����������1��"); InOrder(TT); printf("\n");
    printf("����������2��"); InOrder1(TT); printf("\n");

    // �������ĺ��������
    printf("����������1��"); PostOrder(TT); printf("\n");
    printf("����������2��"); PostOrder1(TT); printf("\n");


    // ��������ĸ߶ȡ�
    printf("���ĸ߶��ǣ�%d\n", TreeDepth(TT));
	return 0;
}
