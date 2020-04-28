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
		cout << "\n\n1 - List Student ";
		cout << "\n2 - Show student performance ";
		cout << "\n3 - Add student ";
		cout << "\n4 - Set Rate  ";
		cout << "\n5 - Save ";
		cout << "\n6 - Load ";
		cout << "\n7 - Exit ";
		cout << "\nThe choice : ";
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
