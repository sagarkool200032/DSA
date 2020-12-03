#include <stdio.h>
#include <stdlib.h>

int LinearSearch(int * arr,int n,int key)
{
    for(int i=0;i<n;i++)
    {
        if(key==arr[i])
            return i;
    }
    printf("Element Not Found");
    return 0;
}

int main()
{
    int n, * arr, key;
    printf("Enter Size of Array: ");
    scanf("%d",&n);
    arr = (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Enter Key: ");
    scanf("%d",&key);
    if(LinearSearch(arr,n,key))
        printf("Element found at %d position\n",LinearSearch(arr,n,key));
}   