#include<stdio.h>
#include<stdlib.h>

void my_memmove(char* src, char* dst, int len){
  int  i = 0;
  if(src==dst){
    printf("Source and Destination Addresses are same\n");
  }

  else if(src>dst || dst>(src+len-1) ){
    for(i=0; i<len; i++){
      *(dst+i) = *(src+i);
    }
  }

  else if(src<dst && dst<(src+len-1)){
    for(i=len; i>=0; i--){
      *(dst+len) = *(src+len);
    }
  }
}

int main(void){

  char src[] = "Destination";
  char dst[] = "Source";

  my_memmove(src, dst, 11);

  printf("%s", dst);

  return 0;
}
