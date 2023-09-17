#include<stdio.h>
#include<locale.h>
#include<math.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int n, i, proizv = 1;
	printf("Введите количество n: ");
	scanf_s("%d", &n);
	for (i = 1; i <= n; ++i)
		proizv *= i;
	printf("\nПроизведение равно: %d.\n", proizv);
	return 0;
}