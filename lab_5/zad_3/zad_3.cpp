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
		printf("������� n ���������� ����� � �������(<=30): \n");
		scanf_s("%d", &n);
	} while (n > 30);
	do
	{
		printf("������� m ���������� �������� � �������(<=30): \n");
		scanf_s("%d", &m);
	} while (m > 30);
	printf("\n");

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("������� ������� [%d,%d]: \n", i + 1, j + 1);
			scanf_s("%d", &arr[i][j]);
		}
	}

	printf("\n�������: \n");
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
				printf("\n� ������ %d ���������� ������������� �������.\n", i + 1); 
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
	printf("\n������� ����� ��������� ������: \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	if (t == 0) printf("\n� ������� ��� �����, ���������� ������������� ��������. \n");
	return 0;
}