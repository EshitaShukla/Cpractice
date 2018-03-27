#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct Node{
  int data;
  struct Node* left;
  struct Node* right;
};


struct Node* newNode(int data){
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
}

struct Node* insert(struct Node* root, int data){
  if(root == NULL) return newNode(data);

  if(data < root->data){
    root->left = insert(root->left, data);
  }

  else if(data > root->data){
    root->right = insert(root->right, data);
  }

  else exit(0);

  return root;
}

void inorder(struct Node* root){
  //Left->root->right
  if(root != NULL) {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
  return;
}

int search(struct Node* root, int data){
  if(root == NULL || root->data == data) return root->data;

  else if (data > root->data) return search(root->right, data);

  else if (data < root->data) return search(root->left, data);

  else return INT_MIN;
}

int main(void){

  struct Node* root = NULL;

  root = insert(root, 50);
  insert(root, 20);
  insert(root, 80);
  insert(root, 30);
  insert(root, 40);
  insert(root, 70);

  inorder(root);

  int data = search(root, 200);
  printf("\nSearched data: %d\n", data);
  return 0;
}
