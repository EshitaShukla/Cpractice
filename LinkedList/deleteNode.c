#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node* next;
};

void deleteNode(struct Node** head_ref, int node_pos ){
  struct Node* temp_node = *head_ref;

  if(*head_ref == NULL){
    printf("Empty Linked List\n");
    return;
  }
  if(node_pos == 0){
    (*head_ref) = temp_node->next;
    free(temp_node);

    return;
  }

  for(int i = 0; i<node_pos-1 && temp_node!=NULL; i++){
    temp_node = temp_node->next;
  }
  if(temp_node==NULL || temp_node->next==NULL){
    return;
  }

  struct Node* next = temp_node->next->next;
  free(temp_node->next);

  temp_node->next = next;

}

void push(struct Node** head_ref, int new_data){
  struct Node* new_head = (struct Node*) malloc(sizeof(struct Node*));

  new_head->data = new_data;

  new_head->next = (*head_ref);

  (*head_ref) = new_head;
}

void addAfter(struct Node* prev_node, int new_data){
  if(prev_node == NULL){
    printf("The given node cannot be NULL \n");
    return;
  }
  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node*));
  new_node->data = new_data;
  new_node->next = prev_node->next;
  prev_node->next = new_node;
  return;
}

void append(struct Node** head_ref, int new_data){

  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node*));
  struct Node* last = *head_ref;

  new_node->data = new_data;
  new_node->next = NULL;

  if(*head_ref == NULL){
    *head_ref = new_node;
    return;
  }

  while(last->next != NULL){
    last = last->next;
  }

  last->next = new_node;
  return;
}

void printList(struct Node* node ){
  while(node->next != NULL){
    printf("The data at Node is %d\n", node->data);
    node = node->next;
  }
}
int main(){

  struct Node* head = NULL;

  append(&head, 2);
  append(&head, 4);
  append(&head, 8);
  append(&head, 16);

  push(&head, 7);

  append(&head, 32);

  push(&head, 99);

  addAfter(head->next->next, 9);

  printList(head);

  deleteNode(&head, 4);
  printf("The Linked List after deleting the node: \n");
  printList(head);


  return 0;
}
