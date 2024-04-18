#include<iostream>
#include<stdlib.h>
using namespace std;
const int defaultSize = 100;
template<class T>
class Seqlist
{
protected:
	T* data;                    //data�����鰡
	int maxSize;
	int last;
	void reSize(int newSize);     //�ı�ռ��С����(0)
public:
	int Length()const;      //����� ��*��
	int Size()const;			//���������������&��
	Seqlist(int sz = defaultSize);		
	Seqlist(Seqlist<T>& L);			
	~Seqlist();				
	int Search(T& x)const;   //����x�ڱ����е�λ�ã�1��
	int Locate(int i)const;   //��λ��i�������ֵ��2��
	bool getData(int i, T& x)const;  //ȡ��i�������ֵ��3��
	void SetData(int i, T& x);    //�ı��i�������ֵ��4��
	bool Insert(int i, T& x);    //����x�ڵ�i������֮��5��
	bool Remove(int i, T& x);	//ɾ����i�����6��
	void input();			    //in
	void output();				//out
};


