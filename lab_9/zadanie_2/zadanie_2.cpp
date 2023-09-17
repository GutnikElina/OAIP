//������������ �������� ���� �� ���������, �������� � �������� ���������, ����������� ��� ����������, 
//��������� ���������� ��������� � ������������ �� ����� ��������� � ����� �� ������ �� ����������
//(��������, �� �������, �� ���������������� ������, �� ���� �������� � �.�.).
//������������, ������, ����������, ����� ��������� � ����� ��������� �������� �������� � ���� �������.
//������������� ��������� �� ������� ��� �������� ����� � ���������� �������� ����� / ������.

//��������� ����������: ������� �.�., ����� ������������� ������, �������� �����, ���� ��������.

#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

struct reader
{
	char fam[30];
	char imya[20];
	char otch[30];
	char nom[20];
	char nazv[40];
	char vozvrat[20];
};

int check();
void form();
void menu();
void out();
void find();
void change();

int sch = 0;
struct reader mas[100];
FILE* file;

int main()
{
	setlocale(LC_ALL, "Rus");
	fopen_s(&file, "reader.txt", "w+b");

	if (file != NULL)
	{
		printf("���� reader.txt ������� ������!\n");
		while (1)
		{
			menu();
			switch (check())
			{
			case 1: form(); break;
			case 2: out(); break;
			case 3: find(); break;
			case 4: change(); break;
			case 5: return 0; break;
			default: printf("\n---�� ������ ���� �����. ���������� �����.\n"); break;
			}
		}
		fclose(file);
	}
	else
	{
		fprintf(stderr, "�� ������� ������� ��� ������� ���� reader.txt.\n");
		return 1;
	}
}

void menu()
{
	printf("\n-----����-----\n");
	printf("  ��������:\n");
	printf("1-��� ����� ����� ������\n");
	printf("2-��� ������ ������(��) � ����\n");
	printf("3-��� ������ ������(��)\n");
	printf("4-��� ��������� ������(��)\n");
	printf("5-��� ������\n\n");
}

int check()
{
	char ch[100];
	int chislo;
	gets_s(ch);
	bool isbreak = false;
	for (int i = 0; ch[i] < strlen(ch); i++)
	{
		if (ch[i] < 48 || ch[i]>57)
			isbreak = true;
	}
	if (isbreak)
	{
		printf("\n---�� ������ ���� �����. ���������� �����.\n");
	}
	else
		chislo = atoi(ch);
	return chislo;
}

void form()
{
	int br = 1;
	while (br)
	{
		int wh = 1, k=0;
		char choice;
		br = 1;
		printf("\n---������ �%d:", sch + 1);
		printf("\n������� ������� ��������: ");
		gets_s(mas[sch].fam);
		printf("������� ��� ��������: ");
		gets_s(mas[sch].imya);
		printf("������� �������� ��������: ");
		gets_s(mas[sch].otch);
		printf("������� ����� ������������� ������: ");
		gets_s(mas[sch].nom);
		printf("������� �������� �����: ");
		gets_s(mas[sch].nazv);
		printf("������� ���� ��������: ");
		gets_s(mas[sch].vozvrat);
		sch++;
		printf("\n---������ ����������?\n���� ��, �� ������� '1', ���� ���, �� ������� '0'.\n");
		br = check();
	}
}

