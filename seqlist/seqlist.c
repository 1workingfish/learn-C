#define _CRT_SECURE_NO_WARNINGS

#include "seqlist.h"

//初始化顺序表
void InitList(PSeqList LL)
{
	ClearList(LL);
}

//销毁顺序表
void DestroyList(PSeqList LL)
{
	return;
}

//在第ii个位置插入元素ee  返回值：0-失败 1-成功
int InsertList(PSeqList LL, int ii, ElemType* ee)
{
	if ((LL == NULL) || (ee == NULL))
	{
		return 0;
	}
	if (LL->length >= MAXSIZE) 
	{
		printf("顺序表已满，插入失败\n");
		return 0;
	}
	if ((ii < 1) || (ii > LL->length + 1))
	{
		printf("插入位置(%d)不合法，应该在（%d - %d）之间\n", ii, 1, LL->length + 1);
		return 0;
	}
	int i = 0;
	for (i = LL->length; i >= ii; i--)
	{
		memcpy(LL->date + i, LL->date + i - 1, sizeof(ElemType));
		//LL->date[i + 1] = LL->date[i];
	}
	//LL->date[ii] = ee;
	memcpy(LL->date + ii - 1, ee, sizeof(ElemType));
	(LL->length)++;
	return 1;
}

//在表头插入
int PushFront(PSeqList LL, ElemType* ee)
{
	return InsertList(LL, 1, ee);
}

//在表尾插入
int PushBack(PSeqList LL, ElemType* ee)
{
	return InsertList(LL, LL->length + 1, ee);
}

//求长度
int LengthList(PSeqList LL)
{
	return LL->length;
}

//获取元素
int GetElem(PSeqList LL,int ii, ElemType* ee)
{
	if ((LL == NULL) || (ee == NULL))
	{
		return 0;
	}
	if ((ii < 1) || (ii > LL->length + 1))
	{
		printf("输入位置（%d）不合法，应该在（%d - %d）之间\n", ii, 1, LL->length + 1);
		return 0;
	}
	memcpy(ee, LL->date+ii - 1, sizeof(ElemType));
	return 1;
}

//清空顺序表
void ClearList(PSeqList LL)
{
	if (LL == NULL)
	{
		return;
	}
	LL->length = 0;
	memset(LL->date, 0, sizeof(ElemType) * MAXSIZE);
}

//判断是否为空
int IsEmpty(PSeqList LL)
{
	if (LL == NULL)
	{
		return 0;
	}
	if (LL->length == 0)
	{
		return 1;
	}
	return 0;
}

//打印顺序表
void PrintfList(PSeqList LL)
{
	if (LL == NULL)
	{
		return;
	}
	if (LL->length == 0)
	{
		printf("顺序表为空\n");
	}
	int i = 0;
	for (i = 0; i < LL->length; i++)
	{
		printf("%-3d ", LL->date[i]);
	}
	printf("\n");
}

//查找ee在顺序表中的位置
int LocateList(PSeqList LL, ElemType* ee)
{
	if ((LL == NULL) || (ee == NULL))
	{
		return 0;
	}
	int i = 0;
	for (i = 0; i < LL->length; i++)
	{
		if (LL->date[i] == *ee)
		{
			return i + 1;
		}
	}
	return 0;
}

//删除第ii个元素
int DeleteElem(PSeqList LL, int ii)
{
	if (LL == NULL)
	{
		return 0;
	}
	if (ii<1 || ii>LL->length + 1)
	{
		printf("删除元素位置（%d）不合法，应该在（%d - %d）之间\n", ii, 1, LL->length);
	}
	int i = 0;
	for (i = ii; i < LL->length ; i++)
	{
		memcpy(LL->date+i-1, LL->date+i, sizeof(ElemType));
	}
	(LL->length)--;
	return 1;
}

//删除头元素
int PopFront(PSeqList LL)
{
	return DeleteElem(LL, 1);
}

//删除尾元素
int PopBack(PSeqList LL)
{
	return DeleteElem(LL, LL->length);
}

//归并  把两个升序表合并成一个
int MergeList(PSeqList La, PSeqList Lb, PSeqList Lc)
{
	if ((La == NULL) || (Lb == NULL) || (Lc == NULL))
	{
		return 0;
	}
	if (MAXSIZE < (La->length + Lb->length))
	{
		return 0;
	}

	int istartla = 0;  // 表La第一个元素的位置。
	int istartlb = 0;  // 表Lb第一个元素的位置。
	int istartlc = 0;  // 表Lc第一个元素的位置。

	// 把La和Lb合并到Lc中。
	while (istartla < La->length && istartlb < Lb->length)
	{
		Lc->date[istartlc++] = La->date[istartla] < Lb->date[istartlb] ? La->date[istartla++] : Lb->date[istartlb++];

	}
	// 把La其它的元素追加到Lc中。
	while (istartla < La->length)
	{
		Lc->date[istartlc++] = La->date[istartla++];
	}
	// 把Lb其它的元素追加到Lc中。
	while (istartlb < Lb->length)
	{
		Lc->date[istartlc++] = Lb->date[istartlb++];
	}
	Lc->length = La->length + Lb->length;
	return 1;
}