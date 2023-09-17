/* CUSTOM */
#include "utils.h"

uint32 arrlen(const void **arr)
{
    int len = 0;
    while (arr[len] != NULL)
    {
        len++;
    }
    return len;
}