#include <stdio.h>
#include <stdlib.h>


struct Node{
  int data;
  struct Node* left;
  struct Node* right;
};

void inOrderTraverse(struct Node* root){
  if(root != NULL){
    inOrderTraverse(root->left);
    printf("%d ", root->data);
    inOrderTraverse(root->right);
  }
  return;
}

struct Node* newnode(int data){
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
}

struct Node* insert(struct Node* root, int data){
  if(root == NULL) return newnode(data);

  else if(data > root->data){
    root->right = insert(root->right, data);
  }

  else{
    root->left = insert(root->left, data);
  }

  return root;
}


struct Node* minValueNode(struct Node* root){
  struct Node* temp = root;

  if(temp->left != NULL){
    temp = temp->left;
  }

  return temp;
}


struct Node* deleteNode(struct Node* root, int data){
  if(root == NULL) return root;

  if(data < root->data){
      root->left = deleteNode(root->left, data);
  }

  else if(data > root->data){
    root->right = deleteNode(root->right, data);
  }

  else{
    if(root->left == NULL){
      struct Node* temp = root->right;
      free(root);
      return temp;
    }

    else if(root->right == NULL){
      struct Node* temp = root->left;
      free(root);
      return temp;
    }
    else{
      struct Node* temp = minValueNode(root->right);
      root->data = temp->data;
      root->right = deleteNode(root->right, temp->data);
    }
  }

  return root;
}

int main(void){

  struct Node* root = NULL;
  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);

  inOrderTraverse(root); //Left-Root-Right

  deleteNode(root, 70);
  printf("\n\n");
  inOrderTraverse(root); //Left-Root-Right
  return 0;
}