void out()
{
	if (sch == 0)
		printf("\n---��� �������---\n\n");
	else
	{
		printf("\n�������: \n");
		printf("1-���� ������ ������� �����-���� ������\n");
		printf("2-���� ������ ������� ��� ������\n");
		printf("\n");
		int sw = check();
		if (sw == 1)
		{
			printf("\n������� ����� ������, ������� ����� �������\n");
			int k = check();
			printf("������� ��������: %s\n", mas[k - 1].fam);
			printf("��� ��������: %s\n", mas[k - 1].imya);
			printf("�������� ��������: %s\n", mas[k - 1].otch);
			printf("����� ������������� ������: %s\n", mas[k - 1].nom);
			printf("�������� �����: %s\n", mas[k - 1].nazv);
			printf("���� ��������: %s\n", mas[k - 1].vozvrat);

			fprintf(file, "\n������� ��������: ");
			fputs(mas[k - 1].fam, file);
			fprintf(file, "\n��� ��������: ");
			fputs(mas[k - 1].imya, file);
			fprintf(file, "\n�������� ��������: ");
			fputs(mas[k - 1].otch, file);
			fprintf(file, "\n����� ������������� ������: ");
			fputs(mas[k - 1].nom, file);
			fprintf(file, "\n�������� �����: ");
			fputs(mas[k - 1].nazv, file);
			fprintf(file, "\n���� ��������: ");
			fputs(mas[k - 1].vozvrat, file);
			fprintf(file, "\n");

			printf("\n������ �������� � �����!\n");
		}
		else if (sw == 2)
		{
			for (int i = 0; i < sch; i++)
			{
				printf("\n������ �%d: \n", i + 1);
				printf("������� ��������: %s\n", mas[i].fam);
				printf("��� ��������: %s\n", mas[i].imya);
				printf("�������� ��������: %s\n", mas[i].otch);
				printf("����� ������������� ������: %s\n", mas[i].nom);
				printf("�������� �����: %s\n", mas[i].nazv);
				printf("���� ��������: %s\n", mas[i].vozvrat);

				fprintf(file, "\n������� ��������: ");
				fputs(mas[i].fam, file);
				fprintf(file, "\n��� ��������: ");
				fputs(mas[i].imya, file);
				fprintf(file, "\n�������� ��������: ");
				fputs(mas[i].otch, file);
				fprintf(file, "\n����� ������������� ������: ");
				fputs(mas[i].nom, file);
				fprintf(file, "\n�������� �����: ");
				fputs(mas[i].nazv, file);
				fprintf(file, "\n���� ��������: ");
				fputs(mas[i].vozvrat, file);
				fprintf(file, "\n");

				printf("\n������ �������� � �����!\n");
			}
		}
		else printf("\n---�� ������ ���� �����.���������� �����---\n");
	}
}

