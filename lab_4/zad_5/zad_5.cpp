#include<iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int ch, sum=0;
	cout << "¬ведите число: ";
	cin >> ch;

	for (int i = 0; ch / 10 >= 0; i++)
	{
		sum += ch % 10;
		ch = (ch - ch % 10) / 10;
		if (ch == 0)
		{
			break;
		}
	}
	cout << "—умма равна " << sum << endl;
}