#include <iostream>
using namespace std;
class Point
{
private:
	int x, y;
public:
	void init(int a, int b)
	{
		this->x = a;
		this->y = b;
	}
	void setx(int a)
	{
		this->x = a;
	}
	void sety(int b)
	{
		this->y = b;
	}
	int getx()
	{
		return this->x;
	}
	int gety()
	{
		return this->y;
	}
};
int main()
{
	Point A, B;
	A.init(702, 311);
	B.init(311, 702);
	cout << "A.x=" << A.getx() << " " << "B.y=" << B.gety() << endl;
	return 0;
}