void find()
{
	int break_find, amount;
	char find_fam[30], find_imya[20], find_otch[30], find_nazv[30], find_nom[30], find_vozvrat[30];
	if (sch == 0)
		printf("\n---��� ����c��---\n");
	else
	{
		do
		{
			printf("\n��������: \n");
			printf("1-��� ������ �� �������\n");
			printf("2-��� ������ �� �����\n");
			printf("3-��� ������ �� ��������\n");
			printf("4-��� ������ �� ������ ������������� ������\n");
			printf("5-��� ������ �� �������� �����\n");
			printf("6-��� ������ �� ��� ��������\n");
			printf("7-��� �����������\n");
			switch (check())
			{
			case 1: printf("\n������� ������� ��� ������:\n");
				gets_s(find_fam);
				amount = 0;
				for (int i = 0; i < sch; i++)
				{
					break_find = 0;
					for (int b = 0; b < (strlen(find_fam)) && break_find == 0; b++)
					{
						if (find_fam[b] != mas[i].fam[b])
							break_find++;
					}
					if (break_find == 0)
					{
						printf("\n������ �%d: \n", i + 1);
						printf("������� ��������: %s\n", mas[i].fam);
						printf("��� ��������: %s\n", mas[i].imya);
						printf("�������� ��������: %s\n", mas[i].otch);
						printf("����� ������������� ������: %s\n", mas[i].nom);
						printf("�������� �����: %s\n", mas[i].nazv);
						printf("���� ��������: %s\n", mas[i].vozvrat);

						fprintf(file, "\n---�������� ����� �� ������� ��������---\n");
						fprintf(file, "\n������� ��������: ");
						fputs(mas[i].fam, file);
						fprintf(file, "\n��� ��������: ");
						fputs(mas[i].imya, file);
						fprintf(file, "\n�������� ��������: ");
						fputs(mas[i].otch, file);
						fprintf(file, "\n����� ������������� ������: ");
						fputs(mas[i].nom, file);
						fprintf(file, "\n�������� �����: ");
						fputs(mas[i].nazv, file);
						fprintf(file, "\n���� ��������: ");
						fputs(mas[i].vozvrat, file);
						fprintf(file, "\n");

						printf("\n������ �������� � �����!\n");
						amount++;
					}
				}
				if (amount == 0)
					printf("\n---��������� ������� �� ���������� � �������. ���������� ������---\n");
				break;
			case 2: printf("\n������� ��� ��� ������:\n");
				gets_s(find_imya);
				amount = 0;
				for (int i = 0; i < sch; i++)
				{
					break_find = 0;
					for (int b = 0; b < (strlen(find_imya)) && break_find == 0; b++)
					{
						if (find_imya[b] != mas[i].imya[b])
							break_find++;
					}
					if (break_find == 0)
					{
						printf("\n������ �%d: \n", i + 1);
						printf("������� ��������: %s\n", mas[i].fam);
						printf("��� ��������: %s\n", mas[i].imya);
						printf("�������� ��������: %s\n", mas[i].otch);
						printf("����� ������������� ������: %s\n", mas[i].nom);
						printf("�������� �����: %s\n", mas[i].nazv);
						printf("���� ��������: %s\n", mas[i].vozvrat);

						fprintf(file, "\n---�������� ����� �� ����� ��������---\n");
						fprintf(file, "\n������� ��������: ");
						fputs(mas[i].fam, file);
						fprintf(file, "\n��� ��������: ");
						fputs(mas[i].imya, file);
						fprintf(file, "\n�������� ��������: ");
						fputs(mas[i].otch, file);
						fprintf(file, "\n����� ������������� ������: ");
						fputs(mas[i].nom, file);
						fprintf(file, "\n�������� �����: ");
						fputs(mas[i].nazv, file);
						fprintf(file, "\n���� ��������: ");
						fputs(mas[i].vozvrat, file);
						fprintf(file, "\n");

						printf("\n������ �������� � �����!\n");
						amount++;
					}
				}
				if (amount == 0)
					printf("\n---���������� ����� �� ���������� � �������. ���������� ������---\n");
				break;
			case 3: printf("\n������� �������� ��� ������:\n");
				gets_s(find_otch);
				amount = 0;
				for (int i = 0; i < sch; i++)
				{
					break_find = 0;
					for (int b = 0; b < (strlen(find_otch)) && break_find == 0; b++)
					{
						if (find_otch[b] != mas[i].otch[b])
							break_find++;
					}
					if (break_find == 0)
					{
						printf("\n������ �%d: \n", i + 1);
						printf("������� ��������: %s\n", mas[i].fam);
						printf("��� ��������: %s\n", mas[i].imya);
						printf("�������� ��������: %s\n", mas[i].otch);
						printf("����� ������������� ������: %s\n", mas[i].nom);
						printf("�������� �����: %s\n", mas[i].nazv);
						printf("���� ��������: %s\n", mas[i].vozvrat);

						fprintf(file, "\n---�������� ����� �� �������� ��������---\n");
						fprintf(file, "\n������� ��������: ");
						fputs(mas[i].fam, file);
						fprintf(file, "\n��� ��������: ");
						fputs(mas[i].imya, file);
						fprintf(file, "\n�������� ��������: ");
						fputs(mas[i].otch, file);
						fprintf(file, "\n����� ������������� ������: ");
						fputs(mas[i].nom, file);
						fprintf(file, "\n�������� �����: ");
						fputs(mas[i].nazv, file);
						fprintf(file, "\n���� ��������: ");
						fputs(mas[i].vozvrat, file);
						fprintf(file, "\n");

						printf("\n������ �������� � �����!\n");
						amount++;
					}
				}
				if (amount == 0)
					printf("\n---���������� �������� �� ���������� � �������. ���������� ������---\n");
				break;
			case 4: printf("\n������� ����� ������������� ������ ��� ������:\n");
				gets_s(find_nom);
				amount = 0;
				for (int i = 0; i < sch; i++)
				{
					break_find = 0;
					for (int b = 0; b < (strlen(find_nom)) && break_find == 0; b++)
					{
						if (find_nom[b] != mas[i].nom[b])
							break_find++;
					}
					if (break_find == 0)
					{
						printf("\n������ �%d: \n", i + 1);
						printf("������� ��������: %s\n", mas[i].fam);
						printf("��� ��������: %s\n", mas[i].imya);
						printf("�������� ��������: %s\n", mas[i].otch);
						printf("����� ������������� ������: %s\n", mas[i].nom);
						printf("�������� �����: %s\n", mas[i].nazv);
						printf("���� ��������: %s\n", mas[i].vozvrat);

						fprintf(file, "\n---�������� ����� �� ������ ������������� ������---\n");
						fprintf(file, "\n������� ��������: ");
						fputs(mas[i].fam, file);
						fprintf(file, "\n��� ��������: ");
						fputs(mas[i].imya, file);
						fprintf(file, "\n�������� ��������: ");
						fputs(mas[i].otch, file);
						fprintf(file, "\n����� ������������� ������: ");
						fputs(mas[i].nom, file);
						fprintf(file, "\n�������� �����: ");
						fputs(mas[i].nazv, file);
						fprintf(file, "\n���� ��������: ");
						fputs(mas[i].vozvrat, file);
						fprintf(file, "\n");

						printf("\n������ �������� � �����!\n");
						amount++;
					}
				}
				if (amount == 0)
					printf("\n---���������� ������ ������������� ������ �� ���������� � �������. ���������� ������---\n");
				break; 
			case 5: printf("\n������� �������� ��� ������:\n");
				gets_s(find_nazv);
				amount = 0;
				for (int i = 0; i < sch; i++)
				{
					break_find = 0;
					for (int b = 0; b < (strlen(find_nazv)) && break_find == 0; b++)
					{
						if (find_nazv[b] != mas[i].nazv[b])
							break_find++;
					}
					if (break_find == 0)
					{
						printf("\n������ �%d: \n", i + 1);
						printf("������� ��������: %s\n", mas[i].fam);
						printf("��� ��������: %s\n", mas[i].imya);
						printf("�������� ��������: %s\n", mas[i].otch);
						printf("����� ������������� ������: %s\n", mas[i].nom);
						printf("�������� �����: %s\n", mas[i].nazv);
						printf("���� ��������: %s\n", mas[i].vozvrat);

						fprintf(file, "\n---�������� ����� �� �������� �����---\n");
						fprintf(file, "\n������� ��������: ");
						fputs(mas[i].fam, file);
						fprintf(file, "\n��� ��������: ");
						fputs(mas[i].imya, file);
						fprintf(file, "\n�������� ��������: ");
						fputs(mas[i].otch, file);
						fprintf(file, "\n����� ������������� ������: ");
						fputs(mas[i].nom, file);
						fprintf(file, "\n�������� �����: ");
						fputs(mas[i].nazv, file);
						fprintf(file, "\n���� ��������: ");
						fputs(mas[i].vozvrat, file);
						fprintf(file, "\n");

						printf("\n������ �������� � �����!\n");
						amount++;
					}
				}
				if (amount == 0)
					printf("\n---���������� �������� ����� �� ���������� � �������. ���������� ������---\n");
				break;
			case 6: printf("\n������� ���� �������� ��� ������:\n");
				gets_s(find_vozvrat);
				amount = 0;
				for (int i = 0; i < sch; i++)
				{
					break_find = 0;
					for (int b = 0; b < (strlen(find_vozvrat)) && break_find == 0; b++)
					{
						if (find_vozvrat[b] != mas[i].nazv[b])
							break_find++;
					}
					if (break_find == 0)
					{
						printf("\n������ �%d: \n", i + 1);
						printf("������� ��������: %s\n", mas[i].fam);
						printf("��� ��������: %s\n", mas[i].imya);
						printf("�������� ��������: %s\n", mas[i].otch);
						printf("����� ������������� ������: %s\n", mas[i].nom);
						printf("�������� �����: %s\n", mas[i].nazv);
						printf("���� ��������: %s\n", mas[i].vozvrat);

						fprintf(file, "\n---�������� ����� �� ��� ��������---\n");
						fprintf(file, "\n������� ��������: ");
						fputs(mas[i].fam, file);
						fprintf(file, "\n��� ��������: ");
						fputs(mas[i].imya, file);
						fprintf(file, "\n�������� ��������: ");
						fputs(mas[i].otch, file);
						fprintf(file, "\n����� ������������� ������: ");
						fputs(mas[i].nom, file);
						fprintf(file, "\n�������� �����: ");
						fputs(mas[i].nazv, file);
						fprintf(file, "\n���� ��������: ");
						fputs(mas[i].vozvrat, file);
						fprintf(file, "\n");

						printf("\n������ �������� � �����!\n");
						amount++;
					}
				}
				if (amount == 0)
					printf("\n---���������� ��� �������� �� ���������� � �������. ���������� ������---\n");
				break;
			case 7: return;
			default: printf("\n---�� ������ ���� �����. ���������� �����---\n");
			}
		} while (1);
	}
}

