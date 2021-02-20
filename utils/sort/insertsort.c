#include "../../include/utils/insertsort.h"

static int ct, st;

void insertSort(int *a, int n)
{
    int temp;
    int i, j;
    ct = 0, st = 0;

    for (i = 1; i < n; i++)
    {
        for (j = i; *(a + j - 1) > *(a + j) && j != 0; j--)
        {
            temp = *(a + j);
            *(a + j) = *(a + j - 1);
            *(a + j - 1) = temp;
            ct++;
            st++;
        }
    }

    printf("compare %d times, switch %d times.\n", ct, st);
}