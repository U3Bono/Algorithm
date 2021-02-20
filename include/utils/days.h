#ifndef _days_h
#define _days_h

#include <stdio.h>

typedef struct
{
    int year;
    int month;
    int day;
} DATE;

int isLeap(int year);
int days(int year, int month, int day);

#endif
