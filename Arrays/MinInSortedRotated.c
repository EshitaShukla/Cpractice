#include <stdio.h>
#include <stdlib.h>

int search(int* a, int low, int high){
  if(low>high) return -1;

  int mid = (low+high)/2;

  int min = a[mid];
  //if(key==a[mid]) return mid;

  if(a[low]<a[mid]){
    min =a[low];

  }

  if(a[mid+1] < min){
      min = a[mid+1];
    }


  return min;

}

int main(void){
  int a[] = {80,90,100,110,120,10,20,30,40,50,60,70};

  int size = sizeof(a)/sizeof(a[0]);

  int min = search(a, 0, size-1);

  printf("Value: %d\n", min);

}
