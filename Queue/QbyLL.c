#include<stdio.h>
#include<stdlib.h>


struct QNode{
  int data;
  struct QNode* next;
};

struct QNode* front = (struct QNode*) malloc(sizeof(struct QNode));
struct QNode* end = (struct QNode*) malloc(sizeof(struct QNode));


struct QNode* newNode(int data){
  struct QNode* newNode = (struct QNode*) malloc(sizeof(struct QNode));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}


void enqueue(struct QNode** head, int data){

  struct QNode* node = newNode(data);
  if(*head == NULL){
    *head = front = end = node;
  }

  else{
    end->next = node;
    end = node;
  }

  printf("%d ", data);
  return;
}

void dequeue(struct QNode** head){

  struct QNode* temp = front;

  if(front == NULL) return;

  if(front == end){
    front == end == NULL;
  }

  else{
    *head = front->next;
    front = *head;
  }

  int deq = front->data;
  printf("\nDequeue'd data: %d \n", deq);

  free(temp);
  return;
}


int main(void){

  struct QNode* q = NULL;

  enqueue(&q, 11);
  enqueue(&q, 101);
  enqueue(&q, 22);
  enqueue(&q, 202);

  dequeue(&q);
  dequeue(&q);
  dequeue(&q);
  dequeue(&q);

  printf("\nEnd Node Data: %d \n", end->data);
  printf("\nFront Node Data: %d \n", front->data);

  return 0;
}
