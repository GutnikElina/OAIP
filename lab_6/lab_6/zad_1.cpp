#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<math.h>

void main()
{
	setlocale(LC_ALL, "Rus");
	float* arr;
	int n, kol = 0, imax=0, i;
	float pr = 1, c, max;
	printf("������� ���������� ��������� � �������: ");
	scanf_s("%d", &n);
	arr = (float*)malloc(n * sizeof(float));
	printf("������� ����� �: ");
	scanf_s("%f", &c);
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("������� %d-� ������� �������: ", i+1);
		scanf_s("%f", arr+i);
	}
	printf("\n������: \n");
	for (i = 0; i < n; i++)
	{
		printf("%.2f ", *(arr + i));
	}
	for (i = 0; i < n; i++)
	{
		if ( *(arr+i) > c)
			kol++;
	}
	printf("\n");
	if (kol == 0)
		printf("\n��� ��������� ������� ����� �.\n");
	else printf("\n���������� ��������� ������� ������� ����� �: %d.\n", kol);

	printf("\n������ ����� ��������� ��������� �� �� ������: \n");
	for (i = 0; i < n; i++)
	{
		printf("%.2f ", fabs(*(arr + i)));
	}
	printf("\n");
	max = *arr;
	for (i = 0; i < n; i++)
	{
		if (*(arr + i) > max)
		{
			max = *(arr + i);
			imax = i;
		}
	}
	for (i = imax+1; i < n; i++)
	{
		pr *= *(arr+i);
	}
	
	if (pr==1)
		printf("\n����� ������������� �� ������ �������� ��������� ���.\n");
	else printf("\n������������ ��������� �������, ������������� ����� ������������� �� ������ ��������: %.2f.\n", pr);
	free(arr);
}