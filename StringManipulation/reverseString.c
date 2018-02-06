#include<stdio.h>

void reverseString(char* str){
  char* temp = str;
  char buffer;
  int count = 0;

  while(*temp != '\0'){
    *temp++;
    count++;
  }

  char* end = temp-1;

  while(str<end){
    buffer = *str;
   *str++ = *end;
    *end-- = buffer;
  }
  str[count] = '\0';

}

int main(){
  char str[] = "irawiT hdurinA";

  reverseString(str);

  printf("The reversed String is : %s\n", str);
}
