#include<stdio.h>
#include<locale.h>
#include<conio.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int n, m, i, j, imax = 0, jmax = 0, imin = 0, jmin = 0;
	float sum = 0, max, min;
	float arr[30][30], arr_min;
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
		for (j = 0; j < m; j++)
		{
			printf("Введите элемент [%d,%d]: \n", i + 1, j + 1);
			scanf_s("%f", &arr[i][j]);
		}
	}

	printf("\nМАТРИЦА: \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%.1f ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (i = 0; i < n; i++)
	{
		sum += arr[i][i];
	}
	printf("Сумма элементов массива на главной диагонали: %.2f.\n", sum);

	max = arr[0][0];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (max < arr[i][j])
			{
				max = arr[i][j];
				imax = i;
				jmax = j;
			}
		}
	}
	min = arr[0][0];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (min > arr[i][j])
			{
				min = arr[i][j];
				imin = i;
				jmin = j;
			}
		}
	}
	printf("Минимальный элемент массива: %.1f.\n", min);
	printf("Максимальный элемент массива: %.1f.\n", max);

	arr_min = arr[imin][jmin];
	arr[imin][jmin] = arr[imax][jmax];
	arr[imax][jmax] = arr_min;

	printf("\nМАТРИЦА после перестановки: \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%.1f ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
