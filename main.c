#include <stdio.h>
#include <string.h>
#include <time.h>
#include "include/strings/swapletter.h"

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
    char s1[] = "AM I OLDER YOU THAN";
    char s2[] = "AM I OLDER THAN YOU";
    swap_letter(s1, s2);
    printf("%s\n%s\n", s1, s2);
}

