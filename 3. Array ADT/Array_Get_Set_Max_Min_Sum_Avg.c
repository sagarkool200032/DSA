#include<stdio.h>

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

int Get(struct Array arr,int index)
{
  if(index>=0 && index<arr.length)
    return arr.A[index];
  return -1;
}

void Set(struct Array *arr,int index,int x)
{
  if(index>=0 && index<arr->length)
    arr->A[index]=x;
}
int Max(struct Array arr)
{
  int max=arr.A[0];
  int i;
  for(i=1;i<arr.length;i++)
  {
    if(arr.A[i]>max)
      max=arr.A[i];
  }
  return max;
}

int Min(struct Array arr)
{
  int min=arr.A[0];
  int i;
  for(i=1;i<arr.length;i++)
  {
    if(arr.A[i]<min)
    min=arr.A[i];
  }
  return min;
}
// Find Min and Max in array in 1 scan
// Time Complexity: O(n)
void MinnMax(struct Array arr)
{
  int min = arr.A[0];
  int max = arr.A[0];
  for(int i=1; i<arr.length; i++)
  {
    if(arr.A[i]<min){min = arr.A[i];}
    else if(arr.A[i]>max){max = arr.A[i];}
  }
  printf("max:%d \nmin:%d",max,min);
}

int Sum(struct Array arr)
{
  int s=0;
  int i;
  for(i=0;i<arr.length;i++)
    s+=arr.A[i];
  return s;
}

float Avg(struct Array arr)
{
  return (float)Sum(arr)/arr.length;
}
int main()
{
 struct Array arr1={{2,3,9,16,18,21,28,32,35},10,9};
 printf("Sum: %d\n",Sum(arr1));
 printf("Average: %.2f\n",Avg(arr1));
 printf("Get: %d\n",Get(arr1,2));
 printf("Max: %d\n",Max(arr1));
 printf("Min: %d\n",Min(arr1));
 Display(arr1);
 printf("\n\n");
 MinnMax(arr1);
 return 0;
}