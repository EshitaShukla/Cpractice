#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node *next;
};

void printlist(struct Node* first){
 while(first != NULL){
   printf("Node Data: %d\n", first->data);
   first = first->next;
 }
}

// void pushNode(struct Node** head_ref, int new_data){

//   struct Node* new_node = NULL;
//   new_node = (struct Node*) malloc(sizeof(struct Node));

//   new_node->data = new_data;
//   new_node->next = (*head_ref);
//   *head_ref = new_node;
// }

// void pushBetweenNode(struct Node* prev_node, int new_data){
//   struct Node* new_node = (struct Node*)(malloc(sizeof(struct Node*)));
//   new_node->data = new_data;
//   new_node->next = prev_node->next;
//   prev_node->next = new_node;
// }

void pushNodeAtEnd(struct Node* previous_node, int new_data){

  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node*));
  new_node->data = new_data;
  new_node->next = NULL;

  previous_node->next = new_node;
}

int main(){
  struct Node* head = NULL;
  struct Node* second = NULL;
  struct Node* third = NULL;

  head = (struct Node*) malloc(sizeof(struct Node));
  second = (struct Node*) malloc(sizeof(struct Node));
  third = (struct Node*) malloc(sizeof(struct Node));

  head->data = 1;
  head->next = second;

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = NULL;

  printlist(head);

  int new_data = 15;

  //pushNode(&head, new_data);
  //pushBetweenNode(second, new_data);
  pushNodeAtEnd(third, new_data);

  printf("New List: \n");

  printlist(head);


  return 0;

}
