#define _GNU_SOURCE
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define BASE 10

int main(void){
  char s1[32], s2[32], s3[32];
  int n1 = 0, n2 = 0, n3 = 0;
  fgets(s1, sizeof(s1), stdin);
  fgets(s2, sizeof(s2), stdin);
  fgets(s3, sizeof(s3), stdin);
  n1 = strtol(s1, NULL, BASE);
  n2 = strtol(s2, NULL, BASE);
  n3 = strtol(s3, NULL, BASE);
  int max = -0;
  if(n1 > n2){
    max = n1;
  } else {
    max = n2;
  }
  if(n3 > max){
    max = n3;
  }
  printf("max is %i\n", max);
  return 0;
}
