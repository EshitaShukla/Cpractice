#include<stdio.h>
#include <stdlib.h>
#include<limits.h>

struct Node{
  char data;
  struct Node* next;
};

struct Node* newNode(char data){
  struct Node* newN = (struct Node*) malloc(sizeof(struct Node));
  newN->data = data;
  newN->next = NULL;
  return newN;
}

int compare(struct Node* a, struct Node* b){
  printf("%d, %d", a->data, b->data);
  while(a!=NULL && b!=NULL){
    if(a->data == b->data){
      a = a->next;
      b = b->next;
    }

    else return INT_MIN;
  }

  if(a != NULL) return -1;
  else if(b != NULL) return 1;
  else return 0;

}


int main()
{
    struct Node *list1 = newNode('g');
    list1->next = newNode('e');
    list1->next->next = newNode('e');
    list1->next->next->next = newNode('k');
    list1->next->next->next->next = newNode('s');
    list1->next->next->next->next->next = newNode('b');

    struct Node *list2 = newNode('g');
    list2->next = newNode('e');
    list2->next->next = newNode('e');
    list2->next->next->next = newNode('k');
    list2->next->next->next->next = newNode('s');
    list2->next->next->next->next->next = newNode('b');

    printf("%d", compare(list1, list2));

    return 0;
}
