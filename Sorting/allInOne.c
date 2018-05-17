#include<stdio.h>
#include<limits.h>

void swap(int *a, int* b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;

  return;
}


void insertionSort(int* arr, unsigned int size){

  int hole = 0;
  int j = -1;
  int i = 0;

  for(i=0; i<size; i++){
    hole = *(arr+i);
    j = i-1;
    while(j>=0 && *(arr+j) > hole){
      *(arr+j+1) = *(arr+j);
      j--;
    }

    *(arr+j+1) = hole;
  }

}


void bubbleSort(int* arr, unsigned int size){
  unsigned int i = 0;
  int j= 0;

  for(i=0; i<size; i++){
    for(j=0; j<size-1;j++){
      if(*(arr+j) > *(arr+j+1))
        swap(arr+j, arr+j+1);
    }
  }

}



void selectionSort(int* arr, unsigned int size){
  unsigned int i = 0;
  unsigned int j = 0;
  int min = INT_MIN;

  for(i=0;i<size-1; i++){
    min = i;

    for(j=i+1; j<size-1-i; j++){
      if(*(arr+j) < *(arr+min)){
        min = j;
      }
    }
    swap(arr+min, arr+i);

  }
}

void merge(int arr[], int low, int mid, int high){
  int i = 0;
  int j = 0;
  int k = low;

  int n1, n2;

  n1 = mid-low+1;
  n2 = high-mid;

  int a1[n1];
  int a2[n2];

  for(i=0; i<n1; i++){
    a1[i] = arr[low+i];
  }

  for(j=0; j<n2; j++){
    a2[j] = arr[mid+1+j];
  }

  i=0; j=0;

  while(i<n1 && j<n2){
    if(a1[i] <= a2[j]){
      arr[k] = a1[i];
      i++;
    }
    else{
      arr[k] = a2[j];
      j++;
    }
    k++;
  }

  while(i<n1){
      arr[k] = a1[i];
      i++;
      k++;
    }

  while(j<n2){
      arr[k] = a2[j];
      j++;
      k++;
    }

  return;
}

void mergeSort(int arr[], int low, int high){
  if(low < high){
    int mid = low + (high-low)/2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
  }
}

int partition(int arr[], int low, int high){
  int pivot = arr[high];
  int j = low -1;
  int i = 0;

  for(int i=low; i<=high-1; i++){

    if(arr[i] <= pivot){
      j++;
      swap(&arr[j], &arr[i]);
    }
  }
  swap(&arr[high], &arr[j+1]);
  return j+1;
}

void quickSort(int arr[], int low, int high){

  if(low<high){
    int part = partition(arr, low, high);

    quickSort(arr, low, part-1);
    quickSort(arr, part+1, high);
  }

}


int main(void){

  int arr[] = {1,-2,13,4,5,-7,8};
  int size = sizeof(arr)/sizeof(arr[0]);

  //selectionSort(arr, size);

  //bubbleSort(arr, size);


  //insertionSort(arr, size);

  //mergeSort(arr, 0, size-1);

  quickSort(arr, 0, size-1);
  int i;
  for(i=0; i<size; i++){
    printf("%d ", arr[i]);
  }

  return 0;
}
