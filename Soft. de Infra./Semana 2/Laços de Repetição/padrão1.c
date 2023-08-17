#include <stdio.h>

int main(){
  int arg = 0;
  scanf("%d", &arg);
  for(int i = 1; i <= arg; i++){
    for(int j = 0; j < i; j++){
      printf("%i ", (j+i) % 2);
    }
    printf("\n");
  }
  return 0;
}
