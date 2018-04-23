#include <stdio.h>
#include <stdlib.h>
#define NUM_OF_CHARACTERS 256


void removeDuplicates(char* str){
  int* hash = (int*) calloc(NUM_OF_CHARACTERS, sizeof(int));

  int i;
  int ri = 0;
  for(i=0; *(str+i); i++){
    hash[*(str+i)]++;

    if(hash[*(str+i)] == 1){
      *(str+ri) = (*(str+i));
      ri++;
    }
  }

  *(str+ri) = '\0';

  printf("%s\n", str);


}

int main(void){

  char str[] = "Anniirrrruuuuuuudhhhhh";
  printf("%s\n\n", str);
  removeDuplicates(str);
  return 0;
}
