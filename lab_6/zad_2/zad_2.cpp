#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int** arr;
	int n, m, i, j;
	printf("Введите n количество строк в массиве: \n");
	scanf_s("%d", &n);
	printf("Введите m количество столбцов в массиве: \n");
	scanf_s("%d", &m);
	arr = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++)
		*(arr+i) = (int*)malloc(m * sizeof(int));
	printf("\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("Введите элемент [%d,%d]: \n", i + 1, j + 1);
			scanf_s("%d", *(arr+i)+j);
		}
	}
	printf("\nМАТРИЦА: \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d ", *(*(arr+i)+j));
		}
		printf("\n");
	}

	int kol = 0;
	for (j = 0; j < m; j++)
	{
		for (i = 0; i < n; i++)
		{
			if (*(*(arr + i) + j) == 0)
			{
				kol++;
				break;
			}
		}
	}
	printf("\nКоличество столбцов, содержащих ноль: %d.\n", kol);

	int nom, k=0, kolich=0, ikol=0;
	for (i = 0; i < n; i++)
	{
		k = 0;

		for (j = 0; j < m; j++)
		{
			if (*(*(arr + i) + j) == *(*(arr + i) + j+1))
				k++;
		}
		if (kolich < k)
		{
			kolich = k;
			ikol = i;
		}
	}
	if (k==0) printf("\nНет строки, в которой находится серия одинаковых элементов.\n");
	else printf("\nНомер строки, в которой находится самая длинная серия одинаковых элементов: %d.\n", ikol+1);

	return 0;
}
