#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Определить местоположение элементов массива А не встречающихся в массиве В

int main()
{
    constexpr int SIZE = 10;
    int A[SIZE];
    int B[SIZE];

    srand(time(NULL));

    for(int i = 0; i < SIZE; ++i) {
        A[i] = rand() % 10;
        B[i] = rand() % 10;
    }

    printf("A: ");
    for(int i = 0; i < SIZE; ++i) {
        printf("%d ", A[i]);
    }
    printf("\nB: ");
    for(int i = 0; i < SIZE; ++i) {
        printf("%d ", B[i]);
    }
    printf("\n");

    for(int i = 0; i < SIZE; ++i)
    {
        bool found = false;
        for(int j = 0; j < SIZE; ++j)
        {
            if(A[i] == B[j])
            {
                found = true;
                break;
            }
        }
        if (!found) {
            printf("%d ", i);
        }
    }


    return 0;
}
