#include <stdio.h>
#include <stdlib.h>

void printArray(int* a, int n){
  int i;
  for(i=0; i<n; i++){
    printf("%d ", a[i]);
  }

  return;
}

void swap(int*a, int*b){
  int temp =*a;
  *a =*b;
  *b = temp;
}

void selectionSort(int* a, int n){
  int i,j, min=0;

  for(i=0; i<n; i++){
    min=i;

    for(j=i+1; j<n; j++){
      if(a[j]<a[min]){
        min = j;
      }
    }
    swap(&a[min], &a[i]);
  }
}


int main(void){
  int arr[] = {3,46,7,1,8,325,35};

  int size = sizeof(arr)/sizeof(arr[0]);
  selectionSort(arr,size);

  printArray(arr, size);

  return 0;
}
