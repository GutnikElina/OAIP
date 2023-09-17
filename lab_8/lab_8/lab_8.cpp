#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

struct chit
{
	char fam[30];
	char imya[20];
	char otch[30];
	char nom[20];
	char nazv[40];
	char vozvrat[20];
};

int check();
void enter_new();
void menu();
void out();
void del();
void change();
void find();
void sort();

int sch = 0;
chit mas[100];
chit tmp;
chit alf;

int main()
{
	setlocale(LC_ALL, "Rus");
	
	while (1)
	{
		menu();
		
		switch (check())
		{
		case 1: enter_new(); break;
		case 2: sort(); break;
		case 3: find(); break;
		case 4: change(); break;
		case 5: del(); break;
		case 6: out(); break;
		case 7: return 0; break;
		default: printf("\n---�� ������ ���� �����. ���������� �����.\n"); break;
		}
	} 
}

int check()
{
	char ch[100];
	int chislo;
	gets_s(ch);
	bool isbreak = false;
	for (int i = 0; i < strlen(ch); i++)
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

void menu()
{
	printf("\n-----����-----\n");
	printf("  ��������:\n");
	printf("1-��� ����� ����� ������\n");
	printf("2-��� ���������� �� �������� �������\n");
	printf("3-��� ������ \n");
	printf("4-��� ��������� ������\n");
	printf("5-��� �������� ������\n");
	printf("6-��� ������ ������(��)\n");
	printf("7-��� ������\n\n");
}

void enter_new()
{
	int br = 1;
	while(br)
	{
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
			int k=check();
			printf ("������� ��������: %s\n", mas[k - 1].fam );
			printf("��� ��������: %s\n", mas[k - 1].imya);
			printf("�������� ��������: %s\n", mas[k - 1].otch);
			printf("����� ������������� ������: %s\n", mas[k - 1].nom);
			printf("�������� �����: %s\n", mas[k - 1].nazv);
			printf("���� ��������: %s\n", mas[k - 1].vozvrat);
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
			}
		}
		else printf ("\n---�� ������ ���� �����.���������� �����---\n");
	}
}

void del() 
{
	int d;
	if (sch == 0)
		printf("\n---��� �������---\n");
	else
	{
		printf("\n������� ����� ������, ������� ���������� �������: \n");
		printf("���� ���������� ������� ��� ������, ������� '99'\n");
		d = check();
		if (d<=sch)
		{
			for (int i = (d - 1); i < sch; i++)
				mas[i] = mas[i + 1];
			sch = sch - 1;
		}
		else if (d == 99)
		{
			for (int i = 0; i < sch; i++)
				mas[i] = tmp;
			sch = 0;
		}
		else printf("\n---�� ������ ���� �����.���������� �����---\n");
	}
}

void change() 
{
	if (sch == 0)
		printf("\n---��� �������---\n");
	else
	{
		printf("\n������� ����� ������: \n");
		int zap = check();
		if (zap <= sch)
		{
			do
			{
				printf("�������: \n");
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
					getchar();
					break;
				case 2: printf("\n������� ����� ���:\n");
					gets_s(mas[zap - 1].imya);
					getchar(); 
					break;
				case 3: printf("\n������� ����� ��������:\n");
					gets_s(mas[zap - 1].otch);
					break;
				case 4: printf("\n������� ����� ����� ������������� ������:\n");
					gets_s(mas[zap - 1].nom);
					getchar();
					break;
				case 5: printf("\n������� ����� �������� �����:\n");
					gets_s(mas[zap - 1].nazv);
					break;
				case 6: printf("\n������� ����� ����:\n");
					gets_s(mas[zap - 1].vozvrat);
					break;
				case 7: return;
				default: printf("\n---�� ������ ���� �����. ���������� �����.\n");
				}
			} while (1);
		}
		else printf("\n---�� ������ ���� �����. ���������� �����---\n");
	}
}

