//将struct与typedef分开定义
#include <stdio.h>
#include <stdlib.h>
typedef struct PolyNode* Polynomial;	//使用 typedef 给一个还未完全声明的类型 PolyNode 起了一个新别名Polynomial
struct PolyNode {
	int coef;			//系数
	int expon;			//指数
	Polynomial link;	//指向下一个域的指针（声明link，类型是Polynomial，Polynomial表示的是结构体的别名）
};
//传入系数、指数、Polynomial类型的指针（Polynomial本身也是指针）
void Attach(int c, int e, Polynomial* pRear)
{
	Polynomial P;

	//申请新结点，结点类型为结构体PolyNode
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	//对新结点赋值
	P->coef = c;
	P->expon = e;
	P->link = NULL;
	(*pRear)->link = P;
	*pRear = P;	//修改pRear的值
}
Polynomial ReadPoly()
{
	Polynomial P, Rear, t;
	int c, e, N;
	//先读入一个整数
	scanf_s("%d", &N);
	//链表头空结点
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->link = NULL;
	Rear = P;
	//再一对对读系数指数
	while (N--)
	{
		scanf_s("%d %d", &c, &e);
		//每读入一个结点，插在当前结果表达式的后面。rear要改变，所以传指针
		Attach(c, e, &Rear);
	}
	//删除临时生成的头节点
	t = P;
	P = P->link;
	free(t);
	return P;
}
//add 插件
int compare(int e1, int e2) {
	if (e1 > e2) return 1;
	else if (e1 < e2) return -1;
	else return 0;
}

//add instructor
Polynomial Add(Polynomial P1, Polynomial P2) {
	Polynomial PS, rear, temp;
	int sum;
	//构造空结点，rear指向当前处理结果的尾巴
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
	//P1、P2相乘， 只要有一个为空，返回null
	if (!P1 || !P2) return NULL;
	t1 = P1;
	t2 = P2;
	//申请空结点
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->link = NULL;
	Rear = P;
	//先用P1的第一项乘以P2，得到P
	while (t2) {
		Attach(t1->coef * t2->coef, t1->expon + t2->expon, &Rear);
		t2 = t2->link;	//t2往后挪
	}
	t1 = t1->link;
	//两重循环 t1每一项乘t2每一项
	while (t1) {
		t2 = P2;
		Rear = P;	//Rear一开始指向P
		while (t2) {
			e = t1->expon + t2->expon;	//指数相加得到当前指数
			c = t1->coef * t2->coef;	//系数相乘得到当前系数
			//找插入位置。比较指数，将当前结果按照指数降序插进结果多项式
			while (Rear->link && Rear->link->expon > e)	//Rear的下一项的指数大于要插入的指数，所以rear还要往后挪
				Rear = Rear->link;
			if (Rear->link && Rear->link->expon == e) {	//Rear的下一项的指数等于要插入的指数，要做合并
				if (Rear->link->coef + c)				//系数相加后不等于0，c加进原来的
					Rear->link->coef += c;
				else {								//系数相加后等于0，删掉
					t = Rear->link;
					Rear->link = t->link;
					free(t);
				}
			}
			else {										//Rear的下一项的指数小于要插入的指数，可以插入
				t = (Polynomial)malloc(sizeof(struct PolyNode));	//申请一个新结点
				t->coef = c; t->expon = e;
				t->link = Rear->link;								//插入新结点
				Rear->link = t; Rear = Rear->link;
			}
			t2 = t2->link;
		}
		t1 = t1->link;
	}
	//第一个空结点要删掉
	t2 = P;
	P = P->link;	//指向下一个位置
	free(t2);

	return P;
}

//output
void PrintPoly(Polynomial P)
{ /* 输出多项式 */
	int flag = 0; /* 辅助调整输出格式用 */
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

