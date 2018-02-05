#include<stdio.h>

int reverseBinary(int num){
  int rev = 0;
  while(num > 0){
    rev <<= 1;
    if(num & 1){
      rev ^= 1;
    }
    num >>=1;
  }
  return rev;
}

int main(){
  int a = 11;

  a = reverseBinary(a);
  printf("%d", a);

  return 0;
}
