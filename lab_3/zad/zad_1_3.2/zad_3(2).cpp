#include<stdio.h>
#include<locale.h>
#include<math.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int n, i, proizv = 1;
	printf("������� ���������� n: ");
	scanf_s("%d", &n);
	for (i = 1; i <= n; ++i)
		proizv *= i;
	printf("\n������������ �����: %d.\n", proizv);
	return 0;
}