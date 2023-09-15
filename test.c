#include <stdio.h>
#include <stdlib.h>

int compareArray(int a[], int b[], int len)
{
    int test = 1;
    for (int n = 0; n < len; n++)
    {
        if (a[n] != b[n])
        {
            test = 0;
        }
    }
    return test;
}

void main()
{
    int i[] = {3, 3};
    int j[] = {3, 3};
    printf("%d", i==j);
    if (i == j)
    {
        printf("ok");
    }
    int test = 1;
    for (int n = 0; n < 2; n++)
    {
        if (i[n] != j[n])
        {
            test = 0;
        }
    }
    printf("%d", compareArray(i, j, 2));
}