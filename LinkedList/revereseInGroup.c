#include<stdio.h>
#include<stdlib.h>


struct Node{
  int data;
  struct Node* next;
};

struct Node* newNode(int data){
  struct Node* newN = (struct Node*) malloc(sizeof(struct Node));
  newN->data = data;
  newN->next = NULL;

  return newN;
}

void print(struct Node* head){
  while(head!=NULL){
    printf("%d ", head->data);
    head = head->next;
  }

  printf("\n");
}

void reverse(struct Node** head){

  struct Node *curr, *next, *prev;
  prev = NULL;
  curr = *head;
  next = NULL;

  while(curr){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;

  }

  *head = prev;

  printf("Reversed LL: ");
  print(*(head));
}

struct Node* reverseInGroup(struct Node** head, int key){
  unsigned int n = key;
  struct Node *curr, *next, *prev;
  prev = NULL;
  curr = *head;
  next = NULL;
  while(n && curr!=NULL){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr=next;
    n--;
    //printf("n: %d\n",n);
  }

  if(next){
    (*head)->next = reverseInGroup(&next, key);
  }

  return prev;
  //print(*(head));
}

int main(void){
  struct Node* head = newNode(1);
  head->next = newNode(2);
  head->next->next = newNode(3);
  head->next->next->next = newNode(4);
  head->next->next->next->next = newNode(5);
  head->next->next->next->next->next = newNode(6);
  head->next->next->next->next->next->next = newNode(7);
  head->next->next->next->next->next->next->next = newNode(8);
  head->next->next->next->next->next->next->next->next = newNode(9);
  head->next->next->next->next->next->next->next->next->next = newNode(10);
  head->next->next->next->next->next->next->next->next->next->next = newNode(11);

  print(head);

  //reverse(&head);


  head = reverseInGroup(&head, 8);
  print(head);

  return 0;
}
