#include "../include/others/hanoi.h"

void hanoiMain()
{
    int i;
    printf("Please input the number of tower:");
    scanf("%d", &i);
    hanoi(i, 'A', 'B', 'C');
}

void hanoi(int i, char a, char b, char c) //hanoi整体移动，从a到c
{
    if (i == 1)
    {
        move(a, c);
    }
    else
    {
        hanoi(i - 1, a, c, b); //hanoi整体移动上面i - 1个，从a到b
        move(a, c);            //移动最后一个，从a到c
        hanoi(i - 1, b, a, c); //hanoi整体移动上面i - 1个，从b到c
    }
}

void move(char x, char y) //移动最后一个
{
    printf("move %c to %c\n", x, y);
}
