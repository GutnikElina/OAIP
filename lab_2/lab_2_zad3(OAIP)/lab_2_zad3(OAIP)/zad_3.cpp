#include<stdio.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int chislo;

	printf("������� ����� ������� ���� �� 1 �� 12: ");
	scanf_s("%d.", &chislo);

	switch (chislo)
	{
	case 1: printf("\n����� - ������.\n");
		break;
	case 2: printf("\n����� - �������.\n");
		break;
	case 3: printf("\n����� - ����.\n");
		break;
	case 4: printf("\n����� - ������.\n");
		break;
	case 5: printf("\n����� - ���.\n");
		break;
	case 6: printf("\n����� - ����.\n");
		break;
	case 7: printf("\n����� - ����.\n");
		break;
	case 8: printf("\n����� - ������.\n");
		break;
	case 9: printf("\n����� - ��������.\n");
		break;
	case 10: printf("\n����� - �������.\n");
		break;
	case 11: printf("\n����� - ������.\n");
		break;
	case 12: printf("\n����� - �������.\n");
		break;
	default: printf("\n��������� ��������� �����.\n");
	}
		return 0;
	}
