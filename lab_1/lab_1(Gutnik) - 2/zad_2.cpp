#include<stdio.h>
#include<locale.h>
#include<math.h>

int main()
{
	setlocale(LC_ALL, "Rus");

	float a, b, c, s;
	printf("������� ������ �������������� ������������: ");
	scanf_s("%f%f", &a, &b);

	c = a * a + b * b;
	s = (a * b) / 2;

	printf("\n���������� �������������� �����������: %.2f.\n", sqrt(c));
	printf("������� �������������� �����������: %.2f.\n\n", s);
	return 0;
}