#include "01.h"
int main()
{
	Polynomial P1, P2, PP, PS;
	//�������ʽ1��P1��P2��������ṹ��ָ��
	printf("Please input polynomial 1:\n");
	P1 = ReadPoly();
	//�������ʽ2
	printf("Please input polynomial 2:\n");
	P2 = ReadPoly();
	printf("��õĽ���ǣ�\n");
	//�ӷ����㲢���
	PS = Add(P1, P2);
	PrintPoly(PS);
	//�˷����㲢��������ص�Ҳ��ָ��
	PP = Mult(P1, P2);
	PrintPoly(PP);
	return 0;
}
