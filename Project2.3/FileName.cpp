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
		//link不止一个，重复指向link是寻找第i个节点，也就是正确的插入位置
		if (current == NULL)
		{
			cout << "无效的插入位置\n";
			return false;
		}
		else {
			LinkNode* newNode = new LinkNode(x);
			if (newNode == NULL) { cout << "分配错误"; exit(1); }
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
			cout << "无效删除位置";
			return false;
		}
		del = current->link;
		current->link = del->link;
	}
	x = del->data; delete del;
	return true;
}