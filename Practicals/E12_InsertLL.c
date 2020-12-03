#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
}* front = NULL;
typedef struct Node * Node;

void display(Node p)
{
    if(p==NULL)
    {
        printf("Linked List is empty\n");
        return;
    }
    printf("current Linked List---->");
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n\n\n");     
}

int count(struct Node *p)
{
    int count=0;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}

void insertBegining(int x)
{
    Node temp;
    temp = (Node)malloc(sizeof(struct Node));
    if(temp==NULL)
        printf("Linked List is full\n");
    else
    {
        temp->data=x;
        temp->next=front;
        front=temp;
    }
}

void insertEnd(int x)
{
    Node t,p=front;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if(front==NULL)
        front = t;  
    else
    {
        while(p->next!=NULL)
            p = p->next;       //p is pointing to the last node
        p->next = t;
    } 
}

void insertBetween(int x,int index)
{
    Node t,p=front;
    if(index < 0 || index > count(p))
        return;

    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    if(index == 0)
    {
        t->next=front;
        front=t;
    }
    else
    {
        for(int i=0;i<index-1;i++)
            p=p->next;
        t->next=p->next;
        p->next=t;
    }    
}



int main()
{
    int option = 1;
    while(option!=0)
    { 
        printf("1. Insertion At Begining\n2. Insertion At End\n3. Insertion in Between\n4. Exit \nEnter Option: ");
        scanf("%d",&option);
        if(option==1)
        {
            int n;
            printf("Enter Data: ");
            scanf("%d",&n);
            insertBegining(n);
            display(front);
        }
        else if(option==2)
        {
            int n;
            printf("Enter Data: ");
            scanf("%d",&n);
            insertEnd(n);
            display(front);
        }

        else if(option==3)
        {
            int n,index;
            printf("Enter Data and Index: ");
            scanf("%d %d",&n,&index);
            insertBetween(n,index);
            display(front);
        }
        else
        {
            option = 0;  
        }
              
    }
}