#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int n = 0;
	float* arr;
		printf("Введите n количество чисел в массиве: ");
		scanf_s("%d", &n);
	arr = (float*)malloc(n * sizeof(float));
	for (int i = 0; i < n; i++)
	{
		printf("Введите %d элемент массива: ", i+1);
		scanf_s("%f", &arr[i]);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (arr[i] == 1 / arr[j])
			{
				printf("В массиве имеются взаимно обратные числа %.2f и %.2f. \n", arr[i], arr[j]);
			}
		}
	}
	delete[] arr;
}