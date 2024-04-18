#include <stdio.h>
#include <stdlib.h>
#define Maxsize 1000
#define Dsize 50
typedef int ElemType;    //���������
struct Node
{
	ElemType Data[Maxsize];
	int index;
};
typedef struct Node* Stack;

//Stack CreateS(int max)
//int isFull(Stack Ptr)

//�п�
int isEmpty(Stack S)
{
	return S->index == -1;
}
//���ȫ��ջ
void MakeEmpty(Stack S)
{
	if (S == NULL)
		printf("use Create() first\n");
	else
		while (!isEmpty(S))
			Pop(S);
}

//������ջ
Stack Create()
{
	Stack* Sk;
	Sk = (Stack*)malloc(sizeof(struct Node));    //�Ⱥ����߷�������Ҫ��ͬ
}
//��ջ
void Push(Stack Ptr, ElemType item)
{
	if (Ptr->index == Maxsize - 1)
	{
		printf("��ջ��\n");
		return;
	}
	else
	{
		Ptr->Data[++(Ptr->index)] = item;
		return;
	}
}
//��ջ
ElemType Pop(Stack Ptr)
{
	if (Ptr->index == -1)
	{
		printf("��ջ�ѿ�\n");
		return NULL;
	}
	else
		return Ptr->Data[(Ptr->index)--];
}


//ʵ��˫���ջ
typedef struct DStack
{
	ElemType data[Maxsize];
	int tou;
	int wei;
}S;
//Ԫ�ؽ�ջ
void Push(S* Ptr, ElemType item, int tag)
{
	if (Ptr->wei - Ptr->tou == 1)
	{
		printf("��ջ��\n");
		return;
	}
	else
	{
		if (tag == 1)
			Ptr->data[++(Ptr->tou)] = item;
		else
			Ptr->data[--(Ptr->wei)] = item;
	}
}
//Ԫ�س�ջ
ElemType Pop(S* Ptr, int tag)
{
	if (tag == 1)
	{
		if (Ptr->tou == -1)
		{
			printf("��ջ��\n");
			return NULL;
		}
		else return Ptr->data[(Ptr->tou)--];
	}
	else
	{
		if (Ptr->wei == Maxsize)
		{
			printf("��ջ��\n");
			return NULL;
		}
		else return Ptr->data[(Ptr->wei)++];
	}
}