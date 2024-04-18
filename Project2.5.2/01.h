//��struct��typedef�ֿ�����
#include <stdio.h>
#include <stdlib.h>
typedef struct PolyNode* Polynomial;	//ʹ�� typedef ��һ����δ��ȫ���������� PolyNode ����һ���±���Polynomial
struct PolyNode {
	int coef;			//ϵ��
	int expon;			//ָ��
	Polynomial link;	//ָ����һ�����ָ�루����link��������Polynomial��Polynomial��ʾ���ǽṹ��ı�����
};
//����ϵ����ָ����Polynomial���͵�ָ�루Polynomial����Ҳ��ָ�룩
void Attach(int c, int e, Polynomial* pRear)
{
	Polynomial P;

	//�����½�㣬�������Ϊ�ṹ��PolyNode
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	//���½�㸳ֵ
	P->coef = c;
	P->expon = e;
	P->link = NULL;
	(*pRear)->link = P;
	*pRear = P;	//�޸�pRear��ֵ
}
Polynomial ReadPoly()
{
	Polynomial P, Rear, t;
	int c, e, N;
	//�ȶ���һ������
	scanf_s("%d", &N);
	//����ͷ�ս��
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->link = NULL;
	Rear = P;
	//��һ�ԶԶ�ϵ��ָ��
	while (N--)
	{
		scanf_s("%d %d", &c, &e);
		//ÿ����һ����㣬���ڵ�ǰ������ʽ�ĺ��档rearҪ�ı䣬���Դ�ָ��
		Attach(c, e, &Rear);
	}
	//ɾ����ʱ���ɵ�ͷ�ڵ�
	t = P;
	P = P->link;
	free(t);
	return P;
}
//add ���
int compare(int e1, int e2) {
	if (e1 > e2) return 1;
	else if (e1 < e2) return -1;
	else return 0;
}

//add instructor
Polynomial Add(Polynomial P1, Polynomial P2) {
	Polynomial PS, rear, temp;
	int sum;
	//����ս�㣬rearָ��ǰ��������β��
	PS = (Polynomial)malloc(sizeof(struct PolyNode));
	PS->link = NULL;
	rear = PS;
	while (P1 && P2) {
		switch (compare(P1->expon, P2->expon)) {
		case 1:
			Attach(P1->coef, P1->expon, &rear);
			P1 = P1->link;
			break;
		case -1:
			Attach(P2->coef, P2->expon, &rear);
			P2 = P2->link;
			break;
		case 0:
			sum = P1->coef + P2->coef;
			if (sum) Attach(sum, P1->expon, &rear);//coef=0 then do nothing
			P1 = P1->link;
			P2 = P2->link;
			break;
		}
	}
	while (P1) {
		Attach(P1->coef, P1->expon, &rear);
		P1 = P1->link;
	}
	while (P2) {
		Attach(P2->coef, P2->expon, &rear);
		P2 = P2->link;
	}
	//rear->link=NULL;
	temp = PS;
	PS = PS->link;
	free(temp);
	return PS;
}

//mult instructor
Polynomial Mult(Polynomial P1, Polynomial P2)
{
	Polynomial P, Rear, t1, t2, t;
	int c, e;
	//P1��P2��ˣ� ֻҪ��һ��Ϊ�գ�����null
	if (!P1 || !P2) return NULL;
	t1 = P1;
	t2 = P2;
	//����ս��
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->link = NULL;
	Rear = P;
	//����P1�ĵ�һ�����P2���õ�P
	while (t2) {
		Attach(t1->coef * t2->coef, t1->expon + t2->expon, &Rear);
		t2 = t2->link;	//t2����Ų
	}
	t1 = t1->link;
	//����ѭ�� t1ÿһ���t2ÿһ��
	while (t1) {
		t2 = P2;
		Rear = P;	//Rearһ��ʼָ��P
		while (t2) {
			e = t1->expon + t2->expon;	//ָ����ӵõ���ǰָ��
			c = t1->coef * t2->coef;	//ϵ����˵õ���ǰϵ��
			//�Ҳ���λ�á��Ƚ�ָ��������ǰ�������ָ���������������ʽ
			while (Rear->link && Rear->link->expon > e)	//Rear����һ���ָ������Ҫ�����ָ��������rear��Ҫ����Ų
				Rear = Rear->link;
			if (Rear->link && Rear->link->expon == e) {	//Rear����һ���ָ������Ҫ�����ָ����Ҫ���ϲ�
				if (Rear->link->coef + c)				//ϵ����Ӻ󲻵���0��c�ӽ�ԭ����
					Rear->link->coef += c;
				else {								//ϵ����Ӻ����0��ɾ��
					t = Rear->link;
					Rear->link = t->link;
					free(t);
				}
			}
			else {										//Rear����һ���ָ��С��Ҫ�����ָ�������Բ���
				t = (Polynomial)malloc(sizeof(struct PolyNode));	//����һ���½��
				t->coef = c; t->expon = e;
				t->link = Rear->link;								//�����½��
				Rear->link = t; Rear = Rear->link;
			}
			t2 = t2->link;
		}
		t1 = t1->link;
	}
	//��һ���ս��Ҫɾ��
	t2 = P;
	P = P->link;	//ָ����һ��λ��
	free(t2);

	return P;
}

//output
void PrintPoly(Polynomial P)
{ /* �������ʽ */
	int flag = 0; /* �������������ʽ�� */
	if (!P) {
		printf("0 0\n");
		return;
	}
	while (P) {
		if (!flag)
			flag = 1;
		else
			printf(" ");
		printf("%dx^%d", P->coef, P->expon);
		P = P->link;
	}
	printf("\n");
}

