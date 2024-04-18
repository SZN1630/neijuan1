#include "01.h"
int main()
{
	Polynomial P1, P2, PP, PS;
	//读入多项式1，P1、P2都是链表结构的指针
	printf("Please input polynomial 1:\n");
	P1 = ReadPoly();
	//读入多项式2
	printf("Please input polynomial 2:\n");
	P2 = ReadPoly();
	printf("求得的结果是：\n");
	//加法运算并输出
	PS = Add(P1, P2);
	PrintPoly(PS);
	//乘法运算并输出，返回的也是指针
	PP = Mult(P1, P2);
	PrintPoly(PP);
	return 0;
}
