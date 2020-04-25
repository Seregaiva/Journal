#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include <stdio.h>
#pragma warning (disable:4996)
using namespace std;
struct Subject
{
	vector<int>Uml;
	vector<int>Cplus;
};
class Student
{
	string name;
	Subject subject;
public:
	friend ostream& operator<<(ostream& os, const Student& st);
	Student() {}
	Student(string name);
	void ShowStudent() { cout << name; }
	void ShowMarkStudent(Student &st);
	void MarkUml(int i);
	void MarkCplus(int i);
	~Student() {}
};
class Group
{

	vector<Student>student;
	int count;
public:
	Group() { 
		if (count)
		student.clear();
		count = 0;
	}
	int getQuantity() { return count; }
	void AddStudent(Student& s);
	void AddStudent(Group& gr);
	void ListStudent();
	void ShowGroup();
	void SelectStudent();
	void SetMark(Group& gr);
	void Save(Group& gr);
	void Load(Group& gr);
	~Group() {}
};

