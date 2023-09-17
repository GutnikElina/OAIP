#include<stdio.h>
#include<locale.h>
#include<math.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int n, m, i, j, sum = 0, k = 0, max;
	int arr[30][30];
	do
	{
		printf("Введите n количество строк в массиве(<30): \n");
		scanf_s("%d", &n);
	} while (n >= 30);
	do
	{
		printf("Введите m количество столбцов в массиве(<30): \n");
		scanf_s("%d", &m);
	} while (m >= 30);
	printf("\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("Введите элемент [%d,%d]: \n", i + 1, j + 1);
			scanf_s("%d", &arr[i][j]);
		}
	}

	printf("\nМАТРИЦА: \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < n; i++)
	{
		max = arr[i][0];
		for (j = 0; j < n; j++)
		{
			if (max < arr[i][j]) max = arr[i][j];
		}
		sum += max;
	}
	printf("\nСумма максимальных чисел каждой строки: %d.\n", sum);
	
	arr[n-1][m-1] = sum;
	printf("\nМАТРИЦА после перестановки суммы в конец: \n");
	for (i = 0; i < n; i++)
	{ 
		for (j = 0; j < n; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\nОдномерный массив четных чисел матрицы: \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (arr[i][j] % 2 == 0) printf("%d  ", arr[i][j]);
		}
	}
	printf("\nОдномерный массив нечетных чисел матрицы: \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (arr[i][j] % 2 != 0) printf("%d  ", arr[i][j]);
		}
	}
	printf("\n");
		return 0;
}