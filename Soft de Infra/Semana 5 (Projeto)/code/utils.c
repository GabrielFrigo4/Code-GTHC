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

uint32 wstrlen(const wchar *wstr)
{
    int len = 0;
    while (wstr[len] != L'\0')
    {
        len++;
    }
    return len;
}