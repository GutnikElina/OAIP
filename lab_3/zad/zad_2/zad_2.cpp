#include<stdio.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int god=0;
	float k, naselenie, x3, n;
	printf("��������� ������ �����: ");
	scanf_s("%f", &naselenie);
	printf("������� ����������� ����� n, �� ������� ����� ������������� �������� ��������� ������: ");
	scanf_s("%f", &n);
	x3 = naselenie * 3;
	k = (1 / n)*naselenie;
	while (naselenie < x3)
	{
		naselenie += k;
		god++;
	}
	printf("\n����� %d ��� ���������� ��������� ������ ����������� �����.\n", god);
	return 0;
}
/*��������� ������ �������� ������������� �� 1/n ��������� ������� �������, 
��� n-����������� �����. ����� ������� ��� ��������� ������ ��������.*/
