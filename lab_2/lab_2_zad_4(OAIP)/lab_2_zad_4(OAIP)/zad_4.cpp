#include<stdio.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	float a, b, c;
	int k;
	k = 0;
	printf("������� 3 �����: ");
	scanf_s("%f%f%f", &a, &b, &c);
	if ((int)a == a)
		k++;
	if ((int)b == b)
		k++;
	if ((int)c == c)
		k++;
	
	printf("\n���������� ����� �����: %d.\n", k);

	return 0;
}
