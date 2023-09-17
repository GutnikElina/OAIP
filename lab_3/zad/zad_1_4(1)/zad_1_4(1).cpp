#include<stdio.h>
#include<locale.h>
#include<math.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int n, s=0, p=1, i;
	printf("Введите количество n: ");
	scanf_s("%d", &n);
	for(i=2; i<=n; i=i+2)
	s += i; 
	for (i = 2; i <= n; i = i + 2)
	p *= i;
	printf("\nCумма четных чисел равна: %d.", s);
	printf("\nПроизведение четных чисел равна: %d.\n", p);
	return 0;
}