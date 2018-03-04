#include<stdio.h>
#include<stdlib.h>


struct Stack{
  int top;
  unsigned capacity;
  int* array;
};

int isFull(struct Stack* stack){
  if(stack->top == stack->capacity-1){
    return 1;
  }

  return 0;
}

int isEmpty(struct Stack* stack){
  if(stack->top == -1){
    printf("Empty Stack\n");
    return 1;
  }

  return 0;
}


void pop(struct Stack* stack){
  if(isEmpty(stack)){
    printf("Underflow \n");
    return;
  }
  stack->array[stack->top--];
  if(stack->top > -1)
  printf("The top element now is: %d\n", stack->array[stack->top]);

  else printf("No data on stack\n");
  return;
}

void push(struct Stack* stack, int data){
  if(isFull(stack)){
    printf("Overflow \n");
    return;
  }
  stack->array[++stack->top] = data;

  printf("The data pushed is: %d\n", stack->array[stack->top]);
  return;
}


struct Stack* createStack(unsigned capacity){

  struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack*));
  stack->capacity = capacity;
  stack->top = -1;
  stack->array = (int*) malloc(capacity * sizeof(int));

  return stack;
}

int main(void){

  struct Stack* stack = createStack(100);
  push(stack, 4);
  push(stack, 9);
  //push(stack, 16);

  pop(stack);
  pop(stack);
  return 0;
}
