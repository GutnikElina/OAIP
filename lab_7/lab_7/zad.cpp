#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<locale.h>
#include<stdlib.h>

//int fact(int num)	
//{
//	if (num <= 1) return 1;
//	else return num * fact(num - 1);
//}

//int main()
//{
//	int a, r;
//	printf("a= ");
//	scanf_s("%d", &a);
//		r = fact(a);
//		printf("%d!=%d", a, r);
//		
//		return 0;
//}

int main()
{
	char str1[101], str2[101];
	printf("\nVvedite pervyu stroky: \n");
	getchar();
	gets_s(str1);

	printf("\nVvedite vtoryu stroky: \n");
	getchar();
	gets_s(str2);

	printf("%c", strlen(str1));
	printf("%c", strlen(str2));

	printf("%c", strcpy(str1, str2));

	return 0;
}
void zadanie_3_2()
{
	setlocale(LC_ALL, "Rus");
	char str[101];
	int i, j, k{}, max{}, place{}, max_ind{};
	printf("\n"); printf("\n");
	printf("Задание №3.2.");
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
				max_ind = i - k + 1;
			}
			k = 0;
		}
	}
	printf("\n");
	printf("Самое длинное слово: ");
	for (i = max_ind - 1; i < max; i++)
	{
		printf("%c", str[i]);
	}
}

void zadanie_3_3()
{
	setlocale(LC_ALL, "Rus");
	char str[101];
	int i, k = 0, kol = 0, ind_posledniy = 0, ind_perviy = 0, kol_a = 0;
	printf("\n");
	printf("Задание №3.3.");
	printf("\nВведите строку: \n");
	getchar();
	gets_s(str);

	strcat_s(str, " ");

	i = 0;
	for (i; i < strlen(str); i++)
	{
		if (str[i] = ' ') k++;
		else
		{
			ind_posledniy = k;
			ind_perviy = i - k + 1;
			for (i = ind_perviy; i <= ind_posledniy; i++)
			{
				if (str[i] == 'a')
					kol_a++;
			}
			if (kol_a >= 2)
				kol++;
		}
	}
	getchar();
	printf("\nКоличество слов, в которых буква 'a' входит не менее двух раз: %d.", kol);
	printf("\n");
}