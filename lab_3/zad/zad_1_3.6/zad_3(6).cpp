#include<stdio.h>
#include<locale.h>
#include<math.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	float m, summa = 0;
	int n, i;
	printf("������� ����� m: ");
	scanf_s("%f.", &m);
	printf("������� ���������� n: ");
	scanf_s("%d", &n);
	for (i = 0; i <= n; ++i)
		summa += 1/(m+i);
	printf("�����: %f\n", summa);
	return 0;
}

/*X=1/m+1/(m+1)+...+1/(m+n)*/