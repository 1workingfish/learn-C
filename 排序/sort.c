#define _CRT_SECURE_NO_WARNINGS

#include"Sort.h"
//ֱ�Ӳ������򣬾��ǵ�һ��Ԫ�ؿ�����һ������Ȼ�󲻶ϵ������в����µ�Ԫ��ֱ������
//����Ԫ��Խ��������Խ��
void InsertSort(SqList* s)
{
	if (s->length == 0)
	{
		printf("����Ϊ��\n");
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

//�۰��������,��ֱ������Ļ����ϲ��ҵķ�����ɶ��ֲ���
void BInsertSort(SqList* s)
{
	if (s->length == 0)
	{
		printf("����Ϊ��\n");
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

//ϣ��������С�������򣬻���ֱ�Ӳ�����������Ԫ��Խ���������ٶ�Խ�����һ���������鰴����������
//����ֱ�����һ�ε�����Ϊ1
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
		printf("����Ϊ��\n");
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

//ð����������Ԫ��֮����бȽϣ���������flag�鿴Ԫ���Ƿ��Ѿ��������
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


//�����������ùؼ��ִ�������Ҳ鿴�Ƿ���Ԫ�رȹؼ���С�����򽻻����ڴ˻����ϴ��������ҿ��Ƿ���Ԫ��
//�ȸý�����Ԫ��Ҫ����Ҳ������
//�ѹؼ��ַ����˳�ѭ����lowλ���ϣ�ʹ�����Ԫ�ض����ұ�Ԫ��ҪС��Ȼ������С�����ڽ��бȽϣ�ֱ��low<high
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
		printf("����Ϊ��\n");
		return;
	}
	if (s->length == 1)
	{
		return;
	}
	QSort(s, 1, s->length);
}

//��ѡ������ͬð��������ͬ������һ����������¼��СԪ�ص��±꣬Ȼ��ÿһ�ν��н���
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

//������ ,ai>a2i  ai>a2i+1 �����������ڵ�Ⱥ��ӽڵ��ֵҪ�󣨴���ѣ�
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

//�鲢����
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