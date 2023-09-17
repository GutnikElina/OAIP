#include<stdio.h>
#include<locale.h>
#include<math.h>
#include<conio.h>

int main()
{
	setlocale(LC_ALL, "Rus"); 
	float x, a;
	printf("Введите число a: \n");
	scanf_s("%f", &a);
	x = a * a + 1;
	while (x < 1000001)
	{
		x *= x; ++x;
	}
	printf("\nЧисло после преобразований равно %1.f\n", x);
	a = _getch();
	return 0;
}

/*Число a возводят в квадрат и результат увеличивают на 1. Полученное число снова возводят в квадрат
и увеличивают на 1. Этот процесс продолжается до тех пор, пока не будет получено число X, большее миллиона. Найти число X.*/