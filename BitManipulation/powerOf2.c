#include <stdio.h>

void powerof2(int x){
  if(x && !(x & (x-1))){
    printf("%d is a power of 2\n", x);
  }
  else{
    printf("%d is not power of 2\n", x);
  }
  return;
}

int main(){
  int a = 0x1010;
  powerof2(0b00000000000000001000);
  powerof2(0x1010);
  return 0;
}
