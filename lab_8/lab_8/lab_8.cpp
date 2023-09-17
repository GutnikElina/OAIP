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
		default: printf("\n---Не верный ввод числа. Попробуйте снова.\n"); break;
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
		printf("\n---Не верный ввод числа. Попробуйте снова.\n");
	}
	else
		chislo = atoi(ch);
	return chislo;
}

void menu()
{
	printf("\n-----МЕНЮ-----\n");
	printf("  Выберите:\n");
	printf("1-для ввода новой записи\n");
	printf("2-для сортировки по алфавиту записей\n");
	printf("3-для поиска \n");
	printf("4-для изменения записи\n");
	printf("5-для удаления записи\n");
	printf("6-для вывода записи(ей)\n");
	printf("7-для выхода\n\n");
}

void enter_new()
{
	int br = 1;
	while(br)
	{
		printf("\n---Запись №%d:", sch + 1);
		printf("\nВведите фамилию читателя: ");
		gets_s(mas[sch].fam);
		printf("Введите имя читателя: ");
		gets_s(mas[sch].imya);
		printf("Введите отчество читателя: ");
		gets_s(mas[sch].otch);
		printf("Введите номер читательского билета: ");
		gets_s(mas[sch].nom);
		printf("Введите название книги: ");
		gets_s(mas[sch].nazv);
		printf("Введите день возврата: ");
		gets_s(mas[sch].vozvrat);
		sch++;
		printf("\n---Хотите продолжить?\nЕсли да, то нажмите '1', если нет, то нажмите '0'.\n");
		br = check();
	} 
}

void out() 
{
	if (sch == 0) 
		printf("\n---Нет записей---\n\n");
	else
	{
		printf("\nВведите: \n");
		printf("1-если хотите вывести какую-либо запись\n");
		printf("2-если хотите вывести все записи\n");
		printf("\n");
		int sw = check();
		if (sw == 1)
		{
			printf("\nВведите номер записи, которую нужно вывести\n");
			int k=check();
			printf ("Фамилия читателя: %s\n", mas[k - 1].fam );
			printf("Имя читателя: %s\n", mas[k - 1].imya);
			printf("Отчество читателя: %s\n", mas[k - 1].otch);
			printf("Номер читательского билета: %s\n", mas[k - 1].nom);
			printf("Название книги: %s\n", mas[k - 1].nazv);
			printf("День возврата: %s\n", mas[k - 1].vozvrat);
		}
		else if (sw == 2)
		{
			for (int i = 0; i < sch; i++)
			{
				printf("\nЗапись №%d: \n", i + 1);
				printf("Фамилия читателя: %s\n", mas[i].fam);
				printf("Имя читателя: %s\n", mas[i].imya);
				printf("Отчество читателя: %s\n", mas[i].otch);
				printf("Номер читательского билета: %s\n", mas[i].nom);
				printf("Название книги: %s\n", mas[i].nazv);
				printf("День возврата: %s\n", mas[i].vozvrat);
			}
		}
		else printf ("\n---Не верный ввод числа.Попробуйте снова---\n");
	}
}

void del() 
{
	int d;
	if (sch == 0)
		printf("\n---Нет записей---\n");
	else
	{
		printf("\nВведите номер записи, которую необходимо удалить: \n");
		printf("Если необходимо удалить все записи, нажмите '99'\n");
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
		else printf("\n---Не верный ввод числа.Попробуйте снова---\n");
	}
}

void change() 
{
	if (sch == 0)
		printf("\n---Нет записей---\n");
	else
	{
		printf("\nВведите номер записи: \n");
		int zap = check();
		if (zap <= sch)
		{
			do
			{
				printf("Введите: \n");
				printf("1-для изменения фамилии\n");
				printf("2-для изменения имени\n");
				printf("3-для изменения отчества\n");
				printf("4-для изменения номера читательского билета\n");
				printf("5-для изменения названия книги\n");
				printf("6-для изменения дня возврата\n");
				printf("7-для прекращения\n");
				switch (check())
				{
				case 1: printf("\nВведите новую фамилию:\n");
					gets_s(mas[zap - 1].fam);
					getchar();
					break;
				case 2: printf("\nВведите новое имя:\n");
					gets_s(mas[zap - 1].imya);
					getchar(); 
					break;
				case 3: printf("\nВведите новое отчество:\n");
					gets_s(mas[zap - 1].otch);
					break;
				case 4: printf("\nВведите новый номер читательского билета:\n");
					gets_s(mas[zap - 1].nom);
					getchar();
					break;
				case 5: printf("\nВведите новое название книги:\n");
					gets_s(mas[zap - 1].nazv);
					break;
				case 6: printf("\nВведите новый день:\n");
					gets_s(mas[zap - 1].vozvrat);
					break;
				case 7: return;
				default: printf("\n---Не верный ввод числа. Попробуйте снова.\n");
				}
			} while (1);
		}
		else printf("\n---Не верный ввод числа. Попробуйте снова---\n");
	}
}

