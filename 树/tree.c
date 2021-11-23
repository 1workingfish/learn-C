#define _CRT_SECURE_NO_WARNINGS

#include"tree.h"

// 循环队列QQ的初始化操作。
void InitQueue(PSeqQueue QQ)
{
	Clear(QQ);
}

// 元素入队，返回值：0-失败；1-成功。
int InQueue(PSeqQueue QQ, ElemType* ee)
{
	if ((QQ == NULL) || (ee == NULL))
	{
		return 0;
	}
	if ((IsFull(QQ)) == 1)
	{
		printf("队列已满，不能插入\n");
		return 0;
	}
	memcpy(QQ->data + QQ->rear, ee, sizeof(ElemType));
	QQ->rear = (QQ->rear + 1) % MAXSIZE;
	return 1;
}

// 元素出队，返回值：0-失败；1-成功。
int OutQueue(PSeqQueue QQ, ElemType* ee)
{
	if ((QQ == NULL) || (ee == NULL))
	{
		return 0;
	}
	if (IsEmpty(QQ) == 1)
	{
		printf("队列为空\n");
		return 0;
	}
	memcpy(ee, QQ->data + QQ->front, sizeof(ElemType));
	QQ->front = (QQ->front + 1) % MAXSIZE;
	return 1;
}

// 求循环队列的长度，返回值：>=0-队列QQ元素的个数。
int  Length(PSeqQueue QQ)
{
	if (QQ == NULL)
	{
		return 0;
	}
	return (QQ->rear - QQ->front + MAXSIZE) % MAXSIZE;
}

// 清空循环队列。
void Clear(PSeqQueue QQ)
{
	if (QQ == NULL)
	{
		return;
	}
	QQ->front = QQ->rear = 0;
	memset(QQ->data, 0, sizeof(ElemType) * MAXSIZE);
}

// 判断循环队列是否为空，返回值：1-空，0-非空或失败。
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

// 判断循环队列是否已满，返回值：1-已满，0-未满或失败。
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

// 二叉树的层次遍历。
void LevelOrder(BiTree TT)
{
	SeqQueue QQ;     // 创建循环队列。

	InitQueue(&QQ);  // 初始化循环队列。

	ElemType ee = TT;  // 队列的元素是二叉树。

	InQueue(&QQ, &ee);  // 把根结点当成队列的元素入队。

	while (IsEmpty(&QQ) != 1)  // 队列不为空。
	{
		OutQueue(&QQ, &ee);  // 队头元素出队。

		visit(ee);  // 访问出队元素。
		// 如果出队元素有左结点，左结点入队。
		if (ee->lchild != NULL)
		{
			InQueue(&QQ, &ee->lchild);
		}

		// 如果出队元素有右结点，右结点入队。
		if (ee->rchild != NULL)
		{
			InQueue(&QQ, &ee->rchild);
		}
		
	}
}

// 访问出队元素
void visit(BiTNode* pp)
{
	printf("%c ", pp->data);
}
	