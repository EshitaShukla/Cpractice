#include <stdio.h>
//Number which is a factor of only prime numbers 2,3,5

unsigned int min(unsigned int a, unsigned int b, unsigned int c){
  unsigned int minimum = a;

  if(a<=b && a<=c) minimum = a;
  else if(b<=a && b<=c) minimum =b;
  else minimum = c;

  printf("Minimum= %u\n", minimum);
  return minimum;
}

unsigned int findUgly(unsigned int n){
  unsigned int i2=0; unsigned int i3=0; unsigned int i5=0;

  unsigned int ugly[n];
  unsigned int next_multiple_2 = 2;
  unsigned int next_multiple_3 = 3;
  unsigned int next_multiple_5 = 5;

  unsigned int next = 1;
  ugly[0] = 1;
  unsigned int i;
  
  for(i=1; i<n; i++){
    next = min(next_multiple_2, next_multiple_3, next_multiple_5);
    ugly[i] = next;
    printf("Next = %u\n", next);
    if(next == next_multiple_2) {
      i2++;
      next_multiple_2 = ugly[i2]*2;
    }
    if(next == next_multiple_3) {
      i3++;
      next_multiple_3 = ugly[i3]*3;
    }
    if(next == next_multiple_5) {
      i5++;
      next_multiple_5 = ugly[i5]*5;
    }
  }
  return ugly[n-1];
}


int main(void){

  unsigned int n = 150 ;
  unsigned int num = findUgly(n);
  printf("The %uth ugly number is: %u", n, num);
  return 0;
}
