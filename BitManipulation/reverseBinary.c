#include <stdio.h>
#include <stdlib.h>


int reverse(int num){

  int rev = 0;

  while(num>0){
    rev <<= 1;

    if(num & 1){
      rev ^= 1;
    }
    num >>= 1;
  }

  return rev;
}

int main(void){

  int x=11;
  int result = reverse(x);

  printf("The Reverse Binary Integer of %d (Hex: %x) is: %d (Hex: %x)", x, x, result, result );
}
