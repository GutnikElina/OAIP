#include<stdio.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");

	float a, b, c;
	printf("Введите стороны треуогольника: ");
	scanf_s("%f%f%f", &a, &b, &c);
	printf("\nВы ввели стороны треуогольника. Посчитаем является ли он равнобедренным.\n");
	if (a == b || a == c || b == c)
		printf("\nТреугольник является равнобедренным.\n");
	else
		printf("\nТреугольник не является равнобедренным.\n");
	return 0;
}
