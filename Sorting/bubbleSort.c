#include <stdio.h>
#include <stdlib.h>

void printArray(int* a, int n){
  int i;
  for(i=0; i<n; i++){
    printf("%d ", a[i]);
  }

  return;
}

void swap(int* a, int* b){
  int temp=0;

  temp =*a;
  *a = *b;
  *b = temp;

  return;
}

void bubbleSort(int* a, int n){
  int i, j; bool swapped;

  for(i=0; i<n-1; i++){
    swapped=false;
    for(j=0; j<n-1; j++){
      if(a[j] > a[j+1]){
        swap(&a[j], &a[j+1]);
        swapped =true;
      }
    }
    if(swapped==false) return;
  }
  return;
}

int main(void){
  int arr[] = {3,46,7,1,8,325,35};

  int size = sizeof(arr)/sizeof(arr[0]);
  bubbleSort(arr,size);

  printArray(arr, size);

  return 0;
}
