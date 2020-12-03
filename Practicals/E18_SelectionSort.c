#include <stdio.h>
#include <stdlib.h>

void swap(int *n1, int *n2) 
{ 
    int temp = *n1; 
    *n1 = *n2; 
    *n2 = temp; 
}

void SelectionSort(int *arr, int n) 
{ 
   for (int i = 0; i < n-1; i++)
   {    int min = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[min]) 
                min = j;
        swap(&arr[min], &arr[i]);   
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
    SelectionSort(arr,n);
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
}