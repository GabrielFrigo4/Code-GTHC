#include <stdio.h>

int main(void){
  char input1[256];
  printf("qual é o seu nome? ");
  fgets(input1, sizeof(input1), stdin);
  char input2[256];
  printf("qual é a sua idade? ");
  fgets(input2, sizeof(input2), stdin);
  printf("o seu nome é %se a sua idade é %s", input1, input2);
  return 0;
}
