#include <math.h>
#include <stdio.h>

//Написать программу, которая имеет меню с выбором матеиматичекой операции
/*
 1. Calculate cos(x)
 2. Calculate sin(x)
 3. Exit
*/
int main()
{
    int ch = 0;
    double x;

    do
    {
        printf("1. Calculate cos(x)\n"
               "2. Calculate sin(x)\n"
               "3. Exit\n");
        ch = getchar();
        switch(ch)
        {
            case '1':
            {
                printf("Please enter x, for calculate cos(x)\n");
                scanf("%lf", &x);
                printf("cos(x): %lf\n", cos(x));
                break;
            }
            case '2':
            {
                printf("Please enter x, for calculate sin(x)\n");
                scanf("%lf", &x);
                printf("sin(x): %lf\n", sin(x));
                break;
            }
        }
        getchar();
    }while(ch != '3');

    return 0;
}
