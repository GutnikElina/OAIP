#include<stdio.h>
#include<locale.h>
#include<math.h>

int main()
{
	setlocale(LC_ALL, "Rus");
    int n, sp = 0, i, j;
    printf("¬ведите число n: ");
    scanf_s("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
            if (n == pow(i,3) + pow(j,3)) sp++;
    }
    printf("\n%d способ(ов).\n", sp);
	return 0;
}

/*—оставить алгоритм, определ€ющий количество способов, какими задуманное 
число n>1 можно представить в виде суммы n=i3+j3, счита€, что перестановка 
слагаемых нового способа не даЄт.*/