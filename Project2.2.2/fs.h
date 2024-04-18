#include <stdio.h>
#include <stdlib.h>
typedef struct SNode* Stack;
struct SNode
{
	int data;
	struct SNode* next;
};

//����������
Stack CreateStack()
{
	Stack S;
	S = (Stack)malloc(sizeof(struct SNode));
	S->next = NULL;
	return S;
}

//�п�
int isEmpty(Stack S)
{
	return S->next == NULL;
}

//push ��ѹջ
void Push(int item, Stack S)
{
	struct SNode* temp;
	temp = (struct SNode*)malloc(sizeof(struct SNode*));
	temp->data = item;
	//��ǰ����
	temp->next = S->next;
	S->next = temp;
}
Stack Pop(Stack S)
{
	struct SNode* firstcell;
	Stack topelement;
	if (isEmpty(S))
	{
		printf("��ջ��");
		return  NULL;
	}
	else
	{
		firstcell = S->next;
		S->next = firstcell->next;
		topelement = firstcell->next;
		free(firstcell);
		return topelement;
	}
}