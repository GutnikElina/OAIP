//Создать текстовый файл F1 не менее, чем из 10 строк и записать в него информацию.
//Скопировать в файл F2 только четные строки из F1.

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "rus");
	FILE* F1, * F2;
	fopen_s(&F1, "file1.txt", "w+t");
	fopen_s(&F2, "file2.txt", "w+t");

	if (F1 != NULL)
	{
		printf("Файл file1.txt успешно создан!\n");

		char line[256]{};
		int k;
		for (int i = 1; i < 11; i++)
		{
			k = 0;
			printf("Строка №%d \n", i );
			gets_s(line);
			fputs(line, F1);
			fprintf(F1, "\n");
			if (i % 2 == 0)
				k++;
			if (k != 0)
			{
				fputs(line, F2);
				fprintf(F2, "\n");
			}
		}
		printf("\nГотово!\nДанные записаны в file1.txt и скопированы четные строки в file2.txt.\n");
		fclose(F1);
		fclose(F2);
		return 0;
	}
	else
	{
		fprintf(stderr, "\nНе удалось создать или открыть файл file1.txt.\n");
		return 1;
	}
}

		








