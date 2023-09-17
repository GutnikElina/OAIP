#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int** arr;
	int n, i, j, k=0;
	printf("Введите количество строк/столбцов в квадратной матрице: \n");
	scanf_s("%d", &n);

	arr = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++)
		*(arr + i) = (int*)malloc(n * sizeof(int));
	printf("\n");

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("Введите элемент [%d,%d]: \n", i + 1, j + 1);
			scanf_s("%d", *(arr + i) + j);
		}
	}
	printf("\nМАТРИЦА: \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", *(*(arr + i) + j));
		}
		printf("\n");
	}

	for (i = 0; (i < n) && (k==0); i++)
	{
		for (j = 0; (j < n) && (k==0); j++)
		{
			if (*(*(arr + i) + j) != *(*(arr + j) + i))
				k++;
		}
	}
	if (k == 0) printf("\nКвадратная матрица является симметричной относительно главной диагонали.\n");
	else printf("\nКвадратная матрица не является симметричной относительно главной диагонали.\n");
	printf("\n");
	return 0;
}
