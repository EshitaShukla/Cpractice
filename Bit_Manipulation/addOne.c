#include <stdio.h>

void addOne(int x){
  int m = 1;

  while(x&m){
    x ^= m;
    m<<=1;
  }
  x |= m;
  printf("%d", x);
}



int main(void){

  int x =7;
  addOne(x);

  return 0;
}
