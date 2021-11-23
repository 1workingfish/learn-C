#define _CRT_SECURE_NO_WARNINGS

#include"tree.h"

// ѭ������QQ�ĳ�ʼ��������
void InitQueue(PSeqQueue QQ)
{
	Clear(QQ);
}

// Ԫ����ӣ�����ֵ��0-ʧ�ܣ�1-�ɹ���
int InQueue(PSeqQueue QQ, ElemType* ee)
{
	if ((QQ == NULL) || (ee == NULL))
	{
		return 0;
	}
	if ((IsFull(QQ)) == 1)
	{
		printf("�������������ܲ���\n");
		return 0;
	}
	memcpy(QQ->data + QQ->rear, ee, sizeof(ElemType));
	QQ->rear = (QQ->rear + 1) % MAXSIZE;
	return 1;
}

// Ԫ�س��ӣ�����ֵ��0-ʧ�ܣ�1-�ɹ���
int OutQueue(PSeqQueue QQ, ElemType* ee)
{
	if ((QQ == NULL) || (ee == NULL))
	{
		return 0;
	}
	if (IsEmpty(QQ) == 1)
	{
		printf("����Ϊ��\n");
		return 0;
	}
	memcpy(ee, QQ->data + QQ->front, sizeof(ElemType));
	QQ->front = (QQ->front + 1) % MAXSIZE;
	return 1;
}

// ��ѭ�����еĳ��ȣ�����ֵ��>=0-����QQԪ�صĸ�����
int  Length(PSeqQueue QQ)
{
	if (QQ == NULL)
	{
		return 0;
	}
	return (QQ->rear - QQ->front + MAXSIZE) % MAXSIZE;
}

// ���ѭ�����С�
void Clear(PSeqQueue QQ)
{
	if (QQ == NULL)
	{
		return;
	}
	QQ->front = QQ->rear = 0;
	memset(QQ->data, 0, sizeof(ElemType) * MAXSIZE);
}

// �ж�ѭ�������Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ�ܡ�
int  IsEmpty(PSeqQueue QQ)
{
	if (QQ == NULL)
	{
		return 0;
	}
	if (QQ->front == QQ->rear)
	{
		return 1;
	}
	return 0;
}

// �ж�ѭ�������Ƿ�����������ֵ��1-������0-δ����ʧ�ܡ�
int IsFull(PSeqQueue QQ)
{
	if (QQ == NULL)
	{
		return 0;
	}
	if (((QQ->rear + 1) % MAXSIZE) == QQ->front)
	{
		return 1;
	}
	return 0;
}

// �������Ĳ�α�����
void LevelOrder(BiTree TT)
{
	SeqQueue QQ;     // ����ѭ�����С�

	InitQueue(&QQ);  // ��ʼ��ѭ�����С�

	ElemType ee = TT;  // ���е�Ԫ���Ƕ�������

	InQueue(&QQ, &ee);  // �Ѹ���㵱�ɶ��е�Ԫ����ӡ�

	while (IsEmpty(&QQ) != 1)  // ���в�Ϊ�ա�
	{
		OutQueue(&QQ, &ee);  // ��ͷԪ�س��ӡ�

		visit(ee);  // ���ʳ���Ԫ�ء�
		// �������Ԫ�������㣬������ӡ�
		if (ee->lchild != NULL)
		{
			InQueue(&QQ, &ee->lchild);
		}

		// �������Ԫ�����ҽ�㣬�ҽ����ӡ�
		if (ee->rchild != NULL)
		{
			InQueue(&QQ, &ee->rchild);
		}
		
	}
}

// ���ʳ���Ԫ��
void visit(BiTNode* pp)
{
	printf("%c ", pp->data);
}
	