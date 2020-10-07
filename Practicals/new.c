#include <stdio.h>
#include <limits.h>

int rMax(int * arr, int n)
{
    static int max=INT_MIN;
    if(n<0)
        return max;
    if(max < arr[n])
        max = arr[n];
    rMax(arr,n-1);
}

int rMin(int * arr, int n)
{
    static int min=INT_MAX;
    if(n<0)
        return min;
    if(min > arr[n])
        min = arr[n];
    rMin(arr,n-1);
}

int main()
{
    int n1,arr1[100];
    printf("Enter Size of Array1: ");
    scanf("%d",&n1);
    for(int i=0;i<n1;i++)
        scanf("%d",&arr1[i]);
    printf("Max: %d\n",rMax(arr1,n1-1));
    printf("Min: %d",rMin(arr1,n1-1));
}
    





