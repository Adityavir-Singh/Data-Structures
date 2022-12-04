#include<stdio.h>
int main()
{
    int arr[100], n, i, j,pos, temp;
    printf("Enter number of elements : ");
    scanf("%d" , &n);
    printf("Enter %d numbers : " , n);
    for(i = 0; i <n; i++)
    scanf("%d" , &arr[i]);
    for(i = 0; i < n-1; i++)
    {
        pos = i;
        for(int j = i+1; j < n; j++)
        {
            if(arr[pos] > arr[j])
            pos = j;
        }
        if(pos != i)
        {
            temp = arr[i];
            arr[i] = arr[pos];
            arr[pos] = temp;
        }
    }
    printf("sorted array : ");
    for(i = 0; i < n; i++)
    printf("%d ", arr[i]);
    return 0;
}