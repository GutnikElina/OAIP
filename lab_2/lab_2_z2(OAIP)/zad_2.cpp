#include<stdio.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");

	int x1 = 2, x2 = 4, x3 = 1, y1 = 9, y2 = 0, y3 = 1;
	if  (x1 < x2 && x1 < x3) && (y1 < y2 && y1 < y3)
		printf("����� � ��������� ����� � ������ ���������.\n");
	else if (x2 < x1 && x2 < x3) && (y2 < y1 && y2 < y3)
		printf("����� B ��������� ����� � ������ ���������.\n");
	else if (x3 < x1 && x3 < x2) && (y3 < y1 && y3 < y2)
		printf("����� C ��������� ����� � ������ ���������.\n");
	else
		printf("��� ����� ����� ���� ����������.\n");

	return 0;
}