void change()
{
	if (sch == 0)
		printf("\n---��� �������---\n");
	else
	{
		printf("\n������� ����� ������: \n");
		int zap = check(), izm;
		if (zap <= sch)
		{
			do
			{
				izm = 0;
				printf("\n�������: \n");
				printf("1-��� ��������� �������\n");
				printf("2-��� ��������� �����\n");
				printf("3-��� ��������� ��������\n");
				printf("4-��� ��������� ������ ������������� ������\n");
				printf("5-��� ��������� �������� �����\n");
				printf("6-��� ��������� ��� ��������\n");
				printf("7-��� �����������\n");
				switch (check())
				{
				case 1: printf("\n������� ����� �������:\n");
					gets_s(mas[zap - 1].fam);
					izm++;
					break;
				case 2: printf("\n������� ����� ���:\n");
					gets_s(mas[zap - 1].imya);
					izm++;
					break;
				case 3: printf("\n������� ����� ��������:\n");
					gets_s(mas[zap - 1].otch);
					izm++;
					break;
				case 4: printf("\n������� ����� ����� ������������� ������:\n");
					gets_s(mas[zap - 1].nom);
					izm++;
					break;
				case 5: printf("\n������� ����� �������� �����:\n");
					gets_s(mas[zap - 1].nazv);
					izm++;
					break;
				case 6: printf("\n������� ����� ���� ��������:\n");
					gets_s(mas[zap - 1].vozvrat);
					izm++;
					break;
				case 7: return;
				default: printf("\n---�� ������ ���� �����. ���������� �����---\n");
				}
				if (izm != 0)
				{
					fprintf(file, "\n---������ ����� ���������---\n");
					fprintf(file, "\n������� ��������: ");
					fputs(mas[zap - 1].fam, file);
					fprintf(file, "\n��� ��������: ");
					fputs(mas[zap - 1].imya, file);
					fprintf(file, "\n�������� ��������: ");
					fputs(mas[zap - 1].otch, file);
					fprintf(file, "\n����� ������������� ������: ");
					fputs(mas[zap - 1].nom, file);
					fprintf(file, "\n�������� �����: ");
					fputs(mas[zap - 1].nazv, file);
					fprintf(file, "\n���� ��������: ");
					fputs(mas[zap - 1].vozvrat, file);
					fprintf(file, "\n");
				}

			} while (1);
		}
		else printf("\n---�� ������ ���� �����. ���������� �����---\n");
	}
}