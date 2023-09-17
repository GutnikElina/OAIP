#include<stdio.h>
#include<locale.h>
#include<conio.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int n, m, i, j;
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
		for (j = 0; j < m; j++)
		{
			printf("Введите элемент [%d,%d]: \n", i + 1, j + 1);
			scanf_s("%d", &arr[i][j]);
		}
	}

	printf("\nМАТРИЦА: \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	int kol = m;
	for (j = 0; j < m; j++)
	{
		for (i = 0; i < n; i++)
		{
			if (arr[i][j] == 0)
			{
				kol--;
				break;
			}
		}
	}
	printf("Количество столбцов, не содержащих ноль: %d.\n", kol);
	return 0;
}
