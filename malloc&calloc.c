#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int *ptr1, *ptr2;
    int n, i;

    printf("Enter the no. of elements:");
    scanf("%d",&n);
 
    ptr1 = (int*)malloc(n * sizeof(int));
 
    ptr2 = (int*)calloc(n, sizeof(int));
 
    if (ptr1 == NULL || ptr2 == NULL) 
    {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else 
    {
        printf("Memory successfully allocated using malloc.\n");
        printf("Enter the elements of the array :\n ");
        for(int i = 0; i < n; i++)
        {
            scanf("%d" , &ptr1[i]);
        }
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", ptr1[i]);
        }
 
        free(ptr1);
        printf("\nMalloc Memory successfully freed.\n");
 
        printf("\nMemory successfully allocated using calloc.\n");
        printf("Enter the elements of the array again :\n ");
        for(int i = 0; i < n; i++)
        {
            scanf("%d" , &ptr2[i]);
        }
        printf("The elements of the new array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", ptr2[i]);
        }
 
        free(ptr2);
        printf("\nCalloc Memory successfully freed.\n");
    }
 
    return 0;
}