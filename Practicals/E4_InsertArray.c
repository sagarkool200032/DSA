#include <stdio.h>

int Display(int * arr, int n)
{
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

void Insert(int * arr, int * n, int index, int x)
 {
    int i;

    if(index>=0 && index <= *n) // to check valid index
    {
      for(i=*n+1;i>index;i--)   // shifting right
        arr[i] = arr[i-1];
      arr[index] = x;
      *n+=1;
    }
    else
        printf("Not Possible !\n");
 }

int main()
{
    int n, arr[100],index,value;
    printf("Enter Size of Array: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    printf("Enter Index and Value: ");
    scanf("%d %d",&index,&value);
    Insert(arr,&n,index,value);
    Display(arr,n); 
}   





