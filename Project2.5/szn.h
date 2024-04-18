#include <iostream>
using namespace std;
template<class T>
struct LinkNode
{
	T data;
	LinkNode<T>* link;
	LinkNode(LinkNode<T>* ptr = NULL) { link = ptr; }
	LinkNode(const T&item,LinkNode<T>*ptr=NULL)
	{
		data = item; link = ptr;
	}
};

template<class T>
class List
{
private:
	LinkNode<T>* first;
public:
	List() {
		first = new LinkNode<T>;
	}
	List(const T& x)
	{
		first = new LinkNode<T>(x);
	}
	List(List<T>& L);
	~List() { makeEmpty(); }
	void makeEmpty();
	LinkNode<T>* Locate(int i);
	bool Insert(int i, T& x);
	bool Remove(int i, T& x);
	void inputFront(T endTag);
	void inputRear(T endTag);
};
