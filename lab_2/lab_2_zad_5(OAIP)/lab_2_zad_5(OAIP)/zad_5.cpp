#include<stdio.h>
#include<locale.h>
#include<conio.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int a;
	printf("������� 6-������� �����: ");
	scanf_s ("%d", &a);
	if ((a%10+(a/10)%10+ (a / 100) % 10) == (((a / 1000) % 10) + (a / 10000) % 10) +a/100000)
		printf("����� �������� ����������.");
	else printf("����� �� �������� ����������.");
	a = _getch();
	return 0;
}
