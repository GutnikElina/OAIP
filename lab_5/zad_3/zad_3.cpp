#include<stdio.h>
#include<locale.h>
#include<conio.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int n, m, i, j, ipol, k=0, t=0;
	int arr[30][30];
	do
	{
		printf("Введите n количество строк в массиве(<=30): \n");
		scanf_s("%d", &n);
	} while (n > 30);
	do
	{
		printf("Введите m количество столбцов в массиве(<=30): \n");
		scanf_s("%d", &m);
	} while (m > 30);
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

	for (i = 0; i < n; i++)
	{
		k = 0;
		for (j = 0; (j < m) && (k==0); j++)
		{
			if (arr[i][j] > 0)
			{
				printf("\nВ строке %d содержится положительный элемент.\n", i + 1); 
				k++; 
				t++;
				if (i > 0)
				{
					for ( j = 0; j < m; j++)
					{
						arr[i - 1][j] *= -1;
					}
				}
				
			}
		}
	}
	printf("\nМАТРИЦА после изменения знаков: \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	if (t == 0) printf("\nВ матрице нет строк, содержащих положительные элементы. \n");
	return 0;
}