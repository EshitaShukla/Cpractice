#include <stdio.h>
int main(void){
  int x = 11;
  int one = 0;

  if(x<1) return -1;

  while(x){
    x=x>>1;
    if(x&1)one++;
  }
  if(one>1) printf("Not a power");
  else printf("Is a power");
}
