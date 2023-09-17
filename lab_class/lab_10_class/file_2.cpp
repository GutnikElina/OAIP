//Описать структуру с именем NOTE, содержащую следующие поля : фамилия, имя; номер телефона; 
//день рождения(массив из трех чисел).Написать программу, выполняющую следующие действия : 
//ввод с.клавиатуры данных в массив, состоящий из восьми элементов типа NOTE; упорядочивать 
//записи по датам дней рождения; вывод на экран информации о человеке, номер телефона которого 
//введен с клавиатуры; если такого нет, выдать на дисплей соответствующее сообщение.

#include<iostream>
#include<string>
#include<iomanip>
#include "Header.h"

using namespace std;
int check(string ch);

struct NOTE
{
	string surname{};
	string name{};
	string phoneNumber{};
	int birthDay{};
	int birthMonth{};
	int birthYear{};
}person[8];

int amount=0;

extern void enter_new()
{
	int exit = 1;
	while (exit)
	{
		string line1, line2, line3, line4;
		int ex = 1;
		cout << "\nEnter surname: ";
		cin >> person[amount].surname;
		cout << "Enter name: ";
		cin >> person[amount].name;
		do
		{
			ex = 0;
			cout << "Enter phoneNumber: ";
			cin >> line1;
			if (check(line1) == 999)
				ex = 1;
			else person[amount].phoneNumber = line1;
		} while (ex);
		cout << "\nPrint your birthday date by example: dd.mm.yyyy\n";
		do
		{
			cout << "Enter day of your birthday: ";
			cin >> line2;
			if (line2.length()!= 2)
			{
				cout << "-!!!- This day doesn't exist -!!!-\n";
				person[amount].birthDay = 999;
			}
			else { 
				person[amount].birthDay = check(line2); 
			}
		} while (person[amount].birthDay == 999);
		do
		{
			cout << "Enter month of your birthday: ";
			cin >> line3;
			if (line3.length() != 2)
			{
				cout << "-!!!- This month doesn't exist -!!!-\n";
				person[amount].birthMonth = 999;
			}
			else {
				person[amount].birthMonth = check(line3);
			}
		} while (person[amount].birthMonth == 999);
		do
		{
			cout << "Enter year of your birthday: ";
			cin >> line3;
			if (line3.length() != 4)
			{
				cout << "-!!!- This year doesn't exist -!!!-\n";
				person[amount].birthYear = 999;
			}
			else {
				person[amount].birthYear = check(line3);
			}
		} while (person[amount].birthYear == 999);

		amount++;

		exit = continue_or_not();
	}
}

extern void print()
{
	if (amount == 0)
		cout << "\n---No notes---\n";
	else
	{
		cout << "\n" << setw(15) << "SURNAME" << setw(10) << "NAME" << setw(15) << "PHONENUMBER" << setw(15) << "BIRTHDAY";
		cout << "\n*******************************************************" << endl;
		for (int counter = 0; counter < amount; counter++)
		{
			cout << "\n №" << counter + 1 << setw(10) << person[counter].surname << setw(10);
			cout << person[counter].name << setw(15) << person[counter].phoneNumber;
			cout << setw(7) << person[counter].birthDay << "." << person[counter].birthMonth;
			cout << "." << person[counter].birthYear;
		}
	cout << endl;
	}
}

extern void sort_birthday()
{
	if (amount == 0)
		cout << "\n---No notes---\n";
	else
	{
		int idx;
		for (int i = 0; i < amount - 1; i++) {
			idx = i;
			for (int j = i + 1; j < amount; j++) {
				if (person[j].birthYear > person[idx].birthYear) {
					idx = j;
				}
				else if (person[j].birthYear == person[idx].birthYear &&
					person[j].birthMonth > person[idx].birthMonth) {
					idx = j;
				}
				else if (person[j].birthYear == person[idx].birthYear &&
					person[j].birthMonth == person[idx].birthMonth &&
					person[j].birthDay > person[idx].birthDay) {
					idx = j;
				}
			}
			swap(person[idx], person[i]);
		}
		cout << "\nSort by birthday is completed!\n";
	}
}

extern int read()
{
	cout << "\nEnter phone number:\n";
	string choice;
	cin >> choice;
	for (int i = 0; i < amount; i++)
	{
		if (choice == person[i].phoneNumber)
		{
			cout << "\n" << setw(15) << "SURNAME" << setw(10) << "NAME" << setw(15) << "PHONENUMBER" << setw(15) << "BIRTHDAY";
			cout << "\n*******************************************************" << endl;
			cout << "\n №" << i + 1 << setw(10) << person[i].surname << setw(10);
			cout << person[i].name << setw(15) << person[i].phoneNumber;
			cout << setw(7) << person[i].birthDay << "." << person[i].birthMonth;
			cout << "." << person[i].birthYear;
			cout << "\n";
			return 0;
		}
	}
	cout << "\nThis phone number doesn't exist!\n";
}

extern int read_litter()
{
	cout << "\nEnter the fist litter of the name: \n";
	char litter[10]{};
	cin >> litter;
	cout << "\nEnter phone number:\n";
	string choice;
	cin >> choice;
	for (int i = 0; i < amount; i++)
	{
		if ((choice == person[i].phoneNumber)&&(litter[0]==person[i].name[0]))
		{
			cout << "\n" << setw(15) << "SURNAME" << setw(10) << "NAME" << setw(15) << "PHONENUMBER" << setw(15) << "BIRTHDAY";
			cout << "\n*******************************************************" << endl;
			cout << "\n №" << i + 1 << setw(10) << person[i].surname << setw(10);
			cout << person[i].name << setw(15) << person[i].phoneNumber;
			cout << setw(7) << person[i].birthDay << "." << person[i].birthMonth;
			cout << "." << person[i].birthYear;
			cout << "\n";
			return 0;
		}
	}
	cout << "\nThis person doesn't exist!\n";
}


extern int continue_or_not()
{
	int exit = 1;
	int ch;
	int MAX;
	char line[20]{};
	do
	{
		cout << "---------------------\n" << "\tDo you want to continue?\nIf yes, then click - 1; if no, click - 0.\n";
		cin >> line;
		MAX = strlen(line);
		ch = check(line);
		if (ch != 999)
		{
			if (MAX == 1 && line[0] == '1')
				return 1;
			else if (MAX == 1 && line[0] == '0')
				return 0;
		}
	} while (exit);
	return 0;
}

int check(string ch)
{
	int chislo = 0;
	bool isbreak = false;
	char line[30]{};
	for (int i = 0; i < ch.length(); i++)
	{
		if ((ch[i] < 48 || ch[i]>57)&& ch[i]!=43 )
			isbreak = true;
	}
	if (isbreak)
	{
		cout << "\n-!!!- The entered choice isn't valid.Try again -!!!-\n\n";
		chislo = 999;
		return chislo;
	}
	else
	{
		for (int i = 0; i < ch.length(); i++)
		{
			line[i] = ch[i];
		}
		chislo = atoi(line);
	}
	return chislo;
}

