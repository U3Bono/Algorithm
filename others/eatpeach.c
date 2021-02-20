#include "../include/others/eatpeach.h"

void eatPeachMain()
{
    int n;
    printf("Please input the number of times:");
    scanf("%d", &n);

    printf("Loop:\n");
    printf("The number of the peach is %d.\n", loop(n));
    printf("Recursion:\n");
    printf("The number of the peach is %d.\n", recursion(n));
}

int loop(int n)
{
    int a = 1;
    for (int i = n; i > 1; i--)
    {
        a = (a + 1) * 2;
    }

    return a;
}

int recursion(int n)
{
    int a;
    if (n == 1)
    {
        a = 1;
    }
    else
    {
        a = (recursion(n - 1) + 1) * 2;
    }
    return a;
}
