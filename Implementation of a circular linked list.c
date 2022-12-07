#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct node *last = NULL;
struct node *head =NULL;

void insertatbeg(int d)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter value : ");  
    scanf("%d",&d);

	if (last == NULL) {
		temp->data = d;
		temp->next = temp;
		last = temp;
	}

	else {
		temp->data = d;
		temp->next = last->next;
		last->next = temp;
	}
    printf("\nnode inserted\n");
}

void insertatend(int d)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter value : ");  
    scanf("%d",&d);

	if (last == NULL) {
		temp->data = d;
		temp->next = temp;
		last = temp;
	}

	else {
		temp->data = d;
		temp->next = last->next;
		last->next = temp;
		last = temp;
	}
    printf("\nnode inserted\n");
}

void insertafter()
{
	int d, value;

	struct node *temp, *n;

    printf("Enter number after which you want to enter number: ");
	scanf("%d", &value);
	temp = last->next;

	do 
    {
		if (temp->data == value) 
        {
			n = (struct node*)malloc(sizeof(struct node));

			printf("Enter data to be inserted : ");
			scanf("%d", &d);
			n->data = d;
			n->next = temp->next;
			temp->next = n;

			if (temp == last)
				last = n;
			break;
		}
		else
			temp = temp->next;
	} while (temp != last->next);
    printf("\nnode inserted\n");
}

void deletefirst()
{
	struct node* temp;

	if (last == NULL)
		printf("\nList is empty.\n");

	else {
		temp = last->next;
		last->next = temp->next;
		free(temp);
	}
    printf("\nnode deleted\n");
}

void deletelast()
{
	struct node* temp;

	if (last == NULL)
		printf("\nList is empty.\n");

	temp = last->next;

	while (temp->next != last)
		temp = temp->next;
 
	temp->next = last->next;
	last = temp;
    printf("node deleted\n");
}

void deleteatposition()
{
	int pos, i = 1;
	struct node *temp, *position;
	temp = last->next;

	if (last == NULL)
		printf("\nList is empty.\n");

	else {

		printf("\nEnter position : ");
		scanf("%d", &pos);

		while (i <= pos - 1) {
			temp = temp->next;
			i++;
		}

		position = temp->next;
		temp->next = position->next;

		free(position);
	}
    printf("node deleted\n");
}
void displaylist()
{
	if (last == NULL)
		printf("\nList is empty\n");

	else {
		struct node* temp;
		temp = last->next;

		do {
			printf("%d-->", temp->data);
			temp = temp->next;
		} while (temp != last->next);
        printf("NULL");
	}
}

int search(struct node *head , int d)
{
	int index = 0;
    struct node *current = head;
    do 
    {
		if (current == NULL)
			return 0;
		
		if (current->data == d)
			return index;

        current = current->next;
		index++;
    } while (current != head);

    return -1;
}

int main()
{
    int d , choice , n , index;
    while(1)
    {
        printf("\n1. Insert a node in the beginning \n2. Insert a node at the end \n3. Insert a node after a particular node \n4. Delete the first element \n5. Delete the last element \n6. Delete at position \n7. Search for an element \n8. Display list\n");
        printf("Enter your choice : ");
        scanf("%d" , &choice);
        switch(choice)
        {
            case 1:
            insertatbeg(d);
            break;
            case 2:
            insertatend(d);
            break;
            case 3:
            insertafter();
            break;
            case 4:
            deletefirst();
            break;
            case 5:
            deletelast();
            break;
            case 6: 
            deleteatposition();
            break;
			case 7:
			printf("Enter element to search: ");
			scanf("%d", &d);
			index = search(head, d);
            if (index == -1)
				printf("%d not found in list.\n", d);
			else 
                printf("%d found at %d position.\n", d, (index + 1));
			break;
			case 8:
            displaylist();
            break;
            default:
            printf("Enter a valid choice ");
        }
    }
	return 0;
}

