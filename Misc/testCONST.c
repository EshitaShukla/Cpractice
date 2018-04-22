#include <stdio.h>

int main(void){


  const int a = 43;

  int* p = (int*)&a;
  *p = 73;

  printf("%d", a);
  return 0;
}
