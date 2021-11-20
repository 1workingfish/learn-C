#define _CRT_SECURE_NO_WARNINGS

#include "seqlist.h"

int main()
{/*
	SeqList LL;
	ElemType ee;
	InitList(&LL);
	ee = 10;
	InsertList(&LL, 1, &ee);	
	ee = 9;
	InsertList(&LL, 1, &ee);	
	ee = 8;
	InsertList(&LL, 1, &ee);	
	ee = 7;
	InsertList(&LL, 1, &ee);	
	ee = 6;
	InsertList(&LL, 1, &ee);	
	ee = 5;
	InsertList(&LL, 1, &ee);	
	ee = 4;
	InsertList(&LL, 1, &ee);	
	ee = 3;
	InsertList(&LL, 1, &ee);	
	ee = 2;
	InsertList(&LL, 1, &ee);	
	ee = 1;
	InsertList(&LL, 1, &ee);	
	ee = 0;
	InsertList(&LL, 1, &ee);	
	PrintfList(&LL);*/

	SeqList La;
	SeqList Lb;
	SeqList Lc;
	ElemType ee;
	InitList(&La);
	InitList(&Lb);
	InitList(&Lc);
	ee = 10;
	InsertList(&La, 1, &ee);
	ee = 9;
	InsertList(&Lb, 1, &ee);
	ee = 8;
	InsertList(&Lb, 1, &ee);
	ee = 7;
	InsertList(&Lb, 1, &ee);
	ee = 6;
	InsertList(&La, 1, &ee);
	ee = 5;
	InsertList(&Lb, 1, &ee);
	ee = 4;
	InsertList(&La, 1, &ee);
	ee = 3;
	InsertList(&Lb, 1, &ee);
	ee = 2;
	InsertList(&La, 1, &ee);
	ee = 1;
	InsertList(&Lb, 1, &ee);
	PrintfList(&La);
	PrintfList(&Lb);
	MergeList(&La, &Lb, &Lc);
	PrintfList(&Lc);
	return 0;
}