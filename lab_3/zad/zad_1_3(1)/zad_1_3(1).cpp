#include<stdio.h>
#include<locale.h>
#include<math.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int n, i, s = 0;
	printf("������� ���������� n: ");
	scanf_s("%d", &n);
	for (i = 0; i <= n; ++i)
		s += i;
	printf("\n����� �����: %d.\n", s);
	return 0;
}