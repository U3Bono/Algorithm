#include "../include/others/chi_money.h"

void chi_MoneyMain()
{
    int a, b, c;
    for(a = 0; a < 21; a++)
    {
        for(b = 0; b < 34; b++)
        {
            c = 100 - a - b;
            if(c % 3 == 0)
            {
                if(100 == a * 5 + b * 3 + c / 3)
                {
                    printf("a = %d, b = %d, c = %d\n", a, b, c);
                }
            }
        }
    }
}