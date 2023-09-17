#include<stdio.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	float a, b, c;
	int k;
	k = 0;
	printf("Введите 3 числа: ");
	scanf_s("%f%f%f", &a, &b, &c);
	if ((int)a == a)
		k++;
	if ((int)b == b)
		k++;
	if ((int)c == c)
		k++;
	
	printf("\nКоличество целых чисел: %d.\n", k);

	return 0;
}
