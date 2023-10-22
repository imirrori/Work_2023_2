#include <stdio.h>

//Дано натуральное чилос N
//Вывести все натуральные числа, на которые делится N, без остатка

int main()
{
    unsigned long long int N;
    printf("Please enter N: ");
    scanf("%llu", &N);

    printf("Divider N is: ");
    for(unsigned long long int i = 1; i < N; ++i)
    {
        if ((N % i) == 0)
        {
            printf("%llu ", i);
        }
    }
    printf("\n");

    return 0;
}
