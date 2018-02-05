#include<stdio.h>
#include<stdlib.h>

void removeCharacters(char* str){
  int count = 0;
  int i = 0;

  for(i=0; str[i]; i++){
    if(str[i]!='*'){
      str[count++] = str[i];
    }
  }
  str[count] = '\0';
}

int main(){

  char str[] = "*q*u*a*l*c*o*m*m*";
  removeCharacters(str);
  printf("%s", str);
  return 0;
}
