#include "Student.h"
Student::Student(string name)
{
	this->name = name; 
}
void Student::MarkUml(int i) { subject.Uml.push_back(i); }
void Student::MarkCplus(int i) { subject.Cplus.push_back(i); }
void Student::ShowMarkStudent(Student &st) {
	cout << "\n" << name;
	vector<int>::iterator i_iterator = st.subject.Uml.end();
	cout << "\n C++ : ";
	for (i_iterator = subject.Cplus.begin();
		i_iterator != subject.Cplus.end(); i_iterator++)
		cout << *(i_iterator) << " ";
	cout << "\n UML : ";
	for (i_iterator = st.subject.Uml.begin();
		i_iterator != subject.Uml.end(); i_iterator++)
		cout << *(i_iterator) << " ";
}
void Group::ListStudent() {
	if (student.empty())
	{
		system("cls");
		cout << "Данных нет!";
		
	}
	else
	{
		system("cls");
		for (int i = 0; i < student.size(); i++)
		{
			cout << "\n" << i + 1 << " - ";
			student[i].ShowStudent();
		}
	}
}
void Group::AddStudent(Student& s) { student.push_back(s); count++; }
void Group::AddStudent(Group& gr)
{
	string n;
	system("cls");
	cout << "\nВведите Фамилия Имя : ";
	cin.ignore(32767, '\n');
	getline(cin,n);
	cout << n;
	Student temp(n);
	gr.student.push_back(temp);
}
void Group::ShowGroup() {
	system("cls"); 
	if (student.empty())
		cout << "Данных нет!";
	else
	for (int i = 0; i < student.size(); i++)
		student[i].ShowMarkStudent(student[i]); }
void Group::SelectStudent()
{

}
void Group::SetMark(Group& gr)
{
	int n = 0, s, i;
	gr.ListStudent();
	cout << "\nВыберите студента : ";
	cin >> n;
	n--;
	while (n >= student.size() || n <= 0)
	{
		cout << "\nНеправильный ввод!";
		cout << "\nВведите студента № ";
		cin >> n;
		n--;
	}
	system("cls");
	student[n].ShowStudent();
	cout << "\nВыберите предмет 1 - UML 2 - C++ : ";
	cin >> s;
	while (s < 1 || s>2)
	{
			cout << "\nНеправильный ввод!";
			cout << "\nВыберите предмет 1 - UML 2 - C++ : ";
			cin >> s;
	}
	cout << "\nПоставьте оценку :  ";
	cin >> i;
	while (i < 0 || i>12) {
		cout << "\nНеправильный ввод";
		cout << "\nПоставьте оценку от 0 до 12 : ";
		cin >> i;
	}
		switch (s) {
		case 1:
			gr.student[n].MarkUml(i); break;
		case 2:
			gr.student[n].MarkCplus(i); break;
		}
	gr.student[n].ShowMarkStudent(student[n]);
}
void Group::Save(Group& gr)
{
	ofstream fout("newFile.txt");
	if (!fout.is_open())
		cout << "Error, not opened file!";
	for (int i = 0; i < student.size(); i++)
	{
		fout << gr.student[i];
	}
	fout.close();
}
bool Symbol(const string& Symbols, const char& ch)
{
	for (int i = 0; i < Symbols.size(); i++)
		if (ch == Symbols[i])
			return true;
	return false;
}
void Group::Load(Group& gr)
{
	int mark;
	string str;
	string Symbols = "1234567890";
	ifstream fin("newFile.txt");
	if (!fin.is_open())
		cout << "Error, not opened file!";
	else
	while (true)
	{
		if (fin.eof())
		{
			break;
		}
		getline(fin, str);
		Student temp(str);
		getline(fin, str);
		for (int i = 0; i < str.size(); i++)
		{
			if (Symbol(Symbols,str[i])&& Symbol(Symbols, str[i+1]))
			{
				mark =(( str[i]-48 )*10)+ (str[i + 1]-48);
				temp.MarkCplus(mark);
				i++;
			}
			else if (Symbol(Symbols, str[i]) && !Symbol(Symbols, str[i + 1]))
				temp.MarkCplus(str[i]-48);
		}
		getline(fin, str);
		for (int i = 0; i < str.size(); i++)
		{
			if (Symbol(Symbols, str[i]) && Symbol(Symbols, str[i + 1]))
			{
				mark = ((str[i] - 48) * 10) + (str[i + 1] - 48);
				temp.MarkUml(mark);
				i++;
			}
			else if (Symbol(Symbols, str[i]) && !Symbol(Symbols, str[i + 1]))
				temp.MarkUml(str[i]-48);
		}
		gr.AddStudent(temp);
	
	}
	fin.close();
	gr.student.pop_back();
}
ostream& operator<<(ostream& os, const Student& st)
{
	os << st.name << endl;
	os << "C++ : ";
	for (int i = 0; i < st.subject.Cplus.size(); i++)
		os << st.subject.Cplus[i] << " ";
	os << endl<<"Uml : ";
	for (int i = 0; i < st.subject.Uml.size(); i++)
		os << st.subject.Uml[i];
	os << endl;
	
	return os;
}


