#define _GNU_SOURCE
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
const char vogais[] = {'a', 'e', 'i', 'o', 'u'};
int main(void){
  char letra;
  scanf("%c", &letra);
  for(int i = 0; i < 5; i++){
    if(letra == vogais[i]){
      printf("É vogal\n");
      return 0;
    }
  }
  printf("É consoante\n");
  return 0;
}
