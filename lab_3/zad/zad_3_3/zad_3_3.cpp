#include<stdio.h>
#include<math.h>
#include<locale.h>
int main()
{
    setlocale(LC_ALL, "Rus");
    float s = 20, v1 = 2, v2 = 3, v_sh = 5, time = 0, r = 0;
    int k = 1;
    while (s > 0.00001) 
    {
            time = s / (v_sh + v2);
            r = v_sh * time;
            s = s - time * (v1 + v2);
            printf("Расстояние, которое пролетел шмель  %f км.\n", r);
            time = s / (v_sh + v1);
            r = v_sh * time;
            s = s - time * (v1 + v2);
            printf("Расстояние, которое пролетел шмель %f км.\n", r);
    }
    return 0;
}