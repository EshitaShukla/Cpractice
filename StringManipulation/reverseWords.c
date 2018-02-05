#include<stdio.h>

void reverseString(char* start, char* end){
  char temp;
  while(start<end){
    temp = *start;
    *start++ = *end;
    *end-- = temp;
  }
}

void reverseWord(char* start){
  char* temp = start;
  char* head = start;

  while(*temp){
    temp++;
    if(*temp == '\0'){
      reverseString(head, temp-1);
    }
    else if(*temp == ' '){
      reverseString(head, temp-1);
      head = temp+1;
    }
  }

  reverseString(start, temp-1);
}
int main(){
  char str[] = "My name is Anirudh Tiwari";

  printf("Original String: %s\n", str );

  reverseWord(str);

  printf("Reversed by Word String: %s\n", str );

  return 0;
}
