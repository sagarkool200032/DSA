#include <stdio.h>
#include <stdlib.h>

void swap(int *n1, int *n2) 
{ 
    int temp = *n1; 
    *n1 = *n2; 
    *n2 = temp; 
}

void bubbleSort(int *arr, int n) 
{ 
   for (int i = 0; i < n-1; i++)
   {
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1]) 
                swap(&arr[j], &arr[j+1]);   
   }         
}

int main()
{
    int n,*arr;
    printf("Enter Total No. of elements: ");
    scanf("%d",&n);
    arr = (int *)malloc(n*(sizeof(int)));
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    bubbleSort(arr,n);
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
}