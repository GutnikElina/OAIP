#include<stdio.h>
#include<locale.h>
#include<math.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int n, m, A, i, s = 0;
	printf("������� ����� m: ");
	scanf_s("%d.", &m);
	printf("������� ����� n: ");
	scanf_s("%d.", &n);
	for (i = 0; i <= n; ++i)
		s += i;
	A = m*n + m + s;
    printf("����� ���������: %d.\n", A);
	return 0;
}

//A = m + (m + 1) + ... + (m + n)//