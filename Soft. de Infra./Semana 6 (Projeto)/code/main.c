#include <stdio.h>
#include "new_types.h"
#include "profile.h"
#include "rand.h"

int main(void)
{
    init_rand();
    printf("Hello World\n");
    uint64 rand = rdrand64();
    printf("Hello World\n");
    printf("%llu\n", rand);
    return 0;
}
