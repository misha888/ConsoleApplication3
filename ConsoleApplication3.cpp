﻿#include <iostream>
#include <string>
#include <Windows.h>
#define garbage_collector() cin.ignore(cin.rdbuf()->in_avail())

using namespace std;
struct DAT
{
	int year,
		month,
		day;


};
struct GROUP
{
	char firstName[15];
	char secondName[15];
	char lastName[15];
	DAT Date;
	static const short counSubject = 3;
	int SES[counSubject];
	unsigned int averageMark = 0;
};
GROUP* InitArray(int Dimension);
GROUP InitStudent();
void DisplayArray(GROUP* Massive, int Dimaension);
void DisplayPerson(GROUP);
void SortFirstName(GROUP*, int);
int& CheckCorectDigitValue(int&);

int main(int argc, char* argv[])
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(0, "");

	int Dimension;

	bool begin = true;
tryagain:
	GROUP* MassiveStruct = nullptr;
	do
	{
		cout << "\nEnter the number of student(s)]$~ ";
		do {
			cin >> Dimension;
			if (cin.fail())
			{
				cout << "~$]Previous input failed, please re-enter !!!" << endl;
				cin.clear();
				cin.ignore(32222, '\n');
			}
			else
				break;
		} while (true);
		MassiveStruct = InitArray(Dimension);
		if (MassiveStruct == nullptr)
		{
			cout << "\n~$]Dynamic array don't exist!\n";

			do {
				cout << "~$]Введите '+' для того чтобы повторить попытку или нажмите '-' чтобы выйти из програмы... ";
				char symbol;
				symbol = getchar();
				(symbol == '+') ? begin == true : begin == false;
				if (symbol == '+')
					goto tryagain;
				exit(777);

			} while (!begin);
		}


	} while (begin != true);

	cout << "\nThe list of students SES: ";
	SortFirstName(MassiveStruct, Dimension);
	DisplayArray(MassiveStruct, Dimension);



	cout << "\nThe  list of students 01.12.2010 have 20 year old:\n ";
	for (size_t i = 0; i < GROUP::counSubject; i++)
	{
		if ((MassiveStruct[i].Date.year - 2010 == -20) && (MassiveStruct[i].Date.day == 1) && (MassiveStruct[i].Date.month == 12))
		{
			cout << MassiveStruct[i].firstName << " " << MassiveStruct[i].lastName << " " << MassiveStruct[i].lastName << endl;
		}
	}



	delete MassiveStruct;


}

GROUP InitStudent()
{
	GROUP Student;
	cout << "\nEnter first name:";
	garbage_collector();
	cin.getline(Student.firstName, 50);
	cout << "Enter second name:";
	garbage_collector();
	cin.getline(Student.secondName, 50);
	cout << "Enter last name:";
	garbage_collector();
	cin.getline(Student.lastName, 50);
	cout << "Enter dateborn: ";
	garbage_collector();
	cin >> Student.Date.day >> Student.Date.month >> Student.Date.year;
	//CheckCorectDigitValue(Student.Date.day);
	garbage_collector();
	Student.averageMark = 0;
	for (size_t i = 0; i < GROUP::counSubject; i++)
	{
		Student.SES[i] = rand() % 101;
		Student.averageMark += Student.SES[i];
	}
	Student.averageMark /= GROUP::counSubject;
	return Student;

}

GROUP* InitArray(int Dimension)
{
	GROUP* Massive = new GROUP[Dimension];
	if (Massive == nullptr)
		return nullptr;
	for (size_t i = 0; i < Dimension; i++)
	{
		printf("\n]$~Enter the information about %d student ", i + 1);
		Massive[i] = InitStudent();
	}
	return Massive;
}



void DisplayArray(GROUP* Massive, int Dimension)
{
	for (size_t i = 0; i < Dimension; i++) { DisplayPerson(Massive[i]); }
}



void DisplayPerson(GROUP Man)
{
	printf("\n%s %s %s %d.%d.%d year marks{", Man.firstName, Man.secondName, Man.lastName, Man.Date.day, Man.Date.month, Man.Date.year);
	for (size_t i = 0; i < GROUP::counSubject; i++)
	{
		cout << Man.SES[i] << " ";
	}cout << "}";

}


void SortFirstName(GROUP* Massive, int Dimension)
{
	GROUP Temp;
	for (size_t i = 0; i <= Dimension; i++)
	{
		for (size_t q = Dimension - 1; q > i; q--)
		{
			if (Massive[q].averageMark > Massive[q - 1].averageMark)
			{
				Temp = Massive[q];
				Massive[q] = Massive[q - 1];
				Massive[q - 1] = Temp;
			}
		}
	}
}
int& CheckCorectDigitValue(int& value)
{
	bool flag = false;
	do {
		if (flag) {
			cout << "Please re-enter!!!";
		}flag = false;
		cin >> value;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32222, '\n');
		}
		else
		{
			return value;
		}
	} while (true);
}