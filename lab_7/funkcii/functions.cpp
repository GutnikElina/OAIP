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

	for (i = 0; (str1[i] != 0) && (i < 101); i++)         //��������� �����
		printf("%c", tolower(str1[i]));
	printf("\n");
	for (i = 0; (str1[i] != 0) && (i < 101); i++)
		printf("%c", toupper(str1[i]));                   //��������� �����
	printf("\n");

	strupr(str1);
	puts(str1);
	printf("\n");

	strlwr(str2);
	puts(str2);
	printf("\n");

    printf("%d", strlen(str1));  //����� ������ ������ 
	printf("\n");

    printf("%d", strlen(str2));  //����� ������ ������ 
	printf("\n");
	
	printf("%d", strcmp(str1, str2));   //���������� ��� ������, ���� �����, �� ������� 0; ���� s1>s2 - <0; ���� s1<s2 - >0;
	printf("\n");

	printf("%d", strcspn(str1, str2));    //���������� ����� ���������� �������� ������ s1, 
	                                      // ����������� �� �������, ������� �� ������ � ������ s2
	printf("\n");

	strcpy_s(str1, str2);     //��������� ����������� �� ������ str2 � ������ str1
	puts(str1);
	printf("\n");

	strncpy_s(str1, str2, 1);    //�������� kol �������� ������ str2 � ������ str1
	puts(str1);
	printf("\n");

	strcat_s(str1, str2);     //����������� ������ str1 � ������ str2
	puts(str1);
	printf("\n");



	return 0;
}