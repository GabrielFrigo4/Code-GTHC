#define _GNU_SOURCE
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
  int n1 = 0, n2 = 0, n3 = 0;
  scanf("%d%d%d", &n1, &n2, &n3);
  if (n1 == n2 && n2 == n3) {
    printf("É equilátero\n");
  } else if(n1 == n2 ||
            n1 == n3 ||
            n2 == n3){
    printf("É isóceles\n");
  } else {
    printf("É escaleno\n");
  }
  return 0;
}
