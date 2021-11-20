#define _CRT_SECURE_NO_WARNINGS

#include "seqlist.h"

//��ʼ��˳���
void InitList(PSeqList LL)
{
	ClearList(LL);
}

//����˳���
void DestroyList(PSeqList LL)
{
	return;
}

//�ڵ�ii��λ�ò���Ԫ��ee  ����ֵ��0-ʧ�� 1-�ɹ�
int InsertList(PSeqList LL, int ii, ElemType* ee)
{
	if ((LL == NULL) || (ee == NULL))
	{
		return 0;
	}
	if (LL->length >= MAXSIZE) 
	{
		printf("˳�������������ʧ��\n");
		return 0;
	}
	if ((ii < 1) || (ii > LL->length + 1))
	{
		printf("����λ��(%d)���Ϸ���Ӧ���ڣ�%d - %d��֮��\n", ii, 1, LL->length + 1);
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

//�ڱ�ͷ����
int PushFront(PSeqList LL, ElemType* ee)
{
	return InsertList(LL, 1, ee);
}

//�ڱ�β����
int PushBack(PSeqList LL, ElemType* ee)
{
	return InsertList(LL, LL->length + 1, ee);
}

//�󳤶�
int LengthList(PSeqList LL)
{
	return LL->length;
}

//��ȡԪ��
int GetElem(PSeqList LL,int ii, ElemType* ee)
{
	if ((LL == NULL) || (ee == NULL))
	{
		return 0;
	}
	if ((ii < 1) || (ii > LL->length + 1))
	{
		printf("����λ�ã�%d�����Ϸ���Ӧ���ڣ�%d - %d��֮��\n", ii, 1, LL->length + 1);
		return 0;
	}
	memcpy(ee, LL->date+ii - 1, sizeof(ElemType));
	return 1;
}

//���˳���
void ClearList(PSeqList LL)
{
	if (LL == NULL)
	{
		return;
	}
	LL->length = 0;
	memset(LL->date, 0, sizeof(ElemType) * MAXSIZE);
}

//�ж��Ƿ�Ϊ��
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

//��ӡ˳���
void PrintfList(PSeqList LL)
{
	if (LL == NULL)
	{
		return;
	}
	if (LL->length == 0)
	{
		printf("˳���Ϊ��\n");
	}
	int i = 0;
	for (i = 0; i < LL->length; i++)
	{
		printf("%-3d ", LL->date[i]);
	}
	printf("\n");
}

//����ee��˳����е�λ��
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

//ɾ����ii��Ԫ��
int DeleteElem(PSeqList LL, int ii)
{
	if (LL == NULL)
	{
		return 0;
	}
	if (ii<1 || ii>LL->length + 1)
	{
		printf("ɾ��Ԫ��λ�ã�%d�����Ϸ���Ӧ���ڣ�%d - %d��֮��\n", ii, 1, LL->length);
	}
	int i = 0;
	for (i = ii; i < LL->length ; i++)
	{
		memcpy(LL->date+i-1, LL->date+i, sizeof(ElemType));
	}
	(LL->length)--;
	return 1;
}

//ɾ��ͷԪ��
int PopFront(PSeqList LL)
{
	return DeleteElem(LL, 1);
}

//ɾ��βԪ��
int PopBack(PSeqList LL)
{
	return DeleteElem(LL, LL->length);
}

//�鲢  �����������ϲ���һ��
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

	int istartla = 0;  // ��La��һ��Ԫ�ص�λ�á�
	int istartlb = 0;  // ��Lb��һ��Ԫ�ص�λ�á�
	int istartlc = 0;  // ��Lc��һ��Ԫ�ص�λ�á�

	// ��La��Lb�ϲ���Lc�С�
	while (istartla < La->length && istartlb < Lb->length)
	{
		Lc->date[istartlc++] = La->date[istartla] < Lb->date[istartlb] ? La->date[istartla++] : Lb->date[istartlb++];

	}
	// ��La������Ԫ��׷�ӵ�Lc�С�
	while (istartla < La->length)
	{
		Lc->date[istartlc++] = La->date[istartla++];
	}
	// ��Lb������Ԫ��׷�ӵ�Lc�С�
	while (istartlb < Lb->length)
	{
		Lc->date[istartlc++] = Lb->date[istartlb++];
	}
	Lc->length = La->length + Lb->length;
	return 1;
}