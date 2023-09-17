#include<stdio.h>
#include<math.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int n = 0, min = 0, imin = 0, max = 0, imax = 0, pol1=0, pol2=0, ipol1=0, ipol2=0, sum=0;
	int arr[100];
	do {
		printf("Введите n количество чисел в массиве (<=100): ");
		scanf_s("%d", &n);
	} while (n > 100);
	for (int i = 0; i < n; i++)
	{
		printf("Введите %d элемент массива: ", i + 1);
		scanf_s("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[i]>0)
		{
			pol1 = arr[i];
			ipol1 = i;
			break;
		}
	}
	printf("1 положительный равен %d\n", pol1);
	for (int i=ipol1+1; i < n; i++)
	{
		if (arr[i]>0)
		{
			pol2 = arr[i];
			ipol2 = i;
			break;
		}
	}
	printf("2 положительный равен %d\n", pol2);
	
	for (int i = ipol1+1; i < ipol2; i++)
	{
		sum += arr[i];
	}
	printf("Сумма элементов между положительными числами равна %d.\n", sum);
	max = arr[0];
	for (int i = 0; i < n; i++)
	{
		arr[i] = abs(arr[i]);
	}
	for (int i = 0; i < n; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
			imax = i;
		}

	}
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\nМаксимальный элемент: %d.\n", max);
	return 0;
}