#include<stdio.h>
#include<locale.h>
#include<math.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int n, s = 0, p = 1, i;
	printf("������� ���������� n: ");
	scanf_s("%d", &n);
	for (i = 3; i <= n; i = i + 3)
		s += i;
	for (i = 3; i <= n; i = i + 3)
		p *= i;
	printf("\nC���� ������� 3 ����� �����: %d.", s);
	printf("\n������������ ������� 3 ����� �����: %d.\n", p);
	return 0;
}