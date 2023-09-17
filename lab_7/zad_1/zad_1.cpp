#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<locale.h>
#include<stdlib.h>

int menu()
{
	setlocale(LC_ALL, "Rus");
	int ch;
	do
	{
		printf("\n  Меню:\n");
		printf("1. Задание 1\n");
		printf("2. Задание 2\n");
		printf("3. Задание 3\n");
		printf("4. Выход\n");
		printf("  Ваш выбор: \n");
		scanf_s("%d", &ch);
	} while ((ch < 1) || (ch > 4));
	return ch;
}

void zadanie_1()
{
	setlocale(LC_ALL, "Rus");
	int n, m, i, j, ** arr, k=0, ipol=0, t=0;
	printf("\nЗадание 1.:\nПроверить, есть ли в матрице хотя бы одна строка, содержащая положительный элемент, и найти ее номер.Знаки элементов предыдущей строки изменить на противоположные.\n");
	printf("\nВведите n количество строк в массиве: \n");
	scanf_s("%d", &n);

	printf("Введите m количество столбцов в массиве: \n");
	scanf_s("%d", &m);
	arr = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++)
		*(arr + i) = (int*)malloc(5 * sizeof(int));
	printf("\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("Введите элемент [%d,%d]: \n", i + 1, j + 1);
			scanf_s("%d", &arr[i][j]);
		}
	}
	printf("\nМАТРИЦА: \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < n; i++)
	{
		k = 0;
		for (j = 0; (j < m) && (k == 0); j++)
		{
			if (arr[i][j] > 0)
			{
				printf("\nВ %d-й строке содержится положительный элемент.\n", i + 1);
				k++;
				t++;
				if (i > 0)
				{
					for (j = 0; j < m; j++)
					{
						arr[i - 1][j] *= -1;
					}
				}
			}
		}
	}
	printf("\nМАТРИЦА после изменения знаков: \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	if (t == 0) printf("\nВ матрице нет строк, содержащих положительные элементы. \n");
}


void zadanie_2()
{
	char str[101];
	int i;
	printf("\nЗадание 2:\nНапишите программу, которая вводит строки текста в массив символов s[100], используя функцию gets.Выведите строки в верхнем и нижнем регистрах.\n");
	printf("\nВведите текст: \n");
	getchar();
	gets_s(str);
	printf("Текст в нижнем регистре: ");
	for (i = 0; (str[i] != 0) && (i < 101); i++)
		printf("%c", tolower(str[i]));
	printf("\n");
	printf("Текст в верхнем регистре: ");
	for (i = 0; (str[i] != 0) && (i < 101); i++)
		printf("%c", toupper(str[i]));
	printf("\n");
}


void zadanie_3_1()
{
	setlocale(LC_ALL, "Rus");
	char str[101];
	int i, k = 0, kol = 0, nachalo = 0, konec = 0;
	printf("\n");
	printf("Задание №3.1:\nВ тексте найти и подсчитать количество слов, у которых первый и последний символы совпадают между собой (слова разделены пробелами)\n");
	printf("\nВведите строку: \n");
	getchar();
	gets_s(str);

	strcat_s(str, " ");

	for (i=0; i < strlen(str); i++)
	{
		if (str[i] != ' ')
			k++;
		else
		{
			konec = i - 1;
			nachalo = konec - k+1;
			if (str[nachalo] == str[konec])
				kol++;
			k = 0;
		}
		konec = 0;
		nachalo = 0;
	}
	printf("\nКоличество слов, у которых первый и последний символы совпадают между собой: %d.", kol);
	printf("\n");
}

void zadanie_3_2()
{
	setlocale(LC_ALL, "Rus");
	char str[101];
	int i, j, k{}, max{}, place{}, max_ind{};
	printf("\n"); 
	printf("Задание №3.2:\nВывести на экран самое длинное слово из введенного текста.\n");
	printf("\nВведите строку: \n");
	gets_s(str);

	strcat_s(str, " ");

	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] != ' ') k++;
		else
		{
			if (k > max)
			{
				max = k;
				max_ind = i - k;
			}
			k = 0;
		}
	}
	printf("\n");
	printf("Самое длинное слово: ");
	for (i = max_ind; i < max; i++)
	{
		printf("%c", str[i]);
	}
}

void zadanie_3_3()
{
	setlocale(LC_ALL, "Rus");
	char str[101];
	int i, k = 0, kol = 0, kol_a = 0, nachalo=0, konec=0;
	printf("\n"); printf("\n");
	printf("Задание №3.3:\nПодсчитать количество слов, в которых буква 'а' входит не менее двух раз. (слова разделены пробелом).\n");
	printf("\nВведите строку: \n");
	gets_s(str);

	strcat_s(str, " ");

	i = 0;
	for (i; i < strlen(str); i++)
	{
		if (str[i] != ' ') 
			k++;
		else
		{
			konec = i - 1;
			nachalo = konec - k+1;
			for (nachalo; nachalo <= konec; nachalo++)
			{
				if (str[nachalo] == 'a')
					kol_a++;
			}
			if (kol_a >= 2)
				kol++;
			k = 0;
			kol_a = 0;
		}
		konec = 0;
		nachalo = 0;
	}
	printf("\nКоличество слов, в которых буква 'a' входит не менее двух раз: %d.", kol);
	printf("\n");
}

int main()
{
	setlocale(LC_ALL, "Rus");
	while (1)
	{
		switch (menu())
		{
		case 1: 
			zadanie_1(); break;
		case 2:
			zadanie_2(); break;
		case 3: 
			zadanie_3_1();
			zadanie_3_2(); 
			zadanie_3_3(); 
			break;
		case 4: 
			return 0;
		}
	}
}
