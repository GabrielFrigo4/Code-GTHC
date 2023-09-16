#include <stdio.h>

int main(){
  int arg = 0;
  scanf("%d", &arg);
  for(int i = 1; i <= arg; i++){
    for(int j = 0; j < arg; j++){
      if(arg - i == j ||
        j == arg - 1){
        printf("1 ");
      }
      else if(arg - i < j){
        printf("%i ", i - 1);
      }
      else{
        printf("  ");
      }
    }
    printf("\n");
  }
  return 0;
}
