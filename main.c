#include <stdio.h>
#include "include/tools/arrio.h"
#include "include/utils/quicksort.h"

void test();

int main(int argc, const char *argv[])
{
    system("clear");

    test();

    printf("\n");
    return 0;
}

void test()
{
    int a[] = {2, -7, 4, 1, -5, 9, 7, -3, 6, 0, 3, 8, 5, 10, 9, -2, 0};
    int length = sizeof(a) / sizeof(int);
    quickSort(a, length);
    outputArr(a, length);
}
