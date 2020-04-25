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
		cout << "\n\n1 - Список студентов ";
		cout << "\n2 - Посмотреть успеваемость студентов ";
		cout << "\n3 - Добавить студента ";
		cout << "\n4 - Поставить оценку  ";
		cout << "\n5 - Сохранить ";
		cout << "\n6 - Загрузить ";
		cout << "\n7 - Выход ";
		cout << "\nВведите : ";
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