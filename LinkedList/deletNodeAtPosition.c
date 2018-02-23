#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* next;
};



void printLL(struct Node* node){

  while(node != NULL){
    printf("Data at the node is: %d\n", node->data);

    node = node->next;
  }

  printf("\n\n");

  return;

}


void deletePosition(struct Node** head_ref, int pos){

  struct Node* temp = *head_ref;
  int key = 0;
  struct Node* prev;

  if(temp!=NULL && pos==0){
    *head_ref = temp->next;
    free(temp);
    return;
  }

  while(temp!=NULL && key!=pos){
    prev = temp;
    temp = temp->next;
    key++;
  }

  if(temp==NULL){
    printf("Node does not exits\n");
    return;
  }
  else{
    prev->next = temp->next;
    free(temp);
  }

  return;
}


void deleteNode(struct Node** head_ref, int del_data) {

  struct Node * temp = *head_ref;
  struct Node * prev;


  if(temp!=NULL && temp->data==del_data){
    *head_ref = temp->next;
    free(temp);
    return;
  }

  while(temp!=NULL && temp->data != del_data ){
    prev = temp;
    temp = temp->next;
  }

  if(temp == NULL){
    printf("Data to be deleted not in the Linked List \n");
    return;

  }

  else{
    prev->next = temp->next;
    free(temp);
  }
  return;
}


void append(struct Node* head_ref, int new_data){

  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node*));

  struct Node* last = head_ref;

  new_node->data = new_data;
  new_node->next = NULL;

  while(last->next != NULL){
    last = last->next;
  }
  last->next = new_node;

  return;
}



void addAfter(struct Node* prev, int new_data){

  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node*));\

 // printf("%x\n", prev);

  new_node->next = prev->next;
  new_node->data = new_data;
  prev->next = new_node;
  return;
}

void push(struct Node ** head, int new_data){

  struct Node * new_head = (struct Node*)malloc(sizeof(struct Node*));


//printf("Address of head in passed node Pointer: %x\n", head);
  new_head->next = *head;
  new_head->data = new_data;
  *head = new_head;

  return;

}

int main(void){

  struct Node* head = (struct Node*)malloc(sizeof(struct Node*));
  struct Node* second= (struct Node*)malloc(sizeof(struct Node*));
  struct Node* third= (struct Node*)malloc(sizeof(struct Node*));

  head->data = 10;
  head->next = second;

//   printf("Address of head node Pointer: %x\n", &head);
//   printf("Address of second node Pointer: %x\n", &second);
//   printf("Address of third node Pointer: %x\n", &third);

  second->data = 100;
  second->next = third;

  third->data = 1000;
  third->next = NULL;

//   printf("Address of head->next: %x\n", (second->next));
//   printf("Value at head->next: %x\n", *(second->next));
//   printf("Address of second: %x\n", third);


  printLL(head);


  push(&head, 10000);
  push(&head, 20000);
  push(&head, 30000);

  printLL(head);

  addAfter(head->next, 10240);
//  printf("%x\n", head->next);

  addAfter(second->next, 111123);
  addAfter(third->next, 11223322);

  printLL(head);

  append(head, 988987);

  printLL(head);

  deleteNode(&head, 1000);
  deleteNode(&head, 553436463);
 // deleteNode(&head, 20000);


  deletePosition(&head, -1);

  printLL(head);




  return 0;
}
