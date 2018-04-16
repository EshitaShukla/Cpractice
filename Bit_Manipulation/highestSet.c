#include<stdio.h>


int highestSet(int num){
  int count = 0;

  while(num >>= 1){
    count++;
  }
  return count;
}
int main(){
  int a = 5;

  int position = highestSet(a);

  printf("the highest set bit is at position: %d, The bit %d.\n", position, position+1 );
  return 0;
}
