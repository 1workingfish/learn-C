#define _CRT_SECURE_NO_WARNINGS

#include"btree.h"

void InitStack(PSeqstack SS)
{
	Clear(SS);
}

void Clear(PSeqstack SS)
{
	if (SS == NULL)
	{
		return;
	}
	memset(SS->date, 0, sizeof(ElemType)*MAXSIZE);
	SS->top = -1;
}

int Length(PSeqstack SS)
{
	if (SS == NULL)
	{
		return 0;
	}
	return SS->top + 1;
}

int Is_Full(PSeqstack SS)
{
	if (SS == NULL)
	{
		return 0;
	}
	if (SS->top == MAXSIZE-1)
	{
		return 1;
	}
	return 0;
}

int Is_Empty(PSeqstack SS)
{
	if (SS == NULL)
	{
		return 0;
	}
	if (SS->top == -1)
	{
		return 1;
	}
	return 0;
}

int Push(PSeqstack SS, ElemType* ee)
{
	if ((SS == NULL) || (ee == NULL))
	{
		return 0;
	}
	if (Is_Full(SS) == 1)
	{
		printf("Õ»¿Õ¼äÒÑÂú,ÈëÕ»Ê§°Ü\n");
		return 0;
	}
	 (SS->top)++;
	memcpy(SS->date+SS->top, ee, sizeof(ElemType));
	return 1;
}

int Pop(PSeqstack SS, ElemType* ee)
{
	if ((SS == NULL) || (ee == NULL))
	{
		return 0;
	}
	if (SS->top == -1)
	{
		printf("Õ»Îª¿Õ£¬³öÕ»Ê§°Ü\n");
		return 0;
	}
	memcpy(ee, SS->date + SS->top, sizeof(ElemType));
	(SS->top)--;
	return 1;
}

void PrintfStack(PSeqstack SS)
{
	if (SS == NULL)
	{
		return ;
	}
	if (SS->top == -1)
	{
		printf("Õ»Îª¿Õ\n");
		return ;
	}
	int i = 0;
	int len = Length(SS);
	for (i = 0; i < len; i++)
	{
		printf("SS[%d],value:%d\n", i, SS->date[i]);
	}
}

int GetTop(PSeqstack SS, ElemType* ee)
{
	if ((SS == NULL) || (ee == NULL))
	{
		return 0;
	}
	if (SS->top == -1)
	{
		printf("Õ»Îª¿Õ\n");
		return 0;
	}
	memcpy(ee, SS->date + SS->top, sizeof(ElemType));
	return 1;
}

void visit(BiTree TT)
{
	printf("%c ", TT->data);
}

void PreOrder(BiTree TT)
{
	if (TT == NULL)
	{
		return;
	}
	visit(TT);
	PreOrder(TT->lchild);
	PreOrder(TT->rchild);
}

void InOrder(BiTree TT)
{
	if (TT == NULL)
	{
		return;
	}
	InOrder(TT->lchild);
	visit(TT);
	InOrder(TT->rchild);
}

void PostOrder(BiTree TT)
{
	if (TT == NULL)
	{
		return;
	}
	PostOrder(TT->lchild);
	PostOrder(TT->rchild);
	visit(TT);
}

void PreOrder1(BiTree TT)
{
	Seqstack SS; 

	InitStack(&SS);

	ElemType ee = TT;

	while ((ee != NULL) || (Is_Empty(&SS) != 1))
	{
		if (ee != NULL)
		{
			visit(ee);
			Push(&SS, &ee);
			ee = ee->lchild;
		}
		else
		{
			Pop(&SS, &ee);
			ee = ee->rchild;
		}
	}
}

void InOrder1(BiTree TT)
{
	Seqstack SS;
	InitStack(&SS);
	ElemType ee = TT;
	while ((ee != NULL) || (Is_Empty(&SS) != 1))
	{
		if (ee != NULL)
		{
			Push(&SS, &ee);
			ee = ee->lchild;
		}
		else
		{
			Pop(&SS, &ee);
			visit(ee);
			ee = ee->rchild;
		}
	}
}
void PostOrder1(BiTree TT)
{
	Seqstack SS;    

	InitStack(&SS);   

	ElemType ee = TT;   

	ElemType pp = NULL;

	while ((ee != NULL) || (Is_Empty(&SS) != 1))
	{
		if (ee != NULL)   
		{
			Push(&SS, &ee);
			ee = ee->lchild;
		}
		else   
		{
			GetTop(&SS, &ee);

			if ((ee->rchild != NULL) && (ee->rchild != pp))
			{
				ee = ee->rchild;  
				Push(&SS, &ee);  
				ee = ee->lchild;  
			}
			else
			{
				Pop(&SS, &ee);  
				visit(ee);   
				pp = ee;        
				ee = NULL;      
			}
		}
	}
}

int TreeDepth(BiTree TT)
{
	if (TT == NULL)
	{
		return 0;
	}
	int left = TreeDepth(TT->lchild);
	int rigth = TreeDepth(TT->rchild);

	return left > rigth ? left + 1 : rigth + 1;
}