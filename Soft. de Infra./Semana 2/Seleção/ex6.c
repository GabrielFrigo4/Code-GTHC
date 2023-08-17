#define _GNU_SOURCE
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define BASE 10

int main(void){
  char s1[32];
  int n1 = 0;
  fgets(s1, sizeof(s1), stdin);
  n1 = strtol(s1, NULL, BASE);
  if(n1 % 2 == 1){
    printf("É impar\n");
  } else {
    printf("É par\n");
  }
  return 0;
}
