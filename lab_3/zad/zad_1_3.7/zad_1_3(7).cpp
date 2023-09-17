#include<stdio.h>
#include<locale.h>
#include<math.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int n, i = 1, summa = 0, a = 1;
	printf("¬ведите количество n: ");
	scanf_s("%d", &n);
	while (i <= n)
	{
		a *= i;
		summa += a;
		++i;
	}
	printf("\n—умма: %d\n", summa);
	return 0;
}
/*S=1+1*2+1*2*3+1*2*3*4+...+1*2*3*...*n*/