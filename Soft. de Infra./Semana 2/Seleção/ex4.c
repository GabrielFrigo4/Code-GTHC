#include <stdio.h>

int main(void){
  int a = 0, b = 1;
  if(a == b){
    printf("a = b\n");
  } else {
    printf("a != b\n");
  }
  a = 1;
  if(a == b){
    printf("a = b\n");
  } else {
    printf("a != b\n");
  }
  return 0;
}
