#include <stdio.h>
#include <stdlib.h>
typedef struct SNode* Stack;
struct SNode
{
	int data;
	struct SNode* next;
};

//´´½¨¿ÕÁ´±í
Stack CreateStack()
{
	Stack S;
	S = (Stack)malloc(sizeof(struct SNode));
	S->next = NULL;
	return S;
}

//ÅÐ¿Õ
int isEmpty(Stack S)
{
	return S->next == NULL;
}

//push ¡¤Ñ¹Õ»
void Push(int item, Stack S)
{
	struct SNode* temp;
	temp = (struct SNode*)malloc(sizeof(struct SNode*));
	temp->data = item;
	//ÏòÇ°ÑÓÉê
	temp->next = S->next;
	S->next = temp;
}
Stack Pop(Stack S)
{
	struct SNode* firstcell;
	Stack topelement;
	if (isEmpty(S))
	{
		printf("¶ÑÕ»¿Õ");
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