#include<stdio.h>
#include<stdlib.h>

int main(void){
  int x = 11;
  int count = 0;
  while(x){
    x &= (x-1);
    count++;
  }

  printf("%d", count);
  return 0;
}
