#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<math.h>

void main()
{
	setlocale(LC_ALL, "Rus");
	float* arr;
	int n, kol = 0, imax=0, i;
	float pr = 1, c, max;
	printf("Введите количество элементов в массиве: ");
	scanf_s("%d", &n);
	arr = (float*)malloc(n * sizeof(float));
	printf("Введите число С: ");
	scanf_s("%f", &c);
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("Введите %d-й элемент массива: ", i+1);
		scanf_s("%f", arr+i);
	}
	printf("\nМассив: \n");
	for (i = 0; i < n; i++)
	{
		printf("%.2f ", *(arr + i));
	}
	for (i = 0; i < n; i++)
	{
		if ( *(arr+i) > c)
			kol++;
	}
	printf("\n");
	if (kol == 0)
		printf("\nНет элементов больших числа С.\n");
	else printf("\nКоличество элементов массива больших числа С: %d.\n", kol);

	printf("\nМассив после изменения элементов на их модули: \n");
	for (i = 0; i < n; i++)
	{
		printf("%.2f ", fabs(*(arr + i)));
	}
	printf("\n");
	max = *arr;
	for (i = 0; i < n; i++)
	{
		if (*(arr + i) > max)
		{
			max = *(arr + i);
			imax = i;
		}
	}
	for (i = imax+1; i < n; i++)
	{
		pr *= *(arr+i);
	}
	
	if (pr==1)
		printf("\nПосле максимального по модулю элемента элементов нет.\n");
	else printf("\nПроизведение элементов массива, расположенных после максимального по модулю элемента: %.2f.\n", pr);
	free(arr);
}