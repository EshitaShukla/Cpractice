#include <stdio.h>
#include <stdlib.h>
#define NUM_OF_CHARACTERS 256


char removeDuplicates(char* str){
  int* hash = (int*) calloc(NUM_OF_CHARACTERS, sizeof(int));
   printf("%s\n", str);
  int i;
  char max_ind=-1;
  char rslt;
  int ri = 0;
  for(i=0; *(str+i); i++){
    hash[*(str+i)]++;
    if(max_ind < hash[*(str+i)]){
      max_ind = hash[*(str+i)];
      rslt = *(str+i);
    }
  }

  return rslt;
}

int main(void){

  char str[] = "AAAAAAAAAAnniirrrruuuuuuudhhhhhhh";
  printf("%s\n\n", str);
  char a = removeDuplicates(str);
  printf("Max: %c\n\n", a);
  return 0;
}
