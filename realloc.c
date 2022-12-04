#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int* ptr;
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d" , &n);
 
    ptr = (int*)calloc(n, sizeof(int));

    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else 
    {
        printf("Memory successfully allocated using calloc.\n");
        
        n=8;
        printf("\n\nNew size of the array is: %d\n", n);

        ptr = realloc(ptr, n * sizeof(int));

        printf("Memory successfully re-allocated using realloc.\n");
        printf("Enter the elements of the array :\n ");
        for(int i = 0; i < n; i++)
        {
            scanf("%d" , &ptr[i]);
        }
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", ptr[i]);
        }
        free(ptr);
    }
 
    return 0;
}