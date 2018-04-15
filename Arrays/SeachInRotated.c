#include <stdio.h>
#include <stdlib.h>

int search(int* a, int low, int high, int key){
  if(low>high) return -1;

  int mid = (low+high)/2;

  if(key==a[mid]) return mid;

  if(a[low]<=a[mid]){
    if(key>=a[low] && key<a[mid]){
      return search(a, 0, mid-1, key);
    }
    return search(a, mid+1, high, key);
  }

  else{
    if(key>a[mid] && a[high] >= key){
      return search(a, mid+1, high, key);
    }
    return search(a, low, mid-1, key);
  }

}

int main(void){
  int a[] = {80,90,100,110,120,10,20,30,40,50,60,70};

  int size = sizeof(a)/sizeof(a[0]);
  int key = 90;

  int index = search(a, 0, size-1, key);

  printf("Value: %d, Index: %d\n", a[index], index);

}
