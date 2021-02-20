#include "../../include/utils/days.h"

int days(int year, int month, int day)
{
    int sum = 0;
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int leapYear = isLeap(year);

    if (leapYear)
    {
        printf("It's leap year.\n");
        days[2] = 29;
    }

    if (day < 1 || day > days[month])
    {
        printf("Input error!\n");
        return 0;
    }

    for (int i = 0; i < month; i++)
    {
        sum += days[i];
    }
    sum += day;

    return sum;
}

int isLeap(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}
