#include<iostream>
#include<stdlib.h>
using namespace std;
const int defaultSize = 100;
template<class T>
class Seqlist
{
protected:
	T* data;                    //data是数组啊
	int maxSize;
	int last;
	void reSize(int newSize);     //改变空间大小函数(0)
public:
	int Length()const;      //计算表长 （*）
	int Size()const;			//计算表的最大容量（&）
	Seqlist(int sz = defaultSize);		
	Seqlist(Seqlist<T>& L);			
	~Seqlist();				
	int Search(T& x)const;   //搜索x在表项中的位置（1）
	int Locate(int i)const;   //定位第i个表项的值（2）
	bool getData(int i, T& x)const;  //取第i个表项的值（3）
	void SetData(int i, T& x);    //改变第i个表项的值（4）
	bool Insert(int i, T& x);    //插入x在第i个表项之后（5）
	bool Remove(int i, T& x);	//删除第i个表项（6）
	void input();			    //in
	void output();				//out
};


