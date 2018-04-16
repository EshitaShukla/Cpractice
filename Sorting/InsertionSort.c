#include <stdio.h>
#include <stdlib.h>

void printArray(int* a, int n){
  int i;
  for(i=0; i<n; i++){
    printf("%d ", a[i]);
  }

  return;
}



void insertionSort(int* a, int n){
  int i;

  for(i=1; i<n; i++){

    int hole =i;
    int temp = a[i];

    while(hole>0 && a[hole-1]>temp){
      a[hole] = a[hole-1];
      hole--;
    }
    a[hole] = temp;

  }
}


int main(void){
  int arr[] = {3,46,7,1,8,325,35};

  int size = sizeof(arr)/sizeof(arr[0]);
  insertionSort(arr,size);

  printArray(arr, size);

  return 0;
}
