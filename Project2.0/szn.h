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
	//构造函数和复制构造函数
}LinkNode;
class List
{
private:
	LinkNode* first;
public:
	List() { first = new LinkNode; }
	List(const LinkNode& x) { first = new LinkNode(x); }
	//构造函数
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
	//复制构造函数
	void inputFront();
	//第一步：输入
	bool Insert(int i, int& x);
	//插入元素
	//bool Remove(int i, int& x);
	//删除元素
	void Output();
	//最后一步：输出
};
