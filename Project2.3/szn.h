#include <iostream>
using namespace std;
typedef struct LinkNode
{
	int data;
	LinkNode* link;
	LinkNode(LinkNode* ptr = NULL) 
	{ 
		link = ptr;
	}
	//对应 LinkNode*desptr = first = new LinkNode;
	LinkNode(const int item, LinkNode* ptr = NULL)
	{
		data = item;
		link = ptr;
	}
	//对应LinkNode*newNode = new LinkNode(x);
}LinkNode;
class List
{
private:
	LinkNode* first;
public:
	List() {
		first = new LinkNode;
	}
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
	bool Insert(int i,int& x);
	bool Remove(int i, int& x);
};