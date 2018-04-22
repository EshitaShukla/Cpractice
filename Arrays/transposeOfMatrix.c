#include <stdio.h>
#include<stdlib.h>

void transpose(unsigned int* src, unsigned int* dst, unsigned int m, unsigned int n){
  unsigned int i,j;
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      *(dst+ m*j + i) = *(src+ i*n + j);
    }
  }
}

void printI(unsigned int* image, unsigned int m, unsigned int n){
  unsigned int i, j;
  for(i=0; i<m;i++){
    for(j=0; j<n; j++){
      printf("%d\t", *(image+i*n+j));
    }
    printf("\n");
  }
  printf("\n\n\n");
}



int main(void)
{

    // declarations
    unsigned int image[][4] = {{1,3,5,7},
                               {2,4,6,8},
                               {11,12,13,14}};
    unsigned int *pSource;
    unsigned int m, n;

    // setting initial values
    // and memory allocation
    m = 3, n = 4;
  pSource = (unsigned int*) image;

  unsigned int* dest = (unsigned int*) malloc(sizeof(unsigned int)*m*n);


  printI(pSource, m, n);

  transpose(pSource, dest, m , n);

  printI(dest, n, m);

}
