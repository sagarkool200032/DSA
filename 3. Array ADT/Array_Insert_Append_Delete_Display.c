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

 // time comlexity : O(n^0)= O(1)
 void Append(struct Array *arr,int x)
 {
    if(arr->length < arr->size) // to check space
    arr->A[arr->length++] = x;
 }

 // time comlexity : best case - O(1) , worst case - O(n)
 void Insert(struct Array *arr,int index,int x)
 {
    int i;

    if(index>=0 && index <= arr->length) // to check valid index
    {
      for(i=arr->length;i>index;i--)   // shifting right
        arr->A[i] = arr->A[i-1];

      arr->A[index] = x;
      arr->length++;
    }
 }

// time comlexity : best case - 0 , worst case - O(n)
 int Delete(struct Array *arr,int index)
{
  int x=0;
  int i;
  if(index>=0 && index<arr->length)
  {
    x=arr->A[index];
    for(i=index;i<arr->length-1;i++)  // shifting left
      arr->A[i]=arr->A[i+1];
    arr->length--;
    return x;
 }
 return 0;
}

int main()
{
struct Array arr1={{2,3,4,5,6},10,5};
Append(&arr1,23);
Insert(&arr1,2,12);
printf("%d is deleted",Delete(&arr1,0));
Display(arr1);
 return 0;
}