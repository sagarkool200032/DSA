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

// finding duplicate elements in sorted arry 
// Time Complexity: O(n)
 int FindDuplicate(struct Array arr)
 {
   int lastDuplicate=0;
   for(int i=0;i<arr.length-1;i++)
   {
     if((arr.A[i]==arr.A[i+1]) && (arr.A[i]!=lastDuplicate))
     {
       printf("Duplicate Elements in arr1: %d\n",arr.A[i]);
       lastDuplicate = arr.A[i];
     }   
   }
 }

// finding duplicate elements in sorted arry and it's occurences
// Time Complexity: O(n) while loop is negligible
int FindDuplicate1(struct Array arr)
 {
   for(int i=0;i<arr.length-1;i++)
   {
     if(arr.A[i]==arr.A[i+1])
     {
       int j=i+1;
       while(arr.A[i]==arr.A[j])
        j++;
       printf("%d is appearing %d times in arr2\n",arr.A[i],j-i);
       i=j-1;
     }   
   }
 }

// (Fastest Method but consumes space)
// finding multiple duplicate elements in unsorted/sorted array starting 
// Time Complexity: O(n) (Using Hash Table/BitSet) 
 int FindDuplicate2(struct Array arr)
 {
   int l,h,n;
   l = min(arr);  // if array is sorted min is 1st element of array
   h = max(arr);  // if array is sorted max is last element of array
   n = arr.length;
   int *H = (int *)malloc((h+1)*sizeof(int));
   //intialise B array with 0
   for(int i=0; i<=h;i++)
    H[i] = 0;
  
  for(int i=0; i<n;i++)
    H[arr.A[i]]++;
    
  //print duplicate elements
  for(int i=0;i<=h;i++)
    if(H[i]>1)   
      printf("%d is appearing %d times in arr3\n",i,H[i]);
 }

// finding multiple duplicate elements in unsorted array 
// Time Complexity: O(n^2)  
 int FindDuplicate3(struct Array arr)
 {
   for(int i=0; i<arr.length-1; i++)
   {
     int count = 1;
     if(arr.A[i]!=-1)
     {
       for(int j=i+1; j<arr.length; j++)
       {
         if(arr.A[i]==arr.A[j])
         {
           count++;
           arr.A[j] = -1;
         }
       }
       if(count>1)
        printf("%d is appearing %d times in arr4\n",arr.A[i],count);
     }
   }
 }

int main()
{
  struct Array arr1={{1,2,2,3,4,5,5,10,10,10,20,21,22,22},20,14};
  struct Array arr2= {{0,0,1,3,3,3},20,6};
  struct Array arr3= {{10,5,5,35,35,35,1,5,9,10,35},20,11};
  struct Array arr4= {{8,3,6,4,6,5,6,8,2,7},20,10};
  FindDuplicate(arr1);
  printf("\n\n");
  FindDuplicate1(arr2);
  printf("\n\n");
  FindDuplicate2(arr3);
  printf("\n\n");
  FindDuplicate3(arr4);
  printf("\n\n");
  return 0;
}