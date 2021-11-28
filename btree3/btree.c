#define _CRT_SECURE_NO_WARNINGS

#include"btree.h"

int Insert(BSTree* TT, ElemType* ee)
{
	if ((*TT) == NULL)
	{
		*TT = (BSTree)malloc(sizeof(BSTNode));
		memcpy(&(*TT)->data, ee, sizeof(ElemType));
		(*TT)->lchild = (*TT)->rchild = NULL;
		return 1;
	}
	if (*ee == (*TT)->data)
	{
		return 0;
	}
	if ((*ee) < (*TT)->data)
	{
		Insert(&(*TT)->lchild, ee);
	}
	else
	{
		Insert(&(*TT)->rchild, ee);
	}
}

int Insert1(BSTree* TT, ElemType* ee)
{
	if ((*TT) == NULL)
	{
		(*TT) = (BSTree)malloc(sizeof(BSTNode));
		memcpy(&(*TT)->data, ee, sizeof(ElemType));
		(*TT)->lchild = (*TT)->rchild = NULL;
		return 1;
	}
	BSTNode* pss = NULL;
	BSTNode* ss = (*TT);
	int r1 = 0;
	while (ss != NULL)
	{
		if (*ee == ss->data)
		{
			return 0;
		}
		pss = ss;
		if (*ee < ss->data) 
		{
			ss = ss->lchild;
			r1 = 0;
		}
		else
		{
			ss = ss->rchild;
			r1 = 1;
		}
	}
	ss = (BSTree)malloc(sizeof(BSTNode));
	memcpy(&ss->data, ee, sizeof(ElemType));
	ss->lchild = ss->rchild = NULL;
	if (r1 == 0)
	{
		pss->lchild = ss;
	}
	else
	{
		pss->rchild = ss;
	}
	return 1;
}

void GreateBST(BSTree* TT, int* arr, int len)
{
	(*TT) = NULL;
	int i = 0;
	for (i = 0; i < len; i++)
	{
		Insert(TT, &arr[i]);
	}
}

BSTNode* Find(BSTree TT, ElemType* ee)
{
	if (TT == NULL)
	{
		return NULL;
	}
	if (*ee == TT->data)
	{
		return TT;
	}
	if (*ee < TT->data)
	{
		return Find(TT->lchild, ee);
	}
	else
	{
		return Find(TT->rchild, ee);
	}
}

BSTNode* Find1(BSTree TT, ElemType* ee)
{
	BSTNode* ss = TT;
	while (ss != NULL)
	{
		if (ss->data == *ee)
		{
			return ss;
		}
		if (*ee < ss->data)
		{
			ss = ss->lchild;
		}
		else
		{
			ss = ss->rchild;
		}
		return NULL;
	}
}

int Delete(BSTree* TT, ElemType* ee)
{
	if ((*TT) ==NULL)
	{
		return 1;
	}
	if (((*TT)->data == *ee) && ((*TT)->lchild == NULL) && ((*TT)->rchild == NULL))
	{
		free(*TT);
		(*TT) = 0;
		return 0;
	}
	BSTNode* pss = NULL;
	BSTNode* ss = (*TT);
	int r1 = 0;
	while (ss != NULL)
	{
		if (*ee == ss->data)break;
		pss = ss;
		if (*ee < ss->data)
		{
			ss = ss->lchild;
			r1 = 0;
		}
		else
		{
			ss = ss->rchild;
			r1 = 1;
		}
	}
	if (ss == NULL)
	{
		return 1;
	}
	if ((ss->lchild == NULL) && (ss->rchild == NULL))
	{
		free(ss);
		if (r1 == 0)
		{
			pss->lchild = NULL;
		}
		else
		{
			pss->rchild = NULL;
		}
		return 0;
	}
	if ((ss->lchild == NULL) || (ss->rchild == NULL))
	{
		if (ss->lchild != NULL)
		{
			if (r1 == 0)
			{
				pss->lchild = ss->lchild;
			}
			else
			{
				pss->rchild = ss->lchild;
			}
		}
		else
		{
			if (r1 == 0)
			{
				pss->lchild = ss->rchild;
			}
			else
			{
				pss->rchild = ss->rchild;
			}
		}
		return 0;
	}
	BSTNode* pss1 = ss;
	BSTNode* ss1 = ss->lchild;
	int r11 = 0;
	while (ss1->rchild != NULL)
	{
		r11 = 1;
		pss1 = ss1;
		ss1 = ss1->rchild;
	}
	memcpy(&ss->data, &ss1->data, sizeof(ElemType));
	if (r11 == 0)
	{
		pss1->lchild = ss1->lchild;
	}
	else
	{
		pss1->rchild = ss1->lchild;
	}
	free(ss1);
	return 0;
}

int TreeDepth(BSTree TT)
{
	if (TT == NULL)
	{
		return 0;
	}
	int left = TreeDepth(TT->lchild);
	int rigth = TreeDepth(TT->rchild);
	return left > rigth ? left + 1 : rigth + 1;
}

void visit(BSTree TT)
{
	printf("%d ", TT->data);
}

void PreOrder(BSTree TT)
{
	if (TT == NULL)
	{
		return;
	}
	visit(TT);
	PreOrder(TT->lchild);
	PreOrder(TT->rchild);
}

void InOrder(BSTree TT)
{
	if (TT == NULL)
	{
		return;
	}
	InOrder(TT->lchild);
	visit(TT);
	InOrder(TT->rchild);
}

void PostOrder(BSTree TT)
{
	if (TT == NULL)
	{
		return;
	}
	PostOrder(TT->lchild);
	PostOrder(TT->rchild);
	visit(TT);
}