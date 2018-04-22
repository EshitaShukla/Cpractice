#include<stdio.h>
#include<pthread.h>

void* printHi(void* i){
  int* my_id = (int*)i;
  printf("In function thread: %d\n", *my_id);

  return NULL;
}

int main(void){

  pthread_t pid;

  printf("In main: Pthread Code\n");
  int i; int rc;
  for(i=0; i<4; i++){
    rc = pthread_create(&pid, NULL, printHi, (void*)i);
  }

  pthread_exit(NULL);

  return 0;
}
