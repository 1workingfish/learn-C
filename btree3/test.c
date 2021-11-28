#define _CRT_SECURE_NO_WARNINGS

#include"btree.h"

int main()
{
    BSTree TT = 0; // 声明树指针变量。

    ElemType arr[] = { 50,66,60,26,21,30,70,68 };

    /*
    // 用数组arr中的序列构建二叉排序树TT。
    // 构建的二叉排序树将如下：
                50
             /     \
            26      66
           /  \    /  \
          21  30 60   70
                     /
                    68
    */
    GreateBST(&TT, arr, sizeof(arr) / sizeof(ElemType));

    ElemType ee;

    // 在树TT中查找值为ee的结点，成功返回结点的地址，失败返回NULL。
    ee = 30;
    BSTNode* ss = Find(TT, &ee);
    if (ss != NULL) printf("查找成功，结点的地址是%p，值是%d。\n", ss, ss->data);
    else printf("查找失败。\n");

    // 二叉树的中序遍历。
    printf("中序遍历结果1："); InOrder(TT); printf("\n");

    // 在树TT中删除值为ee的结点，成功返回0，结点不存在返回1。
    ee = 50;
    printf("从树中删除值为ee的结点，Delete()的返回值是%d。\n", Delete(&TT, &ee));

    // 二叉树的中序遍历。
    printf("中序遍历结果2："); InOrder(TT); printf("\n");

    return 0;
	return 0;
}