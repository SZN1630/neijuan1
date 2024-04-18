#include <stdio.h>
#include <stdlib.h>
#define Maxsize 1000
#define Dsize 50
typedef int ElemType;    //视情况而定
struct Node
{
	ElemType Data[Maxsize];
	int index;
};
typedef struct Node* Stack;

//Stack CreateS(int max)
//int isFull(Stack Ptr)

//判空
int isEmpty(Stack S)
{
	return S->index == -1;
}
//清除全部栈
void MakeEmpty(Stack S)
{
	if (S == NULL)
		printf("use Create() first\n");
	else
		while (!isEmpty(S))
			Pop(S);
}

//创建空栈
Stack Create()
{
	Stack* Sk;
	Sk = (Stack*)malloc(sizeof(struct Node));    //等号两边分配类型要相同
}
//进栈
void Push(Stack Ptr, ElemType item)
{
	if (Ptr->index == Maxsize - 1)
	{
		printf("堆栈满\n");
		return;
	}
	else
	{
		Ptr->Data[++(Ptr->index)] = item;
		return;
	}
}
//出栈
ElemType Pop(Stack Ptr)
{
	if (Ptr->index == -1)
	{
		printf("堆栈已空\n");
		return NULL;
	}
	else
		return Ptr->Data[(Ptr->index)--];
}


//实现双向堆栈
typedef struct DStack
{
	ElemType data[Maxsize];
	int tou;
	int wei;
}S;
//元素进栈
void Push(S* Ptr, ElemType item, int tag)
{
	if (Ptr->wei - Ptr->tou == 1)
	{
		printf("堆栈满\n");
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
//元素出栈
ElemType Pop(S* Ptr, int tag)
{
	if (tag == 1)
	{
		if (Ptr->tou == -1)
		{
			printf("堆栈空\n");
			return NULL;
		}
		else return Ptr->data[(Ptr->tou)--];
	}
	else
	{
		if (Ptr->wei == Maxsize)
		{
			printf("堆栈空\n");
			return NULL;
		}
		else return Ptr->data[(Ptr->wei)++];
	}
}