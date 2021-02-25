#include <stdio.h>
#include <string.h>
#include <time.h>
#include "include/tools/stringop.h"

void test();

int main(int argc, const char *argv[])
{
    system("clear");

    test();

    printf("\n");
    return 0;
}

#define STU_NUM 10

typedef struct
{
    int num;
    char name[20];
} Stu;

void test()
{
    clock_t start, finish;
    char s1[] = "student";
    char s2[] = " infomation";
    char *s3 = safe_strcat(s1, s2);

    printf("%s", s3);
    free(s3);
}
