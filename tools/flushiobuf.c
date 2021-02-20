#include "../include/tools/flushiobuf.h"

void flushiobuf()
{
    char ch;
    while ((ch = getchar()) != '\0' && ch != '\n')
        ;
}
