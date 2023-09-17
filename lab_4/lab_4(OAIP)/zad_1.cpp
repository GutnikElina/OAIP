#include<stdio.h>
#include<math.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int n=0, min, imin=0, max, imax=0, sum=0, p=1;
	int arr[100];
	do {
		printf("Введите n количество чисел в массиве (<=100): ");
		scanf_s("%d", &n);
	} while (n > 100);
	for (int i = 0; i < n; i++)
	{
		printf("Введите %d элемент массива: ", i+1);
		scanf_s("%d", &arr[i]);
	}
	min = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
			imin = i;
		}
	}
	max = arr[0];
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
		sum += arr[i];
		p *= arr[i];
	}
	printf("\nМинимальный элемент: %d.\n", min);
	printf("Максимальный элемент: %d.\n", max);
	arr[imin] = max;
	arr[imax] = min;
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\nСумма равна: %d.", sum);
	printf("\nПроизведение равна: %d.\n", p);
	return 0;
}