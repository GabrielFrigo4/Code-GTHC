/* SYSTEM */
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
/* CUSTOM */
#include "rand.h"

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

uint8 rdrand8()
{
    uint8 ret;
    uint32 rnd = rand();
    set_rand_seed();
    uint8 *ptr = (uint8 *)&rnd;
    ret = ptr[0];
    return ret;
}

uint16 rdrand16()
{
    uint16 ret;
    uint32 rnd = rand();
    set_rand_seed();
    uint16 *ptr = (uint16 *)&rnd;
    ret = ptr[0];
    return ret;
}

uint32 rdrand32()
{
    uint32 ret;
    ret = rand();
    set_rand_seed();
    return ret;
}

uint64 rdrand64()
{
    uint64 ret;
    uint32 *ptr = (uint32 *)&ret;
    ptr[0] = rand();
    set_rand_seed();
    ptr[1] = rand();
    return ret;
}