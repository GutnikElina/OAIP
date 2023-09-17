#include<stdio.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int god=0;
	float k, naselenie, x3, n;
	printf("Ќаселение города равно: ");
	scanf_s("%f", &naselenie);
	printf("¬ведите натуральное число n, на которое будет увеличиватьс€ ежегодно население города: ");
	scanf_s("%f", &n);
	x3 = naselenie * 3;
	k = (1 / n)*naselenie;
	while (naselenie < x3)
	{
		naselenie += k;
		god++;
	}
	printf("\n„ерез %d лет количество населени€ города увеличитьс€ втрое.\n", god);
	return 0;
}
/*Ќаселение города ежегодно увеличиваетс€ на 1/n наличного состава жителей, 
где n-натуральное число. „ерез сколько лет население города утроитс€.*/
