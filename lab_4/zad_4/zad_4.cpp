#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int min = 0, imin = 0, max = 0, imax = 0, pol1 = 0, otr1 = 0, ipol1 = 0, iotr1 = 0, sum = 0;
	int arr[25];
	srand(time(NULL));
	for (int i = 0; i < 25; i++)
	{
		arr[i] = rand() % 100 - 50 ;
	}
	for (int i = 0; i < 25; i++)
	{
		printf("%d ", arr[i]);
	}
	for (int i = 0; i < 25; i++)
	{
		if (arr[i] > 0)
		{
			pol1 = arr[i];
			ipol1 = i;
			break;
		}
	}
	printf("\n1 положительный равен %d\n", pol1);
	printf("Ќомер 1 положительного равен %d\n", ipol1);

	for (int i = 0; i < 25; i++)
	{
		if (arr[i] < 0)
		{
			otr1 = arr[i];
			iotr1 = i;
			break;
		}
	}
	printf("\n1 отрицательный равен %d\n", otr1);
	printf("Ќомер 1 отрицательного равен %d\n", iotr1);

	arr[ipol1] = pol1 * otr1;
	arr[iotr1] = pol1 + otr1;
	for (int i = 0; i < 25; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

