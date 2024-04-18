#include"szn.h"
template<class T>
List<T>::List(List<T>& L)
{
	T value;
	LinkNode<T>* srcptr = L.first;
	LinkNode<T>* desptr = first = new LinkNode<T>;
	while (srcptr->link != NULL)
	{
		value = srcptr->link->data;
		desptr->link = new LinkNode<T>(value);
		desptr = desptr->link;
		srcptr = srcptr->link;
	}
	desptr->link = NULL;
}
//复制构造函数

template <class T>
void List<T>::makeEmpty()
{
	LinkNode<T>* q;
	while (first->link != NULL)
	{
		q = first->link;
		first->link = q->link;
		delete q;
	}
}
//析构函数的子函数

template<class T>
LinkNode<T>* List<T>::Locate(int i)
{
	if (i < 0) return NULL;
	LinkNode<T>* current = first;
	int k = 0;
	while (current != NULL && k < i)
	{
		current = current->link;
		k++;
	}
	return current;
}
//返回第i个元素地址

template<class T>
bool List<T>::Insert(int i, T& x)
{
	LinkNode<T>* current = Locate(i);
	if (current == NULL)
		return false;
	LinkNode<T>* newNode = new LinkNode<T>(x);
	if (newNode == NULL)
	{
		cout << "分配错误" << endl;
		exit(1);
	}
	newNode->link = current->link;
	current->link = newNode;
	return true;
}
//插入第i个元素函数

template<class T>
bool List<T>::Remove(int i, T& x)
{
	LinkNode<T>* current = Locate(i - 1);
	if (current == NULL || current->link == NULL)
		return false;
	LinkNode<T>* del = current->link;
	current->link = del->link;
	x = del->data;
	delete del;
	return true;
}
//删除第i个元素

template<class T>
void List<T>::inputFront(T endTag)
{
	LinkNode<T>* newNode;
	T val;
	makeEmpty();
	cin >> val;
	while (val != endTag) 
	{
		newNode = new LinkNode<T>(val);
		if (newNode == NULL) { cout << "存储分配错误"; exit(1); }
		newNode->link = first->link;
		first->link = newNode;
		cin >> val;
	}
}
//前插法建立单链表

template<class T>
void List<T>::inputRear(T endTag)
{
	LinkNode<T>* newNode, * last;
	T val;
	makeEmpty();
	cin >> val; last = first;
	while (val != endTag)
	{
		newNode = new LinkNode<T>(val);
		if (newNode == NULL) { cout << "存储分配错误"; exit(1); }
		last->link = newNode;
		last = newNode;
		cin >> val;
	}
	last->link = NULL;//实际可以省略
}
//后插法建立链表
