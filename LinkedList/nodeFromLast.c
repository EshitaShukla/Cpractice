#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node* next;
};


void nodeFromLast(struct Node** head_ref, int node){

  struct Node *curr, *ref;
  curr = *head_ref;
  ref = *head_ref;
  int n = 0;

  while(n<node){
    ref = ref->next;
    n++;
  }

  while(ref!=NULL){ //Note the Condition, there is an extra loop for getting that node
                    // If done ref->next != NULL you'll be 1 short of the node
    curr = curr->next;
    ref = ref->next;
  }

  printf("The data at %dth node from end is: %d\n", node, curr->data);
  return;
}

void printLL(struct Node* head_ref){
  while(head_ref != NULL){
    printf("Data at the Node is: %d\n", head_ref->data);
    head_ref=head_ref->next;
  }
  return;
}

void push(struct Node** head_ref, int data){
  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node*));
  new_node->next = *head_ref;
  *head_ref = new_node;
  new_node->data = data;

  return;
}


int main(void){

  struct Node *head = (struct Node*)malloc(sizeof(struct Node*));
  head->data = 36;
  head->next = NULL;

  push(&head, 43);
  push(&head, 22);
  push(&head, 34);
  push(&head, 54);
  push(&head, 46);
  push(&head, 31);
  push(&head, 79);

  nodeFromLast(&head, 4);
  printLL(head);



  return 0;
}
