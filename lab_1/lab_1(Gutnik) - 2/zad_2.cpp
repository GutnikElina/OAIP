#include<stdio.h>
#include<locale.h>
#include<math.h>

int main()
{
	setlocale(LC_ALL, "Rus");

	float a, b, c, s;
	printf("Введите катеты прямоугольного треугольника: ");
	scanf_s("%f%f", &a, &b);

	c = a * a + b * b;
	s = (a * b) / 2;

	printf("\nГипотенуза прямоугольного тругольника: %.2f.\n", sqrt(c));
	printf("Площадь прямоугольного тругольника: %.2f.\n\n", s);
	return 0;
}