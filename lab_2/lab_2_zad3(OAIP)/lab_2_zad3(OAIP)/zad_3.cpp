#include<stdio.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int chislo;

	printf("¬ведите номер времени года от 1 до 12: ");
	scanf_s("%d.", &chislo);

	switch (chislo)
	{
	case 1: printf("\nћес€ц - €нварь.\n");
		break;
	case 2: printf("\nћес€ц - февраль.\n");
		break;
	case 3: printf("\nћес€ц - март.\n");
		break;
	case 4: printf("\nћес€ц - апрель.\n");
		break;
	case 5: printf("\nћес€ц - май.\n");
		break;
	case 6: printf("\nћес€ц - июнь.\n");
		break;
	case 7: printf("\nћес€ц - июль.\n");
		break;
	case 8: printf("\nћес€ц - август.\n");
		break;
	case 9: printf("\nћес€ц - сент€брь.\n");
		break;
	case 10: printf("\nћес€ц - окт€брь.\n");
		break;
	case 11: printf("\nћес€ц - но€брь.\n");
		break;
	case 12: printf("\nћес€ц - декабрь.\n");
		break;
	default: printf("\nѕроверьте введенное число.\n");
	}
		return 0;
	}
