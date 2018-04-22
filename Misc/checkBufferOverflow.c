#include <stdio.h>
#include <time.h>
int main() {
  short int i;

  for(i=0; i<32768; i+=1000){
    usleep(100);
    printf("%d\n", i);
  }
  printf("%d", i);
  return 0;
}
