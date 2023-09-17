#include<stdio.h>
#include<locale.h>
#include<math.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    int i=0, a, b, c, d, nom;
    for (nom = 1000; nom<10000; nom++)
    {
        a = nom / 1000;
        b = (nom / 100)%10;
        c = ((nom%100)-(nom%10))/10;
        d = nom%10;
        if (((a == b) && (c == d)) || ((a == c) && (b == d)) || ((a == d) && (b == c)))
        {
            if ((30 == a + b + c + d) && (0 == nom % 2) && (0 == nom % 7) && (0 == nom % 11))
                i++;
        }
        if (i > 0)
        {
            printf("Номер равен %d.\n", nom);
            i = 0;
        }
    }
    return 0;
}