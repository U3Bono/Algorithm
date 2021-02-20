#include "../include/tools/arrio.h"

void inputArr(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
}

void outputArr(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(a + i));
    }
    printf("\n");
}