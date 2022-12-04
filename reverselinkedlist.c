#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
void display(struct node *head)  
{
    if (head == NULL) 
       return; 
   
    display(head->next); 
    printf("%d  ", head->data); 
}

int main()
{
    struct node *prev,*head, *ptr;
    int n,i;
    printf ("Enter size of Linked List: ");
    scanf("%d",&n);
    head=NULL;
    for(i=0;i<n;i++) 
    { 
        ptr=malloc(sizeof(struct node)); 
        printf ("Enter the data: "); 
        scanf("%d",&ptr->data);
        ptr->next=NULL;
        if(head==NULL)
            head=ptr;
        else
            prev->next=ptr;
        prev=ptr;
    }
    display(head);
    return 0;
}