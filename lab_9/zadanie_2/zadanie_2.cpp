//Сформировать бинарный файл из элементов, заданной в варианте структуры, распечатать его содержимое, 
//выполнить добавление элементов в соответствии со своим вариантом и поиск по одному из параметров
//(например, по фамилии, по государственному номеру, по году рождения и т.д.).
//Формирование, печать, добавление, поиск элементов и выбор желаемого действия оформить в виде функций.
//Предусмотреть сообщения об ошибках при открытии файла и выполнении операций ввода / вывода.

//Структура «Читатель»: Фамилия И.О., номер читательского билета, название книги, день возврата.

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
		printf("Файл reader.txt успешно создан!\n");
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
			default: printf("\n---Не верный ввод числа. Попробуйте снова.\n"); break;
			}
		}
		fclose(file);
	}
	else
	{
		fprintf(stderr, "Не удалось создать или открыть файл reader.txt.\n");
		return 1;
	}
}

void menu()
{
	printf("\n-----МЕНЮ-----\n");
	printf("  Выберите:\n");
	printf("1-для ввода новой записи\n");
	printf("2-для вывода записи(ей) в файл\n");
	printf("3-для поиска записи(ей)\n");
	printf("4-для изменения записи(ей)\n");
	printf("5-для выхода\n\n");
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
		printf("\n---Не верный ввод числа. Попробуйте снова.\n");
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
			int k = check();
			printf("Фамилия читателя: %s\n", mas[k - 1].fam);
			printf("Имя читателя: %s\n", mas[k - 1].imya);
			printf("Отчество читателя: %s\n", mas[k - 1].otch);
			printf("Номер читательского билета: %s\n", mas[k - 1].nom);
			printf("Название книги: %s\n", mas[k - 1].nazv);
			printf("День возврата: %s\n", mas[k - 1].vozvrat);

			fprintf(file, "\nФамилия читателя: ");
			fputs(mas[k - 1].fam, file);
			fprintf(file, "\nИмя читателя: ");
			fputs(mas[k - 1].imya, file);
			fprintf(file, "\nОтчество читателя: ");
			fputs(mas[k - 1].otch, file);
			fprintf(file, "\nНомер читательского билета: ");
			fputs(mas[k - 1].nom, file);
			fprintf(file, "\nНазвание книги: ");
			fputs(mas[k - 1].nazv, file);
			fprintf(file, "\nДень возврата: ");
			fputs(mas[k - 1].vozvrat, file);
			fprintf(file, "\n");

			printf("\nДанные выведены в файле!\n");
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

				fprintf(file, "\nФамилия читателя: ");
				fputs(mas[i].fam, file);
				fprintf(file, "\nИмя читателя: ");
				fputs(mas[i].imya, file);
				fprintf(file, "\nОтчество читателя: ");
				fputs(mas[i].otch, file);
				fprintf(file, "\nНомер читательского билета: ");
				fputs(mas[i].nom, file);
				fprintf(file, "\nНазвание книги: ");
				fputs(mas[i].nazv, file);
				fprintf(file, "\nДень возврата: ");
				fputs(mas[i].vozvrat, file);
				fprintf(file, "\n");

				printf("\nДанные выведены в файле!\n");
			}
		}
		else printf("\n---Не верный ввод числа.Попробуйте снова---\n");
	}
}

