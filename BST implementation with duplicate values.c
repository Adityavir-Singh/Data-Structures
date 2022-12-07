#include<stdio.h>
#include<stdlib.h>
 
struct node
{
    int data;
    int count;
    struct node *left, *right;
};

struct node *newNode(int item)                           //function to add value to the new node of a BST
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    temp->count = 1;
    return temp;
}

void printBST(struct node *root)                    //function to print the BST 
{
    if (root != NULL)
    {
        printBST(root->left);
        printf("%d(%d) ", root->data, root->count);
        printBST(root->right);
    }
}

struct node* insert(struct node* node, int data)       //function to add a new node in the BST 
{
    if (node == NULL) 
    return newNode(data);
 
    if (data == node->data)
    {
       (node->count)++;
        return node;
    }
 
    if (data < node->data)
        node->left  = insert(node->left, data);
    else
        node->right = insert(node->right, data);
 
    return node;
}

int main()
{
    struct node *root = NULL;                           //initializing the root to NULL
    root = insert(root, 1);
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 6);
 
    printf("The traversed tree is : \n");
    printBST(root);                                    //calling the function printBST
  
    return 0;
}
