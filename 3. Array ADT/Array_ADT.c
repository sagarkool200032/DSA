#include <stdio.h>
#include <stdlib.h>

struct Array{
    int *A;
    int size;
    int length;
  };

void Display(struct Array arr)
{
  printf("\nElements are:\n");
  for(int i=0;i<arr.length;i++)
    printf("%d ",arr.A[i]);
}

int main()
{
  struct Array arr;
  int i,n;
  printf("Enter size of an array: ");
  scanf("%d",&arr.size);
  arr.A = (int *)malloc(arr.size*sizeof(int));
  printf("Enter No. Of elements: ");
  scanf("%d",&n);
  printf("Enter all elements: \n");
  for(i=0;i<n;i++)
    scanf("%d",&arr.A[i]);
  arr.length = n;

  Display(arr);
  return 0;
}
