// C program for linked list implementation of stack
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack{
    unsigned capacity;
    int top;
    int *array;
};

int ifFull(struct Stack* stack){
    if(stack->top == stack->capacity-1)
    return 1;

    else return 0;
}

int isEmpty(struct Stack* stack){
    if(stack->top == -1){
        return 1;
    }
    else return 0;
}

int push(struct Stack* stack, unsigned data){
    if(ifFull(stack)){
        return -1;
    }
    stack->array[++stack->top] = data;
    printf("Pushed data to stack: %d\n", stack->array[stack->top]);
    return 1;
}

int pop(struct Stack* stack){
    if(isEmpty(stack)){
        return INT_MIN;
    }
    return stack->array[stack->top--];

}

struct Stack* createStack(unsigned capacity){
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *) malloc((stack->capacity)* sizeof(int));

    return stack;
}

int main(){
    struct Stack* stack = createStack(100);
    push(stack, 10);
    push(stack, 20);

    printf("Removed %d from stack\n", pop(stack)); //Remove one data at a time from the top

    return 0;
}
