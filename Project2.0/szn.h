#include <iostream>
using namespace std;
typedef struct LinkNode
{
	int data;
	LinkNode* link;
	LinkNode(LinkNode* ptr = NULL) { link = ptr; }
	LinkNode( const int item, LinkNode* ptr = NULL)
	{
		data = item;
		link = ptr;
	}
	//���캯���͸��ƹ��캯��
}LinkNode;
class List
{
private:
	LinkNode* first;
public:
	List() { first = new LinkNode; }
	List(const LinkNode& x) { first = new LinkNode(x); }
	//���캯��
	List(const List& L)
	{
		int value;
		LinkNode* srcptr = L.first;
		LinkNode* desptr = first = new LinkNode;
		while (srcptr->link != NULL)
		{
			value = srcptr->link->data;
			desptr->link = new LinkNode(value);
			desptr = desptr->link;
			srcptr = srcptr->link;
		}
		desptr->link = NULL;
	}
	//���ƹ��캯��
	void inputFront();
	//��һ��������
	bool Insert(int i, int& x);
	//����Ԫ��
	//bool Remove(int i, int& x);
	//ɾ��Ԫ��
	void Output();
	//���һ�������
};
