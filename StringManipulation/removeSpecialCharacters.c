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
// #include<stdio.h>
// #include<stdlib.h>
//
// int main(){
//
//   char str[] = "Q*U*A*L*C*O*M*M";
//   int i =0;
//
//   char * s = str;
//
//   for(i=0; *s!='\0'; i++){
//     if(*s == '*'){
//       s=s+1;
//       str[i] = *s;
//     }
//     s = s+1;
//   }
//
//   str[i] = '\0';
//
//   printf("%s", str);
//
//   return 0;
// }
