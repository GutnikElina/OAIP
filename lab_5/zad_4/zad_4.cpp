#include<stdio.h>
#include<locale.h>
#include<math.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int n, m, i, j, sum = 0, x, min = 0, sum1 = 0;
	int arr[30][30];
	do
	{
		printf("������� ���������� �����/�������� � ���������� �������(<30): \n");
		scanf_s("%d", &n);
	} while (n >= 30);
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
	for (j = 0; j < n; j++)
	{
		sum = 0;
		bool pol = true;
		for (i = 0; i < n; i++)
		{
			sum += arr[i][j];
			if (arr[i][j] < 0) pol = false;

		}
		if (pol) printf("\n����� ��������� ������� � %d-� �������, �� ���������� ������������� ���������: %d.\n", j+1, sum);
	}
	printf("\n������� ����� ��������� ��������� �� �� ������: \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", abs(arr[i][j]));
			arr[i][j] = abs(arr[i][j]);
		}
		printf("\n");
	}
	min = arr[0][0];
	for (x = 0; x < n+n; x++)                       //x - ���������� � ������� ������� ����� ������ ����������� ����� ������� ������ � ������� ������� 
	{
			sum=0;
			for (i = 0; i < n; i++)
			{
				if ((x - i < n)&&(x-i>=0))
				{
					sum += abs(arr[i][x - i]);
					sum1 = sum;
				}
			}
			if (min > sum1)
				min = sum1;
	}
	printf("\n����������� ����� ������� ��������� ����������, ������������ �������� ��������� �������: %d.\n", min);
	return 0; 
}
