#include <stdio.h>
#include <math.h>

int main(void){
  int x1 = 0, y1 = 0;
  int x2 = 3, y2 = 4;
  int dx = x1-x2, dy = y1 - y2;
  printf("a distancia do ponto 1 pro 2 é %f\n", sqrt(dx*dx + dy*dy));
  return 0;
}
