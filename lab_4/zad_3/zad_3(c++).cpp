#include<iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int n = 0;
	double* arr;
	cout << "Введите n количество чисел в массиве: ";
	cin >> n;

	arr = new double[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Введите " << i+1 << " элемент массива: ";
		cin >> arr[i];
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (arr[i] == 1 / arr[j])
			{
				cout <<"В массиве имеются взаимно обратные числа "<< arr[i] << " и " << arr[j] << endl;

			}
		}
	}
	delete [] arr;
}