#include<stdio.h>
#include<locale.h>
#include<math.h>

int main()
{
	setlocale(LC_ALL, "Rus");

	float x, y;
	printf("������� �������� ���������� x: ");
	scanf_s("%f", &x);
	printf("�� ����� �������� ���������� x.\n\n");

	y = x * (sin(x) + exp(-(x + 3)));

	printf("�������� ��������� ���������: y=%f.\n\n", y);

	return 0;
}