#include "../../include/utils/reverse.h"

void reverse(void *a, int l, int typesize)
{
    void *temp = malloc(typesize);
    for (int i = 0; i < l / 2; i++)
    {
        memcpy(temp, a + i * typesize, typesize);
        memcpy(a + i * typesize, a + (l - 1 - i) * typesize, typesize);
        memcpy(a + (l - 1 - i) * typesize, temp, typesize);
    }

    free(temp);
}
