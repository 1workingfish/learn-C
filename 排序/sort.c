#define _CRT_SECURE_NO_WARNINGS

#include"Sort.h"
//直接插入排序，就是第一个元素看成是一个数组然后不断的像其中插入新的元素直至有序，
//数组元素越有序排序越快
void InsertSort(SqList* s)
{
	if (s->length == 0)
	{
		printf("数组为空\n");
		return;
	}
	if (s->length == 1)
	{
		return;
	}
	for (int i = 2; i <= s->length ; i++)
	{
		if (s->r[i].key < s->r[i - 1].key)
		{
			s->r[0] = s->r[i];
			s->r[i] = s->r[i - 1];
			int j;
			for (j = i - 2; s->r[0].key < s->r[j].key; j--)
			{
				s->r[j + 1] = s->r[j];
			}
			s->r[j + 1] = s->r[0];
		}
	}
}

//折半插入排序,在直接排序的基础上查找的方法变成二分查找
void BInsertSort(SqList* s)
{
	if (s->length == 0)
	{
		printf("数组为空\n");
		return;
	}
	if (s->length == 1)
	{
		return;
	}
	for (int i = 2; i <= s->length; i++)
	{
		s->r[0] = s->r[i];
		int low = 1;
		int high = i - 1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (s->r[0].key < s->r[mid].key)
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		for (int j = i - 1; j >= high + 1; j--)
		{
			s->r[j + 1] = s->r[j];
		}
		s->r[high + 1] = s->r[0];
	}
}

//希尔排序，缩小增量排序，基于直接插入排序数组元素越有序排序速度越快给定一个增量数组按照增量进行
//排序直至最后一次的增量为1
void ShellInsert(SqList* s,int dk)
{
	for (int i = dk + 1; i <= s->length; i ++)
	{
		if (s->r[i].key < s->r[i - dk].key)
		{
			s->r[0] = s->r[i];

			int j;
			for (j = i - dk; j > 0 && s->r[0].key < s->r[j].key; j -= dk)
			{
				s->r[j + dk] = s->r[j];
			}
			s->r[j + dk] = s->r[0];
		}
	}
}

void ShellSort(SqList* s, int dk[], int t)
{
	if (s->length == 0)
	{
		printf("数组为空\n");
		return;
	}
	if (s->length == 1)
	{
		return;
	}
	for (int i = 0; i < t; i++)
	{
		ShellInsert(s, dk[i]);
	}
}

//冒泡排序，两两元素之间进行比较，并设置了flag查看元素是否已经排序过了
void BubbleSort(SqList* s)
{
	int len = s->length - 1;
	int flag = 1;
	while ((len > 0) && (flag == 1))
	{
		flag = 0;
		for (int i = 1; i <= len; i++)
		{
			if (s->r[i].key > s->r[i + 1].key)
			{
				flag = 1;
				RedType tmp = s->r[i];
				s->r[i] = s->r[i + 1];
				s->r[i + 1] = tmp;
			}			
		}
		len--;
	}
}


//快速排序，设置关键字从左边向右查看是否有元素比关键字小，有则交换，在此基础上从右向左找看是否有元素
//比该交换的元素要大，有也交换。
//把关键字放在退出循坏的low位置上，使得左边元素都比右边元素要小，然后两个小数组在进行比较，直至low<high
int Partition(SqList* s, int low, int high)
{
	s->r[0] = s->r[low];
	int pivotkey = s->r[low].key;
	while (low < high)
	{
		while (low < high && s->r[high].key >= pivotkey)
		{
			--high;
		}
		s->r[low] = s->r[high];
		while (low < high && s->r[low].key <= pivotkey)
		{
			++low;
		}
		s->r[high] = s->r[low];
	}
	s->r[low] = s->r[0];
	return low;
}

void QSort(SqList* s, int low, int high)
{
	if (low < high)
	{
		int pivotloc = Partition(s, low, high);
		QSort(s, low, pivotloc - 1);
		QSort(s, pivotloc + 1, high);
	}
}

void QuickSort(SqList* s)
{
	if (s->length == 0)
	{
		printf("数组为空\n");
		return;
	}
	if (s->length == 1)
	{
		return;
	}
	QSort(s, 1, s->length);
}

//简单选择排序，同冒泡排序相同，设置一个变量来纪录最小元素的下标，然后每一次进行交换
void SelectSort(SqList* s)
{
	for (int i = 1; i < s->length; i++)
	{
		int k = i;
		for (int j = i + 1; j <= s->length; j++)
		{
			if (s->r[i].key > s->r[j].key)
			{
				k = j;
			}
		}
		if (k != i)
		{
			RedType tmp = s->r[i];
			s->r[i] = s->r[k];
			s->r[k] = tmp;
		}
	}
}

//堆排序 ,ai>a2i  ai>a2i+1 就是树，根节点比孩子节点的值要大（大根堆）
void HeapAdjust(SqList* s, int n, int m)
{
	RedType rc = s->r[n];
	for (int i = 2 * n; i <= m; i *= 2)
	{
		if (i < m && s->r[i].key < s->r[i + 1].key)
		{
			i++;
		}
		if (rc.key >= s->r[i].key)
		{
			break;
		}
		s->r[n] = s->r[i];
		n = i;
	}
	s->r[n] = rc;
}

void CreatHeap(SqList* s)
{
	int n = s->length;
	for (int i = n / 2; i > 0; i--)
	{
		HeapAdjust(s, i, n);
	}
}

void HeapSort(SqList* s)
{
	CreatHeap(s);
	for (int i = s->length; i > 1; i--)
	{
		RedType x = s->r[1];
		s->r[1] = s->r[i];
		s->r[i] = x;
		HeapAdjust(s, 1, i - 1);
	}
}

//归并排序
//void Merge(RedType R[], RedType T[], int low, int mid, int high)
//{
//	int i = low;
//	int j = mid + 1;
//	int k = low;
//	while (i <= mid && j <= high)
//	{
//		if (R[i].key <= R[j].key)
//		{
//			T[k++] = R[i++];
//		}
//		else
//		{
//			T[k++] = R[j++];
//		}
//	}
//	while (i <= mid)
//	{
//		T[k++] = R[i++];
//	}
//	while (j <= high)
//	{
//		T[k++] = R[j++];
//	}
//}
//
//void MSort(RedType R[], RedType T[], int low, int high)
//{
//	if (low == high)
//	{
//		R[low] = T[low];
//	}
//	else
//	{
//		int mid = (low + high) / 2;
//		MSort(R, T, low, mid);
//		MSort(R, T, mid + 1, high);
//		Merge(R, T, low, mid, high);
//	}
//}
//
//void MergeSort(SqList* s)
//{
//	MSort(s->r, s->r, 1, s->length);
//}