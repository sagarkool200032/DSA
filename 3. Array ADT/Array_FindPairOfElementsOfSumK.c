#include<stdio.h>
#include<stdlib.h>

struct Array
{
  int A[20];
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

// finding pair of elements with sum k in unsoreted array
// Time Complexity: O(n^2)
 int Pair(struct Array arr,int k)
 {
   for(int i=0; i<arr.length-1; i++)
   {
     for(int j=i+1; j<arr.length; j++)
     {
         if(arr.A[i]+arr.A[j]==k)
          printf("%d+%d=%d\n",arr.A[i],arr.A[j],k);
     }
    }
 }

// (Fastest Method but consumes space)
// finding pair of elements with sum k in unsoreted array
// Time Complexity: O(n) (Using Hash Table/BitSet) 
 int Pair1(struct Array arr,int k)
 {
   int l,h,n;
   l = min(arr);  // if array is sorted min is 1st element of array
   h = max(arr);  // if array is sorted max is last element of array
   n = arr.length;
   int *H = (int *)malloc((h+1)*sizeof(int));
   //intialise H array with 0
   for(int i=0; i<=h;i++)
    H[i] = 0;

  for(int i=0; i<n;i++)
    {
      if(H[k-arr.A[i]]!=0 && k-arr.A[i]>=0)
      {
        printf("%d+%d=%d\n",arr.A[i],k-arr.A[i],k);
      }
      H[arr.A[i]]++;
    }
 }

// finding pair of elements with sum k in sorted array
// Time Complexity: O(n)
 int Pair2(struct Array arr,int k)
 {
   int i = 0;
   int j = arr.length-1;
   while(i<j)
   {
     if(arr.A[i]+arr.A[j]==k)
     {
       printf("%d+%d=%d\n",arr.A[i++],arr.A[j--],k);
     }
     else if(arr.A[i]+arr.A[j]>k){j--;}
     else {i++;}
   }
 }

int main()
{
  struct Array arr1={{6,3,8,10,16,7,5,2,9,14},20,10};
  struct Array arr2={{1,3,4,5,6,8,9,10,12,14},20,10};

  Pair(arr1,10);
  printf("\n\n");
  Pair1(arr1,10);
  printf("\n\n");
  Pair2(arr2,10);
  return 0;
}