#include"szn.h"
template<class T>
Seqlist<T>::Seqlist(int sz)   
{
	if (sz > 0)
	{
		maxSize = sz;
		last = -1;       //表的实际长度为空
		data = new T[maxSize];
		if (data == NULL)
		{
			cout << "error" << endl;
			exit(1);
		}
	}
}		
//构造函数结束

template <class T>
Seqlist<T>::Seqlist(Seqlist<T>& L)
{
	maxSize = L.Size()；
		last = L.Length() - 1;
		T value;
	data = new T[maxSize];
	if (data = NULL)
	{
		cout << "error" << endl;
		exit(1);
	}
	for (int i = 1; i <= last + 1; i++)
	{
		L.getData(i, value);
		data[i - 1] = value;
	}
}
//复制构造函数结束

template <class T>
int Seqlist<T>::Length()const
{
	return last + 1;
}
//计算表长（*）

template <class T>
int Seqlist<T>::Size()const
{
	return maxSize;
}
//计算表的最大容量（&）

template <class T>
bool Seqlist<T>::getData(int i, T& x)const
{
	if (i > 0 && i <= last + 1)
	{
		x = data[i - 1];
		return true;
	}
	else
		return false;
}
//取第i个表项的值（1)

template <class T>	
int Seqlist<T>::Search(T& x)const
{
	for (int i = 0; i < last; i++)
		if (data[i] == x)
			return i + 1;
	return 0;
}
//搜索x的表项序号（2）

template <class T>
int Seqlist<T>::Locate(int i)const
{
	if (i >= 1 && i <= last + 1)
		return i;
	else
		return 0;
}
//定位第i个表项并返回（3）

template<class T>
void Seqlist<T>::SetData(int i, T& x)
{
	if (i > 0 && i << last + 1)
		data[i - 1] = x;
}
//改变第i个表项的值（4）

template <class T>
bool Seqlist<T>::Insert(int i, T& x)
{
	if (last == maxSize - 1)
		return false;
	if (i<0 || i>last + 1)
		return false;
	for (int j = last; j >= i; j--)
		data[j + 1] = data[j];
	data[i] = x;
	last++;
	return true;
}
//i处插入x（5）

template <class T>
bool Seqlist<T>::Remove(int i, T& x)
{
	if (last == maxSize - 1)
		return false;
	if (i<0 || i>last + 1)
		return false;
	x = data[i - 1];
	for (int j = i; j <= last; j++)
		data[j - 1] = data[j];
	last--;
	return true;
}
//删除第i个元素（6）

template<class T>
Seqlist<T>::~Seqlist()
{
	delete[]data;
}
//析构函数结束

template<class T>
void Seqlist<T>::reSize(int newSize)
{
	//保护函数：扩充空间，新数组元素个数为newSize个；
	if (newSize <= 0)
	{
		cout << "error" << endl;
		return;
	}
	if (newSize != maxSize)
	{
		T* newarray = new T[newSize];
		if (newarray == NULL)
		{
			cout << "error" << endl;
			exit(1);
		}
		int n = last + 1;
		T* srcptr = data;
		T* destptr = newarray;
		while (n--)
			*destptr++ = *srcptr++;   //复制
		delete[]data;   //删除老数组
		data = newarray;
		maxSize = newSize;
	}
}
//保护函数结束(0)

template<class T>
void Seqlist<T>::input()
{
	cout << "please input elements:" << endl;
	while (1)
	{
		cin >> last;
		if (last <= maxSize)
			break;
		cout << "error" << endl;
	}
	for (int i = 0; i <= last; i++)
	{
		cout << i + 1 << " ";
		cin >> data[i];
	}
}
//输入结束

template<class T>
void Seqlist<T>::output()
{
	for (int i = 0; i <= last; i++)
		cout << data[i] << " ";
	cout << endl;
}
//输出结束