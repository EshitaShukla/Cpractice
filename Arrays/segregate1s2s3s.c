#include <stdio.h>
#include <stdlib.h>


void swap(int* a1, int* a2){
  int temp;
  temp = *a1;
  *a1 = *a2;
  *a2 = temp;

  return;
}

void printArr(int arr[], int size){
  int i;

  for(i=0; i<size; i++){
    printf("%d ", arr[i]);
  }

  printf("\n");
}

void sortSpecial(int* arr, int l, int r){

//*******************************************************
  int mid = 1;
//*******************************************************
  while(mid<=r){
    switch(*(arr+mid)){
    case 1:
        swap(arr+mid, arr+l);
        l++;
        break;


    case 2:
        mid++;
       break;

    case 3:
       swap(arr+mid, arr+r);
       r--;

   }
  }

}

int main(void){

  int arr[] = {1,2,1,2,3,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,2,2,3,1,3};
  int size = sizeof(arr)/sizeof(arr[0]);

  printArr(arr, size);
  sortSpecial(arr, 0, size-1);
  printArr(arr, size);
  return 0;
}
