#include <stdio.h>
#include <stdlib.h>

int AddnMul(int * arr,int n)
{
    int sum =0;
    int multiplication = 1;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        multiplication*=arr[i];
    }
    printf("Sum: %d\nMultiplication:%d",sum,multiplication);
}

int main()
{
    int n;
    int * arr;
    printf("Enter Size of Array: ");
    scanf("%d",&n);
    arr = (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    AddnMul(arr,n);
}   





