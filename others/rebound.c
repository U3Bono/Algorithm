#include "../include/others/rebound.h"

void reboundMain()
{
    float h = 100;

    printf("init: %0.2f\n", h);

    for (int i = 0; i < 10; i++)
    {
        h /= 2;
    }

    printf("after 10 times: %f\n", h);
}
