//建学生档案(姓名、身份证号、综合成绩)
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;

class student
{
private:
	/* data */
	char Name[20];
	char Id[10];
	int Sum;
public:
	student(){} 
	student(const char* acName, const char* acId, int iSum) 
	{
		strcpy(Name, acName);
		strcpy(Id, acId);
		Sum = iSum;
	}

	void Display()
	{
		cout << Name <<"\t" << Id <<"\t" << Sum << "\t";
	}
};

int main(int agec, char **argv) 
{
	char acName[20];
	char acId[10];
	int sum = 0;
	char ch;
	fstream ioFile;
	ioFile.open("D:/Users/10261660/Desktop/data.txt", ios::out|ios::app);
	
	do
	{
		cout << "Input Name: ";
		cin >> acName;

		cout<< "Input Id: ";
		cin >> acId;

		cout<< "Input total value: ";
		cin >> sum;

		student st(acName, acId, sum);
		ioFile.write((char*)&st, sizeof(st));

		cout<< "continue? (Y/y)";
		cin >> ch;
	} while (ch == 'Y' || ch == 'y');
	ioFile.close();

	ioFile.open("D:/Users/10261660/Desktop/data.txt", ios::in);
	student st1;
	ioFile.read((char*)&st1, sizeof(st1));
	vector<student> vec;
	while (!ioFile.eof())
	{
		vec.push_back(st1);
		ioFile.read((char*)&st1, sizeof(st1));
	}
	ioFile.close();

	cout<< "output Info";
    vector<student>::iterator iter;
	for (iter = vec.begin(); iter != vec.end(); iter++)
	{
		iter->Display();
	}
	
	system("pause");
	return 0;
}
