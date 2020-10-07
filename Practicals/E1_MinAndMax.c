#include <stdio.h>
#include <stdlib.h>

void MinnMax(int * arr, int n)
{
  int min = arr[0];
  int max = arr[0];
  for(int i=0; i<n; i++)
  {
    if(arr[i]<min){min = arr[i];}
    else if(arr[i]>max){max = arr[i];}
  }
  printf("max:%d \nmin:%d",max,min);
}

int main()
{
    int n,* arr;
    printf("Enter Size of Array: ");
    scanf("%d",&n);
    arr = (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    MinnMax(arr,n);
}





