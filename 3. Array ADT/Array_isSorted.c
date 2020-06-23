#include<stdio.h>
#include<stdlib.h>

struct Array
{
  int A[10];
  int size;
  int length;
};

 void Display(struct Array arr)
 {
  int i;
  printf("\nElements are\n");
  for(i=0;i<arr.length;i++)
    printf("%d ",arr.A[i]);
 }

 void swap(int *x,int *y)
 {
  int temp=*x;
  *x=*y;
  *y=temp;
 }

int isSorted(struct Array arr)
{
  int i;
  for(i=0;i<arr.length-1;i++)
  {
    if(arr.A[i]>arr.A[i+1])
    return 0;
  }
  return 1;
}

void InsertSorted(struct Array *arr ,int value)
{
  if(!(arr->length==arr->size))
  {
    int i=arr->length-1;
    while(i>=0 && arr->A[i] > value)
    {
      arr->A[i+1] = arr->A[i--];
    }
    arr->A[i+1] = value;
    arr->length++;
  }
}
// negative elements left side and posititve elements to right side
// Time Complexity: O(n)
void NtoP(struct Array *arr)
{
  int i = 0;
  int j = arr->length-1;
  while(i<j)
  {
    while(arr->A[i]<0){i++;}
    while(arr->A[j]>=0){j--;}
    if(i<j)
      swap(&arr->A[i],&arr->A[j]);
  }
}

int main()
{
  struct Array arr1={{2,3,9,16,18,21,28,32,35},10,9};
  struct Array arr2={{1,2,-5,-8,0,5,-8,9,9,-11},10,10};
  printf("%d",isSorted(arr1));
  InsertSorted(&arr1 ,100);
  Display(arr1);
  NtoP(&arr2);
  Display(arr2);
  return 0;
}