#include<stdio.h>
#include<locale.h>
#include<math.h>
#include<conio.h>

int main()
{
	setlocale(LC_ALL, "Rus"); 
	float x, a;
	printf("������� ����� a: \n");
	scanf_s("%f", &a);
	x = a * a + 1;
	while (x < 1000001)
	{
		x *= x; ++x;
	}
	printf("\n����� ����� �������������� ����� %1.f\n", x);
	a = _getch();
	return 0;
}

/*����� a �������� � ������� � ��������� ����������� �� 1. ���������� ����� ����� �������� � �������
� ����������� �� 1. ���� ������� ������������ �� ��� ���, ���� �� ����� �������� ����� X, ������� ��������. ����� ����� X.*/