#include<stdio.h>
#include<locale.h>
#include<math.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int n, m, B=1, i=0;
	printf("������� ����� m: ");
	scanf_s("%d.", &m);
	printf("������� ����� n: ");
	scanf_s("%d.", &n);
	while (i <= n)
	{
		B *= (m + i);
		++i;
    }
	printf("����� ���������: %d.\n", B);
	return 0;
}

/*B=m*(m+1)*...*(m+n)*/