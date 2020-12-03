#include "LL.h"

void DeleteBegining()
{
    struct Node *q=NULL;
    if(start==NULL)
    {
        printf("Linked List is empty");
        return;
    }
    q=start;
    start=start->next;
    free(q);
}

void DeleteEnd(struct Node *p)
{
    struct Node *q=NULL;  // q is tailing pointer
    if(start==NULL)
    {
        printf("Linked List is empty");
        return;
    }
    while(p->next!=NULL)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        free(p);
}  


void Delete(struct Node *p,int index)
{
    struct Node *q=NULL;  // q is tailing pointer
    if(index < 1 || index > count(p))
        return;
    if(index==1)
        DeleteBegining();
    else
    {
        for(int i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        free(p);
    }
}

int main()
{
    int option = 1;
    while(option!=0)
    { 
        printf("1. Delete At Begining\n2. Delete At End\n3. Delete in Between\n4. Insert Data\n5. Exit  \nEnter Option: ");
        scanf("%d",&option);
        if(option==1)
        {
            DeleteBegining();
            display(start);
        }
        else if(option==2)
        {
            DeleteEnd(start);
            display(start);
        }

        else if(option==3)
        {
            int index;
            printf("Index: ");
            scanf("%d",&index);
            Delete(start,index);
            display(start);
        }
        else if(option==4)
        {
            int n;
            printf("Enter Data: ");
            scanf("%d",&n);
            enterData(n);
            display(start);
        }

        else
            option = 0;  
    }
}