void find()
{
	int break_find, amount;
	char find_fam[30], find_imya[20], find_otch[30], find_nazv[30], find_nom[30], find_vozvrat[30];
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
					for (int b = 0; b < (strlen(find_fam)) && break_find == 0; b++)
					{
						if (find_fam[b] != mas[i].fam[b])
							break_find++;
					}
					if (break_find == 0)
					{
						printf("\nЗапись №%d: \n", i + 1);
						printf("Фамилия читателя: %s\n", mas[i].fam);
						printf("Имя читателя: %s\n", mas[i].imya);
						printf("Отчество читателя: %s\n", mas[i].otch);
						printf("Номер читательского билета: %s\n", mas[i].nom);
						printf("Название книги: %s\n", mas[i].nazv);
						printf("День возврата: %s\n", mas[i].vozvrat);

						fprintf(file, "\n---Успешный поиск по фамилии читателя---\n");
						fprintf(file, "\nФамилия читателя: ");
						fputs(mas[i].fam, file);
						fprintf(file, "\nИмя читателя: ");
						fputs(mas[i].imya, file);
						fprintf(file, "\nОтчество читателя: ");
						fputs(mas[i].otch, file);
						fprintf(file, "\nНомер читательского билета: ");
						fputs(mas[i].nom, file);
						fprintf(file, "\nНазвание книги: ");
						fputs(mas[i].nazv, file);
						fprintf(file, "\nДень возврата: ");
						fputs(mas[i].vozvrat, file);
						fprintf(file, "\n");

						printf("\nДанные выведены в файле!\n");
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
						printf("\nЗапись №%d: \n", i + 1);
						printf("Фамилия читателя: %s\n", mas[i].fam);
						printf("Имя читателя: %s\n", mas[i].imya);
						printf("Отчество читателя: %s\n", mas[i].otch);
						printf("Номер читательского билета: %s\n", mas[i].nom);
						printf("Название книги: %s\n", mas[i].nazv);
						printf("День возврата: %s\n", mas[i].vozvrat);

						fprintf(file, "\n---Успешный поиск по имени читателя---\n");
						fprintf(file, "\nФамилия читателя: ");
						fputs(mas[i].fam, file);
						fprintf(file, "\nИмя читателя: ");
						fputs(mas[i].imya, file);
						fprintf(file, "\nОтчество читателя: ");
						fputs(mas[i].otch, file);
						fprintf(file, "\nНомер читательского билета: ");
						fputs(mas[i].nom, file);
						fprintf(file, "\nНазвание книги: ");
						fputs(mas[i].nazv, file);
						fprintf(file, "\nДень возврата: ");
						fputs(mas[i].vozvrat, file);
						fprintf(file, "\n");

						printf("\nДанные выведены в файле!\n");
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
						printf("\nЗапись №%d: \n", i + 1);
						printf("Фамилия читателя: %s\n", mas[i].fam);
						printf("Имя читателя: %s\n", mas[i].imya);
						printf("Отчество читателя: %s\n", mas[i].otch);
						printf("Номер читательского билета: %s\n", mas[i].nom);
						printf("Название книги: %s\n", mas[i].nazv);
						printf("День возврата: %s\n", mas[i].vozvrat);

						fprintf(file, "\n---Успешный поиск по отчеству читателя---\n");
						fprintf(file, "\nФамилия читателя: ");
						fputs(mas[i].fam, file);
						fprintf(file, "\nИмя читателя: ");
						fputs(mas[i].imya, file);
						fprintf(file, "\nОтчество читателя: ");
						fputs(mas[i].otch, file);
						fprintf(file, "\nНомер читательского билета: ");
						fputs(mas[i].nom, file);
						fprintf(file, "\nНазвание книги: ");
						fputs(mas[i].nazv, file);
						fprintf(file, "\nДень возврата: ");
						fputs(mas[i].vozvrat, file);
						fprintf(file, "\n");

						printf("\nДанные выведены в файле!\n");
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
						printf("\nЗапись №%d: \n", i + 1);
						printf("Фамилия читателя: %s\n", mas[i].fam);
						printf("Имя читателя: %s\n", mas[i].imya);
						printf("Отчество читателя: %s\n", mas[i].otch);
						printf("Номер читательского билета: %s\n", mas[i].nom);
						printf("Название книги: %s\n", mas[i].nazv);
						printf("День возврата: %s\n", mas[i].vozvrat);

						fprintf(file, "\n---Успешный поиск по номеру читательского билета---\n");
						fprintf(file, "\nФамилия читателя: ");
						fputs(mas[i].fam, file);
						fprintf(file, "\nИмя читателя: ");
						fputs(mas[i].imya, file);
						fprintf(file, "\nОтчество читателя: ");
						fputs(mas[i].otch, file);
						fprintf(file, "\nНомер читательского билета: ");
						fputs(mas[i].nom, file);
						fprintf(file, "\nНазвание книги: ");
						fputs(mas[i].nazv, file);
						fprintf(file, "\nДень возврата: ");
						fputs(mas[i].vozvrat, file);
						fprintf(file, "\n");

						printf("\nДанные выведены в файле!\n");
						amount++;
					}
				}
				if (amount == 0)
					printf("\n---Введенного номера читательского билета не существует в записях. Попробуйте заново---\n");
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
						printf("\nЗапись №%d: \n", i + 1);
						printf("Фамилия читателя: %s\n", mas[i].fam);
						printf("Имя читателя: %s\n", mas[i].imya);
						printf("Отчество читателя: %s\n", mas[i].otch);
						printf("Номер читательского билета: %s\n", mas[i].nom);
						printf("Название книги: %s\n", mas[i].nazv);
						printf("День возврата: %s\n", mas[i].vozvrat);

						fprintf(file, "\n---Успешный поиск по названию книги---\n");
						fprintf(file, "\nФамилия читателя: ");
						fputs(mas[i].fam, file);
						fprintf(file, "\nИмя читателя: ");
						fputs(mas[i].imya, file);
						fprintf(file, "\nОтчество читателя: ");
						fputs(mas[i].otch, file);
						fprintf(file, "\nНомер читательского билета: ");
						fputs(mas[i].nom, file);
						fprintf(file, "\nНазвание книги: ");
						fputs(mas[i].nazv, file);
						fprintf(file, "\nДень возврата: ");
						fputs(mas[i].vozvrat, file);
						fprintf(file, "\n");

						printf("\nДанные выведены в файле!\n");
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
						if (find_vozvrat[b] != mas[i].nazv[b])
							break_find++;
					}
					if (break_find == 0)
					{
						printf("\nЗапись №%d: \n", i + 1);
						printf("Фамилия читателя: %s\n", mas[i].fam);
						printf("Имя читателя: %s\n", mas[i].imya);
						printf("Отчество читателя: %s\n", mas[i].otch);
						printf("Номер читательского билета: %s\n", mas[i].nom);
						printf("Название книги: %s\n", mas[i].nazv);
						printf("День возврата: %s\n", mas[i].vozvrat);

						fprintf(file, "\n---Успешный поиск по дню возврата---\n");
						fprintf(file, "\nФамилия читателя: ");
						fputs(mas[i].fam, file);
						fprintf(file, "\nИмя читателя: ");
						fputs(mas[i].imya, file);
						fprintf(file, "\nОтчество читателя: ");
						fputs(mas[i].otch, file);
						fprintf(file, "\nНомер читательского билета: ");
						fputs(mas[i].nom, file);
						fprintf(file, "\nНазвание книги: ");
						fputs(mas[i].nazv, file);
						fprintf(file, "\nДень возврата: ");
						fputs(mas[i].vozvrat, file);
						fprintf(file, "\n");

						printf("\nДанные выведены в файле!\n");
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

void change()
{
	if (sch == 0)
		printf("\n---Нет записей---\n");
	else
	{
		printf("\nВведите номер записи: \n");
		int zap = check(), izm;
		if (zap <= sch)
		{
			do
			{
				izm = 0;
				printf("\nВведите: \n");
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
					izm++;
					break;
				case 2: printf("\nВведите новое имя:\n");
					gets_s(mas[zap - 1].imya);
					izm++;
					break;
				case 3: printf("\nВведите новое отчество:\n");
					gets_s(mas[zap - 1].otch);
					izm++;
					break;
				case 4: printf("\nВведите новый номер читательского билета:\n");
					gets_s(mas[zap - 1].nom);
					izm++;
					break;
				case 5: printf("\nВведите новое название книги:\n");
					gets_s(mas[zap - 1].nazv);
					izm++;
					break;
				case 6: printf("\nВведите новый день возврата:\n");
					gets_s(mas[zap - 1].vozvrat);
					izm++;
					break;
				case 7: return;
				default: printf("\n---Не верный ввод числа. Попробуйте снова---\n");
				}
				if (izm != 0)
				{
					fprintf(file, "\n---Запись после изменения---\n");
					fprintf(file, "\nФамилия читателя: ");
					fputs(mas[zap - 1].fam, file);
					fprintf(file, "\nИмя читателя: ");
					fputs(mas[zap - 1].imya, file);
					fprintf(file, "\nОтчество читателя: ");
					fputs(mas[zap - 1].otch, file);
					fprintf(file, "\nНомер читательского билета: ");
					fputs(mas[zap - 1].nom, file);
					fprintf(file, "\nНазвание книги: ");
					fputs(mas[zap - 1].nazv, file);
					fprintf(file, "\nДень возврата: ");
					fputs(mas[zap - 1].vozvrat, file);
					fprintf(file, "\n");
				}

			} while (1);
		}
		else printf("\n---Не верный ввод числа. Попробуйте снова---\n");
	}
}