void find() 
{
	int break_find, amount; 
	char find_fam[30], find_imya[20], find_otch[30], find_nazv[30], find_vozvrat[20], find_nom[20];
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
					for (int b = 0; b < (strlen(find_fam)) && break_find==0; b++)
					{
						if (find_fam[b] != mas[i].fam[b])
							break_find++;
					}
					if (break_find==0)
					{
						printf("\n");
						printf("������� ��������: %s\n", mas[i].fam);
						printf("��� ��������: %s\n", mas[i].imya);
						printf("�������� ��������: %s\n", mas[i].otch);
						printf("����� ������������� ������: %s\n", mas[i].nom);
						printf("�������� �����: %s\n", mas[i].nazv);
						printf("���� ��������: %s\n", mas[i].vozvrat);
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
						printf("\n");
						printf("������� ��������: %s\n", mas[i].fam);
						printf("��� ��������: %s\n", mas[i].imya);
						printf("�������� ��������: %s\n", mas[i].otch);
						printf("����� ������������� ������: %s\n", mas[i].nom);
						printf("�������� �����: %s\n", mas[i].nazv);
						printf("���� ��������: %s\n", mas[i].vozvrat);
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
						printf("\n");
						printf("������� ��������: %s\n", mas[i].fam);
						printf("��� ��������: %s\n", mas[i].imya);
						printf("�������� ��������: %s\n", mas[i].otch);
						printf("����� ������������� ������: %s\n", mas[i].nom);
						printf("�������� �����: %s\n", mas[i].nazv);
						printf("���� ��������: %s\n", mas[i].vozvrat);
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
						printf("\n");
						printf("������� ��������: %s\n", mas[i].fam);
						printf("��� ��������: %s\n", mas[i].imya);
						printf("�������� ��������: %s\n", mas[i].otch);
						printf("����� ������������� ������: %s\n", mas[i].nom);
						printf("�������� �����: %s\n", mas[i].nazv);
						printf("���� ��������: %s\n", mas[i].vozvrat);
						amount++;
					}
				}
				if (amount == 0)
					printf("\n---���������� �������� ����� �� ���������� � �������. ���������� ������---\n");
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
						printf("\n");
						printf("������� ��������: %s\n", mas[i].fam);
						printf("��� ��������: %s\n", mas[i].imya);
						printf("�������� ��������: %s\n", mas[i].otch);
						printf("����� ������������� ������: %s\n", mas[i].nom);
						printf("�������� �����: %s\n", mas[i].nazv);
						printf("���� ��������: %s\n", mas[i].vozvrat);
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
						if (find_vozvrat[b] != mas[i].vozvrat[b])
							break_find++;
					}
					if (break_find == 0)
					{
						printf("\n");
						printf("������� ��������: %s\n", mas[i].fam);
						printf("��� ��������: %s\n", mas[i].imya);
						printf("�������� ��������: %s\n", mas[i].otch);
						printf("����� ������������� ������: %s\n", mas[i].nom);
						printf("�������� �����: %s\n", mas[i].nazv);
						printf("���� ��������: %s\n", mas[i].vozvrat);
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
	
void sort()
{
	if (sch == 0)
		printf("\n��� �������.\n");
	else
	{
		for (int i = 0; i < sch-1; i++)
			for (int j = i + 1; j < sch; j++)
				if (strcmp(mas[i].fam, mas[j].fam) > 0)
				{
					alf = mas[i]; mas[i] = mas[j]; mas[j] = alf;
				}

		printf("\n�������� � ���������� �������: \n");
		for (int i = 0; i < sch; i++)
		{
			printf("\n");
			printf("������� ��������: %s\n", mas[i].fam);
			printf("��� ��������: %s\n", mas[i].imya);
			printf("�������� ��������: %s\n", mas[i].otch);
			printf("����� ������������� ������: %s\n", mas[i].nom);
			printf("�������� �����: %s\n", mas[i].nazv);
			printf("���� ��������: %s\n", mas[i].vozvrat);
		}
	}
}

