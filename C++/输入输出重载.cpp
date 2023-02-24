#include <iostream>
#include <string.h>

using namespace std;

/*
 有一销售人员类Sales，其数据成员有姓名name，身份证号id，年龄age。
 重载输入/输出运算符实现对Sales类数据成员的输入和输出。
*/

class Sales
{
public:
	Sales(const char* acName, const char* acId, int age);

	friend Sales& operator<<(ostream& os, Sales &s1);
	friend Sales& operator>>(istream& is, Sales &s1);

private:
	/* data */
	char Name[20];
	char Id[10];
	int age;
};

Sales::Sales(const char* acName, const char* acId, int iAge)
{
	strcpy(Name, acName);
	strcpy(Id, acId);
	age = iAge;
}

Sales& operator<<(ostream& os, Sales &s1)
{
	os << s1.Name << "\t";
	os << s1.Id << "\t";
	os << s1.age << endl;
	return s1;
}

Sales& operator>>(istream& is, Sales &s1)
{
	cout << "intput..." << endl;
	is >> s1.Name >> s1.Id >> s1.age;
	return s1;
}

int main(int agec, char **argv) 
{
	Sales s1("XuMing", "123", 30);
	cout << s1;

	cin >> s1;
	cout << s1;
	
	system("pause");
	return 0;
}
