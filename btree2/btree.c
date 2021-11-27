#define _CRT_SECURE_NO_WARNINGS

#include"btree.h"

void visit(TBTTree TT)
{
	printf("%c ", TT->data);
}

void PreOrder(TBTTree TT)
{
	if (TT == NULL)
	{
		return;
	}
	visit(TT);
	PreOrder(TT->lchild);
	PreOrder(TT->rchild);
}

void InOrder(TBTTree TT)
{
	if (TT == NULL)
	{
		return;
	}
	InOrder(TT->lchild);
	visit(TT);
	InOrder(TT->rchild);
}

void PostOrder(TBTTree TT)
{
	if (TT == NULL)
	{
		return;
	}
	PostOrder(TT->lchild);
	PostOrder(TT->rchild);
	visit(TT);
}

void InThread(TBTTree TT, TBTTree *pre)
{
	if (TT == NULL)
	{
		return;
	}
	InThread(TT->lchild, pre);
	if (TT->lchild == NULL)
	{
		TT->ltag = 1;
		TT->lchild = *pre;
	}
	printf("%c ", TT->data);
	if (((*pre) != NULL) && ((*pre)->rchild == NULL))
	{
		(*pre)->rtag = 1;
		(*pre)->rchild =TT;
	}
	*pre = TT;
	InThread(TT->rchild, pre);
}

void CrtInThread(TBTTree TT)
{
	if (TT == NULL)
	{
		return;
	}
	TBTNode *pre = NULL;
	InThread(TT, &pre);
	pre->rchild = NULL;
	pre->rtag = 1;
	printf("线索化完成\n");
}

TBTNode* FirstNode(TBTTree TT)
{
	while (TT->ltag == 0)
	{
		TT = TT->lchild;
	}
	return TT;
}

TBTNode* NextNode(TBTNode* pp)
{
	if (pp->rtag == 0)
	{
		return FirstNode(pp->rchild);
	}
	else
	{
		return pp->rchild;
	}
}

void InOrder1(TBTTree TT)
{
	TBTNode* pp = FirstNode(TT);
	while (pp != NULL)
	{
		visit(pp);
		pp = NextNode(pp);
	}
}

TBTNode* LastNode(TBTTree TT)
{
	while (TT->rtag == 0)
	{
		TT = TT->rchild;
	}
	return TT;
}

TBTNode* PriorNode(TBTNode* pp)
{
	if (pp->ltag == 0)
	{

		return LastNode(pp->lchild);
	}
	else
	{
		return pp->lchild;
	}
}

void InOrder2(TBTTree TT)
{
	TBTNode* pp = LastNode(TT);
	while (pp != NULL)
	{
		visit(pp);
		pp = PriorNode(pp);
	}
}