void find() 
{
	int break_find, amount; 
	char find_fam[30], find_imya[20], find_otch[30], find_nazv[30], find_vozvrat[20], find_nom[20];
	if (sch == 0)
	printf("\n---Нет запиcей---\n");
	else
	{
		do
		{
			printf("\nВыберите: \n");
			printf("1-для поиска по фамилии\n");
			printf("2-для поиска по имени\n");
			printf("3-для поиска по отчества\n");
			printf("4-для поиска по номеру читательского билета\n");
			printf("5-для поиска по названию книги\n");
			printf("6-для поиска по дню возврата\n");
			printf("7-для прекращения\n");
			switch (check())
			{
			case 1: printf("\nВведите фамилию для поиска:\n");
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
						printf("Фамилия читателя: %s\n", mas[i].fam);
						printf("Имя читателя: %s\n", mas[i].imya);
						printf("Отчество читателя: %s\n", mas[i].otch);
						printf("Номер читательского билета: %s\n", mas[i].nom);
						printf("Название книги: %s\n", mas[i].nazv);
						printf("День возврата: %s\n", mas[i].vozvrat);
						amount++;
					}
				}
				if (amount == 0)
					printf("\n---Введенной фамилии не существует в записях. Попробуйте заново---\n");
				break;
			case 2: printf("\nВведите имя для поиска:\n");
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
						printf("Фамилия читателя: %s\n", mas[i].fam);
						printf("Имя читателя: %s\n", mas[i].imya);
						printf("Отчество читателя: %s\n", mas[i].otch);
						printf("Номер читательского билета: %s\n", mas[i].nom);
						printf("Название книги: %s\n", mas[i].nazv);
						printf("День возврата: %s\n", mas[i].vozvrat);
						amount++;
					}
				}
				if (amount == 0)
					printf("\n---Введенного имени не существует в записях. Попробуйте заново---\n");
				break;
			case 3: printf("\nВведите отчество для поиска:\n");
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
						printf("Фамилия читателя: %s\n", mas[i].fam);
						printf("Имя читателя: %s\n", mas[i].imya);
						printf("Отчество читателя: %s\n", mas[i].otch);
						printf("Номер читательского билета: %s\n", mas[i].nom);
						printf("Название книги: %s\n", mas[i].nazv);
						printf("День возврата: %s\n", mas[i].vozvrat);
						amount++;
					}
				}
				if (amount == 0)
					printf("\n---Введенного отчества не существует в записях. Попробуйте заново---\n");
				break;
			case 4: printf("\nВведите номер читательского билета для поиска:\n");
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
						printf("Фамилия читателя: %s\n", mas[i].fam);
						printf("Имя читателя: %s\n", mas[i].imya);
						printf("Отчество читателя: %s\n", mas[i].otch);
						printf("Номер читательского билета: %s\n", mas[i].nom);
						printf("Название книги: %s\n", mas[i].nazv);
						printf("День возврата: %s\n", mas[i].vozvrat);
						amount++;
					}
				}
				if (amount == 0)
					printf("\n---Введенного названия книги не существует в записях. Попробуйте заново---\n");
				break;
			case 5: printf("\nВведите название для поиска:\n");
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
						printf("Фамилия читателя: %s\n", mas[i].fam);
						printf("Имя читателя: %s\n", mas[i].imya);
						printf("Отчество читателя: %s\n", mas[i].otch);
						printf("Номер читательского билета: %s\n", mas[i].nom);
						printf("Название книги: %s\n", mas[i].nazv);
						printf("День возврата: %s\n", mas[i].vozvrat);
						amount++;
					}
				}
				if (amount == 0)
					printf("\n---Введенного названия книги не существует в записях. Попробуйте заново---\n");
				break;
			case 6: printf("\nВведите день возврата для поиска:\n");
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
						printf("Фамилия читателя: %s\n", mas[i].fam);
						printf("Имя читателя: %s\n", mas[i].imya);
						printf("Отчество читателя: %s\n", mas[i].otch);
						printf("Номер читательского билета: %s\n", mas[i].nom);
						printf("Название книги: %s\n", mas[i].nazv);
						printf("День возврата: %s\n", mas[i].vozvrat);
						amount++;
					}
				}
				if (amount == 0)
					printf("\n---Введенного дня возврата не существует в записях. Попробуйте заново---\n");
				break;
			case 7: return;
			default: printf("\n---Не верный ввод числа. Попробуйте снова---\n");
			}
		} while (1);
	}
}
	
void sort()
{
	if (sch == 0)
		printf("\nНет записей.\n");
	else
	{
		for (int i = 0; i < sch-1; i++)
			for (int j = i + 1; j < sch; j++)
				if (strcmp(mas[i].fam, mas[j].fam) > 0)
				{
					alf = mas[i]; mas[i] = mas[j]; mas[j] = alf;
				}

		printf("\nЧитатели в алфавитном порядке: \n");
		for (int i = 0; i < sch; i++)
		{
			printf("\n");
			printf("Фамилия читателя: %s\n", mas[i].fam);
			printf("Имя читателя: %s\n", mas[i].imya);
			printf("Отчество читателя: %s\n", mas[i].otch);
			printf("Номер читательского билета: %s\n", mas[i].nom);
			printf("Название книги: %s\n", mas[i].nazv);
			printf("День возврата: %s\n", mas[i].vozvrat);
		}
	}
}

