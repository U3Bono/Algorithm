#include "../include/strings/letternum.h"

void letterNumMain()
{
    int i;
    char c;

    printf("Please input a string:\n");
    getchar();

    i = 0;
    while ((c = getchar()) != '\n')
    {
        if ((c > 'a' && c < 'z') || (c > 'A' && c < 'Z'))
        {
            i++;
        }
    }
    printf("The number of the string:%d\n", i);
}
