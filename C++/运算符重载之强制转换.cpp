#include <iostream>
using namespace std;

/*
有一个类Circle，设计该类的类型转换函数，当将Circle对象转换成int型时，返回圆的半径；当将它转换成double型时，就返回圆的周长；当将它转换成float型时，就返回圆的面积。
*/

/*
类型转换函数没有参数。
类型转换函数没有返回类型。
类型转换函数必须返回将要转换成的type类型数据。
*/

class Circle
{
public:
	Circle(int r) : nr(r){}

	operator int(){return nr;}
	operator double(){return 2*3.14*nr;}
	operator float(){return float(3.14*nr*nr);}

private:
	int nr;
};


int main(int agec, char **argv) 
{
	Circle c1(2);

	int i = c1;
	double d = c1;
	float f = c1;

	cout << i << "\t" << d << "\t" << f << endl; 
	system("pause");
	return 0;
}
