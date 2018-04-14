/*
Rotate an array by D elements: The Reversal Algorithm
*/

#include <stdio.h>
#include <stdlib.h>

void reverse(int* a, int start, int end){
 // printf("The address of a in reverse: %xd\n", &a);
  int temp;
  while(start < end){
    temp = a[start];
    a[start++] = a[end];
    a[end--] = temp;
  }
}

int main(void){
  int a[] = {10,20,30,40,50,60,70};

  int size = sizeof(a)/sizeof(a[0]);
  printf("The size of the array is: %d\n", size);

  int d = 3, i;
  //printf("The address of a in main: %xd", &a);
  reverse(a, 0, d-1);
  reverse(a, d, size-1);
  reverse(a, 0, size-1);

  for(i=0; i<size;i++){
    printf("%d ", a[i]);
  }


}
