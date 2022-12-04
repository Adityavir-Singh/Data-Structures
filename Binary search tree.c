#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *left, *right;
};

struct node *newNode(int item) 
{
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

void inorder(struct node *root) 
{
  if (root != NULL) 
  {
    inorder(root->left);
    printf("%d -> ", root->key);
    inorder(root->right);
  }
}

struct node *insert(struct node *node, int key) 
{
  if (node == NULL) 
  return newNode(key);
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

struct node *minValueNode(struct node *node) 
{
  struct node *current = node;

  while (current && current->left != NULL)
    current = current->left;

  return current;
}

int main() {
  struct node *root = NULL;
  root = insert(root, 8);
  root = insert(root, 7);
  root = insert(root, 6);
  root = insert(root, 5);
  root = insert(root, 4);
  root = insert(root, 3);
  root = insert(root, 2);
  root = insert(root, 1);

  printf("Inorder traversal: ");
  inorder(root);
}