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

 int sum(struct Array arr)
 {
   int sum=0;
   for(int i=0;i<arr.length;i++)
    sum+=arr.A[i];
   return sum;
 }

 int max(struct Array arr)
 {
   int maxx = arr.A[0];
   for(int i=0;i < arr.length; i++)
   {
     if(arr.A[i]>maxx)
      maxx = arr.A[i];
   }
   return maxx;
 }

 int min(struct Array arr)
 {
   int minn = arr.A[0];
   for(int i=0;i < arr.length; i++)
   {
     if(arr.A[i]<minn)
      minn = arr.A[i];
   }
   return minn;
 }

// finding single missing element in sorted arry starting from 1 to n natural numbers
 int FindMissing(struct Array arr)
 {
   int summ = sum(arr);
   int n = arr.A[arr.length-1];
   int s = (n*(n+1))/2;
   return s-summ;
 }

// finding single missing element in sorted arry starting from low to high natural numbers
// Time Complexity: O(n)
 int FindMissing1(struct Array arr)
 {
   int l,h,d,n;
   l=arr.A[0];
   h = arr.A[arr.length-1];
   d = l-0;
   n = arr.length;
   for(int i=0; i<n ; i++)
   {
     if(arr.A[i]-i != d)
      return i+d;
   }
 }

// finding multiple missing elements in sorted arry starting from low to high natural numbers
// Time Complexity: O(n) (while loop is negligible)
 int FindMissing2(struct Array arr)
 {
   int l,h,d,n;
   l=arr.A[0];
   h = arr.A[arr.length-1];
   d = l-0; // current difference
   n = arr.length;
   for(int i=0; i<n ; i++)
   {
     if(arr.A[i]-i != d)
     {
       while(d < arr.A[i]-i)
        printf("Missing Element in array3: %d\n",i+d++);
     }  
   }
 }

// (Fastest Method but consumes memory)
// finding multiple missing elements in unsorted array
// Time Complexity: O(n) (Using Hash Table/BitSet) 
 int FindMissing3(struct Array arr)
 {
   int l,h,n;
   l = min(arr);
   h = max(arr);
   n = arr.length;
   int *B = (int *)malloc((h+1)*sizeof(int));
   //intialise B array with 0
   for(int i=0; i<=h;i++)
    B[i] = 0;
  // add 1 in index postion of number present in arr A
  for(int i=0; i<n;i++)
    B[arr.A[i]]++;
  //print missing elements
  for(int i=l;i<=h;i++)
    if(B[i]==0)  
      printf("Missing Elements in array4: %d\n",i);
 }

int main()
{
  struct Array arr1={{1,2,3,4,5,6,8,9,10},10,9};
  printf("Missing Element in array1 : %d\n\n",FindMissing(arr1));
  
  struct Array arr2={{4,5,6,7,8,10},10,6};
  printf("Missing Element in array2 : %d\n\n\n",FindMissing1(arr2));

  struct Array arr3={{5,6,7,8,10,12,13,18,19,20},10,10};
  FindMissing2(arr3);
  printf("\n\n");

  struct Array arr4={{3,7,8,12,15,2,11,18,20,13},10,10};
  FindMissing3(arr4);
 return 0;
}