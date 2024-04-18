#include"szn.h"
using namespace std;
bool List::Insert(int i,int& x)
{
	if (first == NULL || i == 0)
	{
		LinkNode* newNode = new LinkNode(x);
		if (newNode == NULL) { cout << "error input"; exit(1); }
		newNode->link = first;
		first = newNode;
	}
	else
	{
		LinkNode* current = first;
		for (int k = 1; k < i; k++)
			if (current == NULL)break;
			else current = current->link;
		//link��ֹһ�����ظ�ָ��link��Ѱ�ҵ�i���ڵ㣬Ҳ������ȷ�Ĳ���λ��
		if (current == NULL)
		{
			cout << "��Ч�Ĳ���λ��\n";
			return false;
		}
		else {
			LinkNode* newNode = new LinkNode(x);
			if (newNode == NULL) { cout << "�������"; exit(1); }
			newNode->link = current->link;
			current->link = newNode;
		}
	}
}
bool List::Remove(int i, int& x)
{
	LinkNode* del, * current;
	if (i <= 1)
	{
		del = first;
		first = first->link;
	}
	else
	{
		current = first;
		for (int k = 1; k < i - 1; k++)
			if (current == NULL)break;
			else current = current->link;
		if (current == NULL || current->link == NULL) {
			cout << "��Чɾ��λ��";
			return false;
		}
		del = current->link;
		current->link = del->link;
	}
	x = del->data; delete del;
	return true;
}