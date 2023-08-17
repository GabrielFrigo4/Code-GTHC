#include <stdio.h>

int main(){
  int arg = 0;
  scanf("%d", &arg);
  for(int i = 0; i < arg; i++){
    for(int j = 0; j <= i; j++){
      printf("%i ", arg - i);
    }
    printf("\n");
  }
  return 0;
}
