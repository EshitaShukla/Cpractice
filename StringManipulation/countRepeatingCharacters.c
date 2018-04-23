#include <stdio.h>
#include <stdlib.h>
#define NUM_OF_CHARACTERS 256

void getDuplicates(char* str){
  int* count = (int*) calloc(NUM_OF_CHARACTERS, sizeof(int));
  int i;
  for(i=0; *(str+i); i++){
    count[*(str+i)]++;
  }

  for(i=0; i<NUM_OF_CHARACTERS; i++){
    if(*(count+i) > 1){
      printf("Character: %c, Count: %d\n", i, *(count+i));
    }
  }
  return;
}

int main(void){
  char str[] = "Anirudh Tiwari";

  getDuplicates(str);


  return 0;
}
