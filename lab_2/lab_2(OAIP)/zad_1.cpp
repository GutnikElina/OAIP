#include<stdio.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");

	float a, b, c;
	printf("������� ������� �������������: ");
	scanf_s("%f%f%f", &a, &b, &c);
	printf("\n�� ����� ������� �������������. ��������� �������� �� �� ��������������.\n");
	if (a == b || a == c || b == c)
		printf("\n����������� �������� ��������������.\n");
	else
		printf("\n����������� �� �������� ��������������.\n");
	return 0;
}
