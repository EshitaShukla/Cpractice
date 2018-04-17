#include <stdio.h>
#include <stdlib.h>
#define MAX 55
int fib(int* a, int n){

  if(n>=MAX) return -1;

  if(a[n] == -1){
    if(n<=1){
      a[n] = n;
    }
    else{
      a[n] = fib(a, n-1) + fib(a, n-2);
    }

  }

  return a[n];

}

int main(void){
  int n = 54;
  int memList[MAX];
  int i;
  for(i=0;i<MAX;i++){
    memList[i] = -1;
  }

  printf("The Number is: %d", fib(memList, n));

}
