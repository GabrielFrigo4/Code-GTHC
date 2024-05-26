#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(){
    printf("fileno of -> stdio:{%lli} stdout:{%lli} stderr:{%lli}\n", (int64_t)fileno(stdin), (int64_t)fileno(stdout), (int64_t)fileno(stderr));
    return 0;
}
