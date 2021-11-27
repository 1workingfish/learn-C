#define _CRT_SECURE_NO_WARNINGS

#include"btree.h"

int main()
{
    TBTTree TT = 0; // 声明树指针变量。

     /*
     // 手工构造一个如下结构的二叉树。
                1
             /     \
            2       3
           / \     /
          4   5   6
         / \ /   /
        7  8 9  0
     */

     // 分配根节点。
    TT = (TBTNode*)malloc(sizeof(TBTNode));
    TT->data = '1';
    TT->lchild = TT->rchild = 0;
    TT->ltag = TT->rtag = 0;

    // 第二层第一个节点。
    TT->lchild = (TBTNode*)malloc(sizeof(TBTNode));
    TT->lchild->data = '2';
    TT->lchild->lchild = TT->lchild->rchild = 0;
    TT->lchild->ltag = TT->lchild->rtag = 0;

    // 第二层第二个节点。
    TT->rchild = (TBTNode*)malloc(sizeof(TBTNode));
    TT->rchild->data = '3';
    TT->rchild->lchild = TT->rchild->rchild = 0;
    TT->rchild->ltag = TT->rchild->rtag = 0;

    // 第三层第一个节点。
    TT->lchild->lchild = (TBTNode*)malloc(sizeof(TBTNode));
    TT->lchild->lchild->data = '4';
    TT->lchild->lchild->lchild = TT->lchild->lchild->rchild = 0;
    TT->lchild->lchild->ltag = TT->lchild->lchild->rtag = 0;

    // 第三层第二个节点。
    TT->lchild->rchild = (TBTNode*)malloc(sizeof(TBTNode));
    TT->lchild->rchild->data = '5';
    TT->lchild->rchild->lchild = TT->lchild->rchild->rchild = 0;
    TT->lchild->rchild->ltag = TT->lchild->rchild->rtag = 0;

    // 第三层第三个节点。
    TT->rchild->lchild = (TBTNode*)malloc(sizeof(TBTNode));
    TT->rchild->lchild->data = '6';
    TT->rchild->lchild->lchild = TT->rchild->lchild->rchild = 0;
    TT->rchild->lchild->ltag = TT->rchild->lchild->rtag = 0;

    // 第四层第一个节点。
    TT->lchild->lchild->lchild = (TBTNode*)malloc(sizeof(TBTNode));
    TT->lchild->lchild->lchild->data = '7';
    TT->lchild->lchild->lchild->lchild = TT->lchild->lchild->lchild->rchild = 0;
    TT->lchild->lchild->lchild->ltag = TT->lchild->lchild->lchild->rtag = 0;

    // 第四层第二个节点。
    TT->lchild->lchild->rchild = (TBTNode*)malloc(sizeof(TBTNode));
    TT->lchild->lchild->rchild->data = '8';
    TT->lchild->lchild->rchild->lchild = TT->lchild->lchild->rchild->rchild = 0;
    TT->lchild->lchild->rchild->ltag = TT->lchild->lchild->rchild->rtag = 0;

    // 第四层第三个节点。
    TT->lchild->rchild->lchild = (TBTNode*)malloc(sizeof(TBTNode));
    TT->lchild->rchild->lchild->data = '9';
    TT->lchild->rchild->lchild->lchild = TT->lchild->rchild->lchild->rchild = 0;
    TT->lchild->rchild->lchild->ltag = TT->lchild->rchild->lchild->rtag = 0;

    // 第四层第四个节点。
    TT->rchild->lchild->rchild = (TBTNode*)malloc(sizeof(TBTNode));
    TT->rchild->lchild->rchild->data = '0';
    TT->rchild->lchild->rchild->lchild = TT->rchild->lchild->rchild->rchild = 0;
    TT->rchild->lchild->rchild->ltag = TT->rchild->lchild->rchild->rtag = 0;

    //////////////////////////////////////////////////////////
    // 二叉树的先序遍历。
    printf("先序遍历结果："); PreOrder(TT); printf("\n");

    // 二叉树的中序遍历。
    printf("中序遍历结果："); InOrder(TT); printf("\n");

    // 二叉树的后序遍历。
    printf("后序遍历结果："); PostOrder(TT); printf("\n");
    // 以上遍历二叉树的代码要放在线索化之前。
    //////////////////////////////////////////////////////////

    // 中序遍历二叉树线索化主函数。
    CrtInThread(TT);

    printf("中序线索二叉树从左到右遍历结果："); InOrder1(TT); printf("\n");
    printf("中序线索二叉树从右到左遍历结果："); InOrder2(TT); printf("\n");

    return 0;
}