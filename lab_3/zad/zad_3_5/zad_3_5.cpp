#include <stdio.h>			
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int a, i, k;
	for (i = 11; i <= 31; i++)
	{
			k = i % 10;
			if ((k == 1) || (k == 3) || (k == 7))
			{
				a = i * i; 
					if ((a % 10 > ((a % 100 - a % 10) / 10)) && (((a % 100 - a % 10) / 10) > a / 100))
					printf("Число равно %d.\n", a);
				}
	}
	return 0;
}

