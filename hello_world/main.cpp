#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    double a = 7.25;
    for(size_t i = 0; i < sizeof(a); ++i) {
        for (size_t j = 0; j < CHAR_BIT; ++j) {
            printf("%d", ( (*((char*)&a + i)) & 1 << (CHAR_BIT - 1 - j) ) ? 1 : 0);
        }
        printf("\n");
    }
    return 0;
}
