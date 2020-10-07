#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, * arr, key, l,h,mid;;
    printf("Enter Size of Array: ");
    scanf("%d",&n);
    arr = (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Enter Key: ");
    scanf("%d",&key);
    l = 0;
    h = n-1;
    while(l<=h)
    {
        mid = (l+h)/2;
        if(key==arr[mid])
        {
             printf("Element found at %d position\n",mid);
             return 0;
        }
        else if(key<arr[mid])
            h=mid-1;      
        else
            l=mid+1;
    }
    printf("Element Not Found");
    return 0;
}   





