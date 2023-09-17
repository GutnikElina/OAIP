#include<stdio.h>
#include<locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    float  n = 3, pi4 = 1;
    int i;
    for (i = 0; i < 500; i++) 
    {
        if (i % 2 != 0)
            pi4 += 1 / n;
        else
            pi4 -= 1 / n;
        n += 2;
    }
    printf("Число Пи равно %.8f.\n", pi4*4);
    return 0;
}
