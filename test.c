#include <stdio.h>
#include <stdlib.h>

void main()
{
    int random = rand();
    int* randomp = &random;
    printf("%d\n%d", random, randomp[2]);
}