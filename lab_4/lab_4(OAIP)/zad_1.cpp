#include<stdio.h>
#include<math.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int n=0, min, imin=0, max, imax=0, sum=0, p=1;
	int arr[100];
	do {
		printf("������� n ���������� ����� � ������� (<=100): ");
		scanf_s("%d", &n);
	} while (n > 100);
	for (int i = 0; i < n; i++)
	{
		printf("������� %d ������� �������: ", i+1);
		scanf_s("%d", &arr[i]);
	}
	min = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
			imin = i;
		}
	}
	max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
			imax = i;
		}
	
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", arr[i]);
		sum += arr[i];
		p *= arr[i];
	}
	printf("\n����������� �������: %d.\n", min);
	printf("������������ �������: %d.\n", max);
	arr[imin] = max;
	arr[imax] = min;
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n����� �����: %d.", sum);
	printf("\n������������ �����: %d.\n", p);
	return 0;
}