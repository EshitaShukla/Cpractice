#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node* left;
  struct Node* right;
};


void inOrderTraverse(struct Node* root){
  if(root != NULL){
    inOrderTraverse(root->left);
    printf("%d\n", root->data);
    inOrderTraverse(root->right);
  }
}

struct Node* newnode(int data){

  struct Node* newNode = (struct Node*) malloc(sizeof(struct Node*));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

struct Node* insert(struct Node* root, int data){
  if(root == NULL){
    return newnode(data);
  }

  if(data < root->data){
    root->left = insert(root->left, data);
  }
  else if(data > root->data){
    root->right = insert(root->right, data);
  }

  return root;
}

int main(void){

  struct Node* root = NULL;
  root = insert(root, 50);
  insert(root, 60);
  insert(root, 70);
  insert(root, 80);
  insert(root, 20);
  insert(root, 30);
  insert(root, 40);

  inOrderTraverse(root);
  return 0;

}
