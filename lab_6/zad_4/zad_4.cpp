#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<math.h>
#include<time.h>

int main()
{
	setlocale(0, "");
	srand(time(NULL));
	float** arr;
	int n, i, j;
	float sum;
	printf("Введите количество команд: ");
	scanf_s("%d", &n);
	arr = (float**)malloc(n * sizeof(float*));
	for (i = 0; i < n; i++)
		*(arr + i) = (float*)malloc(5* sizeof(float));
	printf("\n");

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 5; j++)
		{
			*(*(arr + i) + j) = (float)(rand()%6)/3 + 1,5;
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("\nРезультаты %d-й команды: \n", i + 1);
			for (j = 0; j < 5; j++)
			{
				printf("%.2f ", *(*(arr + i) + j));
			}
			printf("\n");
	}
	float max = 0;
	int imax = 0;
	for (i = 0; i < n; i++)
	{
		sum = 0;
		for (j = 0; j < 5; j++)
		{
			sum+= *(*(arr + i)+j);
		}
		if (sum > max)
		{
			max = sum;
			imax = i;
		}
	}
	printf("\nПервое место заняла команда №%d. Результат - %.3f.\n", imax+1, max);
	for (j = 0; j < 5; j++)
	{
		*(*(arr + imax) + j) = 0;
	}

	max = 0;
	imax = 0;
	for (i = 0; i < n; i++)
	{
		sum = 0;
		for (j = 0; j < 5; j++)
		{
			sum += *(*(arr + i) + j);
		}
		if (sum > max)
		{
			max = sum;
			imax = i;
		}
	}
	printf("\nВторое место заняла команда №%d. Результат - %.3f.\n", imax + 1, max);
	for (j = 0; j < 5; j++)
	{
		*(*(arr + imax) + j) = 0;
	}

	max = 0;
	imax = 0;
	for (i = 0; i < n; i++)
	{
		sum = 0;
		for (j = 0; j < 5; j++)
		{
			sum += *(*(arr + i) + j);
		}
		if (sum > max)
		{
			max = sum;
			imax = i;
		}
	}
	printf("\nТретье место заняла команда №%d. Результат - %.3f.\n", imax + 1, max);
	for (j = 0; j < 5; j++)
	{
		*(*(arr + imax) + j) = 0;
	}

	free(arr);
	return 0;
}