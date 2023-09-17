#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<locale.h>
#include<stdlib.h>

int main()
{

	char str1[101], str2[101];
	int i;
	printf("\nVvedite pervyu stroky: \n");
	gets_s(str1);

	printf("\nVvedite vtoryu stroky: \n");
	gets_s(str2);
	printf("\n");

	for (i = 0; (str1[i] != 0) && (i < 101); i++)         //маленькие буквы
		printf("%c", tolower(str1[i]));
	printf("\n");
	for (i = 0; (str1[i] != 0) && (i < 101); i++)
		printf("%c", toupper(str1[i]));                   //заглавные буквы
	printf("\n");

	strupr(str1);
	puts(str1);
	printf("\n");

	strlwr(str2);
	puts(str2);
	printf("\n");

    printf("%d", strlen(str1));  //длина первой строки 
	printf("\n");

    printf("%d", strlen(str2));  //длина второй строки 
	printf("\n");
	
	printf("%d", strcmp(str1, str2));   //сравнивает две строки, если равны, то выводит 0; если s1>s2 - <0; если s1<s2 - >0;
	printf("\n");

	printf("%d", strcspn(str1, str2));    //определяет длину начального сегмента строки s1, 
	                                      // содержащего те символы, которые не входят в строку s2
	printf("\n");

	strcpy_s(str1, str2);     //побайтное копирование из строки str2 в строку str1
	puts(str1);
	printf("\n");

	strncpy_s(str1, str2, 1);    //копирует kol символов строки str2 в строку str1
	puts(str1);
	printf("\n");

	strcat_s(str1, str2);     //приписывает строку str1 к строке str2
	puts(str1);
	printf("\n");



	return 0;
}