#include<stdio.h>
#include<locale.h>
#include<math.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	float n, i, summa = 0;
	printf("������� ���������� n: ");
	scanf_s("%f", &n);
	for (i = 1; i <= n; ++i)
		summa += (1 / i);
	printf("�����: %f\n", summa);
	return 0;
}