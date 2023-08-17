#include <stdio.h>
const char *lower = "abcdefghijklmnopqrstuvwxyz";
const char *upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
  int arg = 0;
  scanf("%d", &arg);
  int char_count = 0;
  for(int i = 1; i <= arg; i++){
    int char_printed_count = 0;
    for(int j = 0; j < arg; j++){
      if(arg - i <= j){
        char print_char = '\0';
        if((i + char_printed_count) % 2 == 1){
          print_char = upper[char_count];
        }
        else{
          print_char = lower[char_count];
        }
        printf("%c ", print_char);
        char_printed_count++;
        char_count++;
      }
      else{
        printf("  ");
      }
    }
    printf("\n");
  }
  return 0;
}
