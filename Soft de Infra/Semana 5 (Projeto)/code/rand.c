#include "rand.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void init_rand()
{
    set_rand_seed();
}

void set_rand_seed()
{
    struct timespec ts;
    timespec_get(&ts, TIME_UTC);
    srand(ts.tv_nsec);
}

uint64 rdrand64()
{
    uint64 ret;
    int *ptr = (int *)&ret;
    ptr[0] = rand();
    set_rand_seed();
    ptr[1] = rand();
    return ret;
}