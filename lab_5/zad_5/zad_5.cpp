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
		printf("������� n ���������� ����� � �������(<30): \n");
		scanf_s("%d", &n);
	} while (n >= 30);
	do
	{
		printf("������� m ���������� �������� � �������(<30): \n");
		scanf_s("%d", &m);
	} while (m >= 30);
	printf("\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("������� ������� [%d,%d]: \n", i + 1, j + 1);
			scanf_s("%d", &arr[i][j]);
		}
	}

	printf("\n�������: \n");
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
	printf("\n����� ������������ ����� ������ ������: %d.\n", sum);
	
	arr[n-1][m-1] = sum;
	printf("\n������� ����� ������������ ����� � �����: \n");
	for (i = 0; i < n; i++)
	{ 
		for (j = 0; j < n; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n���������� ������ ������ ����� �������: \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (arr[i][j] % 2 == 0) printf("%d  ", arr[i][j]);
		}
	}
	printf("\n���������� ������ �������� ����� �������: \n");
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