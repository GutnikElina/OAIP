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
		printf("\n  ����:\n");
		printf("1. ������� 1\n");
		printf("2. ������� 2\n");
		printf("3. ������� 3\n");
		printf("4. �����\n");
		printf("  ��� �����: \n");
		scanf_s("%d", &ch);
	} while ((ch < 1) || (ch > 4));
	return ch;
}

void zadanie_1()
{
	setlocale(LC_ALL, "Rus");
	int n, m, i, j, ** arr, k=0, ipol=0, t=0;
	printf("\n������� 1.:\n���������, ���� �� � ������� ���� �� ���� ������, ���������� ������������� �������, � ����� �� �����.����� ��������� ���������� ������ �������� �� ���������������.\n");
	printf("\n������� n ���������� ����� � �������: \n");
	scanf_s("%d", &n);

	printf("������� m ���������� �������� � �������: \n");
	scanf_s("%d", &m);
	arr = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++)
		*(arr + i) = (int*)malloc(5 * sizeof(int));
	printf("\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("������� ������� [%d,%d]: \n", i + 1, j + 1);
			scanf_s("%d", &arr[i][j]);
		}
	}
	printf("\n�������: \n");
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
				printf("\n� %d-� ������ ���������� ������������� �������.\n", i + 1);
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
	printf("\n������� ����� ��������� ������: \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	if (t == 0) printf("\n� ������� ��� �����, ���������� ������������� ��������. \n");
}


void zadanie_2()
{
	char str[101];
	int i;
	printf("\n������� 2:\n�������� ���������, ������� ������ ������ ������ � ������ �������� s[100], ��������� ������� gets.�������� ������ � ������� � ������ ���������.\n");
	printf("\n������� �����: \n");
	getchar();
	gets_s(str);
	printf("����� � ������ ��������: ");
	for (i = 0; (str[i] != 0) && (i < 101); i++)
		printf("%c", tolower(str[i]));
	printf("\n");
	printf("����� � ������� ��������: ");
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
	printf("������� �3.1:\n� ������ ����� � ���������� ���������� ����, � ������� ������ � ��������� ������� ��������� ����� ����� (����� ��������� ���������)\n");
	printf("\n������� ������: \n");
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
	printf("\n���������� ����, � ������� ������ � ��������� ������� ��������� ����� �����: %d.", kol);
	printf("\n");
}

void zadanie_3_2()
{
	setlocale(LC_ALL, "Rus");
	char str[101];
	int i, j, k{}, max{}, place{}, max_ind{};
	printf("\n"); 
	printf("������� �3.2:\n������� �� ����� ����� ������� ����� �� ���������� ������.\n");
	printf("\n������� ������: \n");
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
	printf("����� ������� �����: ");
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
	printf("������� �3.3:\n���������� ���������� ����, � ������� ����� '�' ������ �� ����� ���� ���. (����� ��������� ��������).\n");
	printf("\n������� ������: \n");
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
	printf("\n���������� ����, � ������� ����� 'a' ������ �� ����� ���� ���: %d.", kol);
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
