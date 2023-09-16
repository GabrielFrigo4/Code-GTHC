#include <stdio.h>
const char *lower = "abcdefghijklmnopqrstuvwxyz";
const char *upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
  int arg = 0;
  scanf("%d", &arg);
  for(int i = 0; i < arg; i++){
    for(int j = i; j < arg; j++){
      if(j == arg - 1){
        printf("%c ", lower[i]);
      }
      else{
        printf("%c ", upper[i]);
      }
    }
    printf("\n");
  }
  return 0;
}
