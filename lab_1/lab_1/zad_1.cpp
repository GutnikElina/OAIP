#include<stdio.h>
#include<locale.h>
#include<math.h>

int main()
{
	setlocale(LC_ALL, "Rus");

	float x, y;
	printf("Введите значение переменной x: ");
	scanf_s("%f", &x);
	printf("Вы ввели значение переменной x.\n\n");

	y = x * (sin(x) + exp(-(x + 3)));

	printf("Значение заданного выражения: y=%f.\n\n", y);

	return 0;
}