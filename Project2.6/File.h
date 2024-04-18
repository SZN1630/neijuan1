#include <iostream>
using namespace std;
template<class T>
 struct CLinkNode
{
	T data;
    CLinkNode<T>* link;
	CLinkNode(CLinkNode<T>* next = NULL) :link(next) {}
	CLinkNode(T d, CLinkNode<T>* next = NULL) :data(d), link(next) {}
};


template<class T>
class CList
{
public:
	CList(constT& x);
	CList(CList<T>& L);
	~CList();
private:
	CLinkNode<T>* first, * rear;
};