#include<iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int n = 0;
	double* arr;
	cout << "������� n ���������� ����� � �������: ";
	cin >> n;

	arr = new double[n];
	for (int i = 0; i < n; i++)
	{
		cout << "������� " << i+1 << " ������� �������: ";
		cin >> arr[i];
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (arr[i] == 1 / arr[j])
			{
				cout <<"� ������� ������� ������� �������� ����� "<< arr[i] << " � " << arr[j] << endl;

			}
		}
	}
	delete [] arr;
}