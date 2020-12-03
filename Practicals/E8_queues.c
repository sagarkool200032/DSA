#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int front=-1,rear=-1;  // global index pointers

void enqueue(int q[],int x)
{
    if(rear==MAX-1)
        printf("Queue OVERFLOW\n");
    else
    {
       if(front==-1 && rear ==-1)
       {
           front=0;
           rear=0;
       }
       else
           rear++;
        q[rear]=x;
    }
}

int dequeue(int q[])
{
    int x=-1;

    if(front==-1 && rear ==-1)
        printf("Queue UNDERFLOW\n");
    else
    {
        if(front==rear)   //if both pointing to the last element
       {
           x=q[front];
           front=-1;
           rear=-1;
       }
       else
       {
           x=q[front];
           front++;
       }
    }
    return x;
}

void Display(int q[])
{
    if(front==-1 && rear ==-1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Current Queue---->  ");
    for(int i=front;i<=rear;i++)
        printf("%d ",q[i]);
    printf("\n\n");
}

int main()
{
    int arr[MAX];
    int option=1;
    while(option!=0)
    {
        int n;
        printf("1.Enqueue \n2.Dequeue \n3.Exit \nEnter Option: ");
        scanf("%d",&option);
            if(option==1)
            {
                printf("Enter Element you want to Enqueu: ");
                scanf("%d",&n);
                enqueue(arr,n);
            }       
            else if(option==2)
                printf("%d Deleted from queue: ",dequeue(arr));
            else
                option=0;
            Display(arr);
    }   
}
