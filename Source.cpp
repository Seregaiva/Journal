#include <iostream>
#include <vector>
#include<string>
#include"Student.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	int key = 1;
	Group group;
	while (key != 0)
	{
		cout << "\n\n1 - ������ ��������� ";
		cout << "\n2 - ���������� ������������ ��������� ";
		cout << "\n3 - �������� �������� ";
		cout << "\n4 - ��������� ������  ";
		cout << "\n5 - ��������� ";
		cout << "\n6 - ��������� ";
		cout << "\n7 - ����� ";
		cout << "\n������� : ";
		cin >> key;
		switch (key)
		{
		case 1:
			group.ListStudent();
			break;
		case 2:
			group.ShowGroup();
			break;
		case 3:
			group.AddStudent(group);
			break;
		case 4:
			group.SetMark(group);
			break;
		case 5:
			group.Save(group);
			break;
		case 6:
			group.Load(group);
			break;
		case 0:
			exit(0);
		}
	}
}