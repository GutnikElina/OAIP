//Написать следующие функции для работы со списками
//countList - функция подсчета числа элементов
//findMax - Функция поиска максимального элемента списка
//findMin - функция поиска минимального элемента списка
//deleteDouble - функция удаления повторяющихся элементов в списке
//deleteList - функция удаления списка

#include<iostream>
#include<string>
#include<iomanip>
#include<windows.h>
#define _XM_NO_INTRINSICS_
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

struct reader
{
	string surname{};
	string name{};
	string patronymic{};
	int idTicket{};
	string book{};
	int day{};
	int month{};
	int year{};
	reader* next;
};

typedef struct reader person;
typedef person* readerPtr;
void menu(void);
void enter_new(readerPtr& first, readerPtr& last);
int countList(readerPtr first);
void findMax(readerPtr first);
void findMin(readerPtr first);
void deleteDouble(readerPtr &first);
void deleteList(readerPtr & first);
void printList(readerPtr first);
int continue_or_not();
int check(string);

int main()
{
	readerPtr first = nullptr;
	readerPtr last = nullptr;
	int choice;
	string line;
	do
	{
		do
		{
			menu();
			cout << "\nEnter your choice: ";
			cin >> line;
			choice = check(line);
		} while (choice == 999);

		switch (choice)
		{
		case 1: enter_new(first, last);
			break;
		case 2: 
			cout << "The amount of the readers in list is " << countList(first) << ".\n";
			break;
		case 3:
			findMax(first);
			break;
		case 4:
			findMin(first);
			break;
		case 5:
			deleteDouble(first);
			break;
		case 6:
			deleteList(first);
			break;
		case 7: 
			printList(first);
			break;
		case 8: return 0; break;
		default:
			cout << "\n-!!!-The entered choice doesn't exist. Try again -!!!-\n";
		}
	} while (choice != 9);
}

void menu(void)
{
	cout << setw(30) << "MENU\n";
	cout << "----------------------------------------------------------\n";
	cout << "1. Add element\n";
	cout << "2. Count the number of elements\n";
	cout << "3. Find the latest deadline for the book return\n";
	cout << "4. Find the earliest deadline for the book return\n";
	cout << "5. Delete duplicate elements\n";
	cout << "6. Delete the list\n";
	cout << "7. Print the list\n";
	cout << "8. Exit\n";
}

void enter_new(readerPtr& first, readerPtr& last)
{
	int choice;
	int a;
	string line;
	do
	{
		readerPtr newPerson = new person;
		string line1, line2, line3, line4;
		int ex;
		cout << "\nEnter surname: ";
		cin >> newPerson->surname;
		cout << "Enter name: ";
		cin >> newPerson->name;
		cout << "Enter patronymic: ";
		cin >> newPerson->patronymic;
		do
		{
			ex = 0;
			cout << "Enter reader ticket number: ";
			cin >> line1;
			a = check(line1);
			if (a == 999)
				ex = 1;
			else newPerson->idTicket = a;
		} while (ex);
		cout << "Enter book title: ";
		cin >> newPerson->book;
		do
		{
			ex = 0;
			cout << "Enter return day: ";
			cin >> line2;
			a = check(line2);
			if (a == 999)
				ex = 1;
			else newPerson->day = a;
		} while (ex);
		do
		{
			ex = 0;
			cout << "Enter return month: ";
			cin >> line3;
			a = check(line3);
			if (a == 999)
				ex = 1;
			else newPerson->month = a;
		} while (ex);
		do
		{
			ex = 0;
			cout << "Enter return year: ";
			cin >> line4;
			a = check(line4);
			if (a == 999)
				ex = 1;
			else newPerson->year = a;
		} while (ex);
	
		newPerson->next = nullptr;
		if (first == nullptr)
		{
			first = last = newPerson;
		}
		else {
			last->next = newPerson;
			last = newPerson;
		}
		choice = continue_or_not();
	} while (choice);
}

int countList(readerPtr first) 
{
	int ammount = 0;
	readerPtr current = first;
	while (current != nullptr) {
		ammount++;
		current = current->next;
	}
	return ammount;
}

void findMax(readerPtr first)
{
	if (first == nullptr) {
		cout << "The list is an emty.\n";
	}
	else {
		readerPtr current = first;
		readerPtr max = first;
		while (current != nullptr) 
		{
			if (current->year >= max->year)
				max = current;
			else if
				(current->year == max->year && current->month >= max->month)
				max = current;
			else if
				(current->year == max->year && current->month == max->month &&
					current->day >= max->day)
				max = current;

			current = current->next;
		}
		
		cout << "The latest deadline for the book return:\n";
		cout << max->surname << "\n";
		cout << max->name << "\n";
		cout << max->patronymic << "\n";
		cout << max->idTicket << "\n";
		cout << max->book << "\n";
		cout << max->day << ".";
		cout << max->month << ".";
		cout << max->year << "\n\n";
	}
}

void findMin(readerPtr first)
{
	if (first == nullptr) {
		cout << "The list is an emty.\n";
	}
	else 
	{
		readerPtr current = first;
		readerPtr min = first;
		while (current != nullptr) {
			if (current->year <= min->year)
				min = current;
			else if 
				(current->year == min->year && current->month <= min->month) 
				min = current;
			else if
				(current->year == min->year && current->month == min->month &&
					current->day <= min->day)
				min = current;
	
			current = current->next;
		}

		cout << "The earliest deadline for the book return:\n";
		cout << min->surname << "\n";
		cout << min->name << "\n";
		cout << min->patronymic << "\n";
		cout << min->idTicket << "\n";
		cout << min->book << "\n";
		cout << min->day << ".";
		cout << min->month << ".";
		cout << min->year << "\n\n";
	}
}

void deleteDouble(readerPtr &first)
{
	if (first == nullptr) 
	{
		cout << "The list is an emty.\n";
	}
	else {
		readerPtr current = first;
		while (current != nullptr) {
			readerPtr temp = current;
			while (temp->next != nullptr) 
			{
				if (current->surname.compare(temp->next->surname) == 0 &&
					current->name.compare(temp->next->name) == 0 &&
					current->patronymic.compare(temp->next->patronymic) == 0 &&
					current->book.compare(temp->next->book) == 0 &&
					current->idTicket == temp->next->idTicket &&
					current->day == temp->next->day && 
					current->month == temp->next->month && 
					current->year == temp->next->year)
				{
					readerPtr deletePerson = temp->next;
					temp->next = deletePerson->next;
					delete deletePerson;
				}
				else 
					temp = temp->next;
			}
			current = current->next;
		}
		cout << "Done! \n";
	}
}

void deleteList(readerPtr& first)
{
	readerPtr temp;
	while (first != nullptr) 
	{
		temp = first;
		first = first->next;
		delete temp;
	}
	cout << "The list is an empty! \n";
}

void printList(readerPtr first)
{
	if (first == nullptr)
		cout << " -!!!- The list is an empty -!!!-\n\n";
	else
	{
		cout << "The list is: \n";
		readerPtr current = first;
		while (current != nullptr)
		{
			cout << current->surname << "\n";
			cout << current->name << "\n";
			cout << current->patronymic << "\n";
			cout << current->idTicket << "\n";
			cout << current->book << "\n";
			cout << current->day << ".";
			cout << current->month << ".";
			cout << current->year << "\n\n";
			current = current->next;
		}
	}
}

int check(string ch)
{
	int chislo = 0;
	bool isbreak = false;
	char line[30]{};
	for (int i = 0; i < ch.length(); i++)
	{
		if ((ch[i] < 48 || ch[i]>57) && ch[i] != 43)
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

int continue_or_not()
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
