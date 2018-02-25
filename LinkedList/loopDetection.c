#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node* next;
};


void detectLoop(struct Node**head_ref){

  struct Node *fast, *slow;
  fast = *head_ref;
  slow = *head_ref;

  while(fast !=NULL && slow!=NULL && fast->next!=NULL){ //The third condition
    fast = fast->next->next;
    slow = slow->next;

    if(fast == slow){
      printf("Loop Detected\n");
      return;

    }
  }
  return;
}

void printLL(struct Node* head_ref){

  int node = 0;
  while(head_ref != NULL){

    printf("The data at %d node is %d\n", node, head_ref->data);
    node++;
    head_ref = head_ref->next;
  }
  return;
}

void push(struct Node** head_ref, int node_data){

  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node*));
  new_node->data = node_data;
  new_node->next = *head_ref;
  *head_ref = new_node;

  return;
}

int main(void){

  struct Node* head = (struct Node*) malloc(sizeof(struct Node*));
  head->data = 11;
  head->next = NULL;

  push(&head, 2112);
  push(&head, 23);
  push(&head, 786);
  push(&head, 4534);
  push(&head, 2);
  push(&head, 21523);

 // head->next->next->next->next->next = head->next->next;

  detectLoop(&head);
  printLL(head);



  return 0;
}
