#include "../include/others/fishnet.h"

void fishNetMain()
{
    DATE date;
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("Please input year:");
    setbuf(stdin, NULL);
    scanf("%d", &date.year);

    printf("Please input month:");
    setbuf(stdin, NULL);
    scanf("%d", &date.month);

    printf("Please input day:");
    setbuf(stdin, NULL);
    scanf("%d", &date.day);

    if (isFishing(getDays(date.year, date.month, date.day)))
    {
        printf("Fishing!\n");
    }
    else
    {
        printf("Net drying!\n");
    }
}

int getDays(int year, int month, int day)
{
    int sum = 0;

    for (int i = 2011; i < year; i++)
    {
        sum += 365;
        if (isLeap(i))
        {
            sum += 1;
        }
    }
    sum += days(year, month, day);
    return sum;
}

int isFishing(int days)
{
    int i = days % 5;
    return i > 0 && i < 4;
}
