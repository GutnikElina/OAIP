#include <iostream>
#include<string>
#include "Header.h"

using namespace std;
int check(string ch);

int main()
{
	string line;
	int choice;
	do {
		cout << "\n1. Enter information.\n" << "2. Read all information.\n";
		cout << "3. Read someone's information by phone number.\n";
		cout << "4. Sort by birthday.\n" << "5. Read information by first litter and phone number. \n" << "6. Quit from the programm.\n";
		do
		{
			cout << "Enter your choice: ";
			cin >> line;
			choice = check(line);
		} while (choice == 999);

		switch (choice)
		{
		case 1: enter_new();
			break;
		case 2: print();
			break;
		case 3: read();
			break;
		case 4: sort_birthday();
			break; 
		case 5: read_litter();
			break;
		case 6: return 0; break;
		default: 
			cout << "\n-!!!-The entered choice doesn't exist. Try again -!!!-\n";
		}
	} while (choice != 5);
	return 0;
}
