#include<stdio.h>
#include<locale.h>
#include<math.h>

int main()
{
	setlocale(LC_ALL, "Rus");
    int n, sp = 0, i, j;
    printf("������� ����� n: ");
    scanf_s("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
            if (n == pow(i,3) + pow(j,3)) sp++;
    }
    printf("\n%d ������(��).\n", sp);
	return 0;
}

/*��������� ��������, ������������ ���������� ��������, ������ ���������� 
����� n>1 ����� ����������� � ���� ����� n=i3+j3, ������, ��� ������������ 
��������� ������ ������� �� ���.*/