#include <stdio.h>
#include <stdlib.h>
#define NUM_OF_CHARACTERS 256

int* getMaskHash(char* m){
  int* hash = (int*) calloc(NUM_OF_CHARACTERS, sizeof(int));
  int i;
  for(i=0; *(m+i); i++){
    hash[*(m+i)]++;
  }

  return hash;
}

void removeMask(char* str, char* m){

  int* hash = getMaskHash(m);

  int i;
  int ri=0;

  for(i=0; *(str+i); i++){
    if(hash[*(str+i)] < 1){
      *(str+ri) = *(str+i) ;
      ri++;
    }
  }

  *(str+ri) ='\0';

  free(hash);

}

int main(void){

  char str[] = "Anmirudsh Tiwaookroi";
  char m[] = "mosk";

  printf("String: %s Mask: %s\n\n", str, m);
  removeMask(str, m);
  printf("String: %s\n\n", str);
  return 0;
}
