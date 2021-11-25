#define _CRT_SECURE_NO_WARNINGS

#include"btree.h"

int main()
{
    /*
// 手工构造一个如下结构的二叉树。
           1
        /     \
       2       3
      / \     /
     4   5   6
    / \ / \
   7  8 9  0
*/
    BiTree TT = 0;

    //分配根节点
    TT = (BiTNode*)malloc(sizeof(BiTNode));
    TT->data = '1';
    TT->lchild = TT->rchild = 0;
    //分配第一个左结点
    TT->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    TT->lchild->data = '2';
    TT->lchild->lchild = TT->lchild->rchild = 0;
    //分配第一个右结点
    TT->rchild = (BiTNode*)malloc(sizeof(BiTNode));
    TT->rchild->data = '3';
    TT->rchild->lchild = TT->rchild->rchild = 0;
    //第二层第一个结点
    TT->lchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    TT->lchild->lchild->data = '4';
    TT->lchild->lchild->lchild = TT->lchild->lchild->rchild = 0;
    //第二层第二个结点
    TT->lchild->rchild = (BiTNode*)malloc(sizeof(BiTNode));
    TT->lchild->rchild->data = '5';
    TT->lchild->rchild->lchild = TT->lchild->rchild->rchild = 0;
    //第二层第三个结点
    TT->rchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    TT->rchild->lchild->data = '6';
    TT->rchild->lchild->lchild = TT->rchild->lchild->rchild = 0;
    //第三层第一个结点
    TT->lchild->lchild->lchild= (BiTNode*)malloc(sizeof(BiTNode));
    TT->lchild->lchild->lchild->data = '7';
    TT->lchild->lchild->lchild->lchild = TT->lchild->lchild->lchild->rchild = 0;
    //第三层第二个结点
    TT->lchild->lchild->rchild = (BiTNode*)malloc(sizeof(BiTNode));
    TT->lchild->lchild->rchild->data = '8';
    TT->lchild->lchild->rchild->lchild = TT->lchild->lchild->rchild->rchild = 0;
    //第三层第三个结点
    TT->lchild->rchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    TT->lchild->rchild->lchild->data = '9';
    TT->lchild->rchild->lchild->lchild = TT->lchild->rchild->lchild->rchild = 0;
    //第三层第四个结点
    TT->lchild->rchild->rchild = (BiTNode*)malloc(sizeof(BiTNode));
    TT->lchild->rchild->rchild->data = '0';
    TT->lchild->rchild->rchild->lchild = TT->lchild->rchild->rchild->rchild = 0;

    // 二叉树的先序遍历。
    printf("先序遍历结果1："); PreOrder(TT); printf("\n");
    printf("先序遍历结果2："); PreOrder1(TT); printf("\n");

    // 二叉树的中序遍历。
    printf("中序遍历结果1："); InOrder(TT); printf("\n");
    printf("中序遍历结果2："); InOrder1(TT); printf("\n");

    // 二叉树的后序遍历。
    printf("后序遍历结果1："); PostOrder(TT); printf("\n");
    printf("后序遍历结果2："); PostOrder1(TT); printf("\n");


    // 求二叉树的高度。
    printf("树的高度是：%d\n", TreeDepth(TT));
	return 0;
}
