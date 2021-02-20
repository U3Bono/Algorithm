#include "../include/strings/palstr.h"

void palStrMain()
{
    char s[NUM];
    int l;

    printf("Please input a string(<=50):\n");
    scanf("%s", s);

    l = getLen(s);

    for (int i = 0; i < l / 2; i++)
    {
        if (*(s + i) != *(s + l - 1 - i))
        {
            printf("It's not palindrome string!\n");
            return;
        }
    }

    printf("It's palindrome string!\n");
}

int getLen(char *s)
{
    int l = 0;
    while (l < 50)
    {
        if (*(s + l) == '\0')
        {
            break;
        }
        l++;
    }

    return l;
}
