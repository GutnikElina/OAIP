/*ƒаны два массива. ћассив ј состоит из N элементов и отсортирован по возрастанию. 
ћассив B состоит из M элементов и отсорирован по убыванию. –азработать программу дл€ сли€ни€ этих массивов 
в отсортированный по возрастанию массив C.*/

//доп: сортировать главную диагональ матрицы и все параллельные ей

#include<iostream>
#include<string>
using namespace std;

int check(char* );
void choice_sort_1(int*arr, int length_of_the_array);
void choice_sort_2(int* arr, int length_of_the_array);

int main()
{
	char line_1[50];
	int amount_1, exit_1 = 1;
	do
	{
		cout << "\nEnter the number of THE FIRST array: " << endl;
		cin >> line_1;
		amount_1 = check(line_1);
		if (amount_1 != 999)
			exit_1 = 0;
	} while (exit_1);
	int* array_1 = new int[amount_1];

	char number_1[20];
	cout << "\nEnter the value of THE FIRST array elements: " ;
	for (int i = 0; i < amount_1; )
	{
		cout << "\nEnter the element array_1" << "[" << i << "]: " << endl;
		cin >> number_1;
		array_1[i] = check(number_1);
		if (array_1[i] != 999)
			i++;
	}
	cout << "---------------------------------";
	cout << "\nTHE FIRST array before sorting: " << endl;
	for (int i = 0; i < amount_1; i++)
	{
		cout << array_1[i] << "  ";
	}

	choice_sort_1(array_1, amount_1);

	cout << "\nTHE FIRST array after sorting: " << endl;
	for (int i = 0; i < amount_1; i++)
	{
		cout << array_1[i] << "  ";
	}
	cout << "\n---------------------------------" << endl;


	char line_2[50];
	int amount_2, exit_2 = 1;
	do
	{
		cout << "\nEnter the number of THE SECOND array: " << endl;
		cin >> line_2;
		amount_2 = check(line_2);
		if (amount_2 != 999)
			exit_2 = 0;
	} while (exit_2);
	int* array_2 = new int[amount_2];

	char number_2[20];
	cout << "\nEnter the value of THE SECOND array elements: ";
	for (int i = 0; i < amount_2; )
	{
		cout << "\nEnter the element array_2" << "[" << i << "]: " << endl;
		cin >> number_2;
		array_2[i] = check(number_2);
		if (array_2[i] != 999)
			i++;
	}

	cout << "---------------------------------";
	cout << "\nTHE SECOND array before sorting: " << endl;
	for (int i = 0; i < amount_2; i++)
	{
		cout << array_2[i] << "  ";
	}

	choice_sort_2(array_2, amount_2);

	cout << "\nTHE SECOND array after sorting: " << endl;
	for (int i = 0; i < amount_2; i++)
	{
		cout << array_2[i] << "  ";
	}
	cout << "\n---------------------------------" << endl;

	int amount_3 = amount_1 + amount_2;
	int* array_3 = new int[amount_3];
	for (int i = 0; i < amount_1; i++)
		array_3[i] = array_1[i];
	for (int i = amount_1; i < amount_3; i++)
		array_3[i] = *array_2++;

	cout << ">> Let's combine THE FIRST and SECOND arrays into one <<" << endl;
	cout << "\nTHE THIRD array before sorting: " << endl;
	for (int i = 0; i < amount_3; i++)
	{
		cout << array_3[i] << "  ";
	}

	choice_sort_1(array_3, amount_3);

	cout << "\nTHE THIRD array after sorting: " << endl;
	for (int i = 0; i < amount_3; i++)
	{
		cout << array_3[i] << "  ";
	}
	cout << "\n---------------------------------" << endl;

}

void choice_sort_1(int* arr, int length_of_the_array)
{
	for (int counter = 0; counter < length_of_the_array; counter++)
	{
		int temp = arr[0];
		for (int element_counter = counter + 1; element_counter < length_of_the_array; element_counter++)
		{
			if (arr[counter] > arr[element_counter])
			{
				temp = arr[counter];
				arr[counter] = arr[element_counter];
				arr[element_counter] = temp;
			}
		}
	}
}

void choice_sort_2(int* arr, int length_of_the_array)
{
	for (int counter = 0; counter < length_of_the_array; counter++)
	{
		int temp = arr[0];
		for (int element_counter = counter + 1; element_counter < length_of_the_array; element_counter++)
		{
			if (arr[counter] < arr[element_counter])
			{
				temp = arr[counter];
				arr[counter] = arr[element_counter];
				arr[element_counter] = temp;
			}
		}
	}
}

int check(char*ch)
{
	int chislo=0;
	bool isbreak = false;
	for (int i = 0; i < strlen(ch); i++)
	{
		if (ch[i] < 48 || ch[i]>57)
			isbreak = true;
	}
	if (isbreak)
	{
		cout << "\n-!!!- The entered choice isn't valid.Try again -!!!-" << endl;
	    chislo = 999;
		return chislo;
	}
	else
		chislo = atoi(ch);
	return chislo;
}
