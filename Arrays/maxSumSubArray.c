#include<stdio.h>
#include<limits.h>

void maxSumSubArray(int* arr, unsigned int size){

  int maxSum = INT_MIN;
  int currSum = 0;
  unsigned int i =0;
  unsigned int start =0;
  unsigned int end = 0;
  unsigned int l = 0;


  for(i=0; i<size; i++){
    currSum += *(arr+i);
    if(maxSum<currSum){
      maxSum=currSum;
      start=l;
      end=i;
    }

    if(currSum<0){
      l = i+1;
      currSum =0;
    }
  }

  printf("%d\n%d\n%d", maxSum, start, end);
}

int main(void){

  int arr[] = {-1,-2,-4,3,4,-12,7,-8,3,12,3, -4};
  unsigned int size = sizeof(arr)/sizeof(arr[0]);

  maxSumSubArray(arr, size);

  return 0;

}
