#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
}* head = NULL,* last = NULL;

void display(struct Node *p)
{
    printf("current Linked List---->");
    do
    {
        printf("%d ",p->data);
        p = p->next;
    }while(p!=head);
    printf("\n");     
}

int countNodes(struct Node * p)
{
    int count=0;
    do
    {
        count++;
        p = p->next;
    }while(p!=head);
    return count;
}

void enterData(int x)
{
    struct Node * temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head ;
    if(head == NULL)
    {
        head = temp;
        last = temp;
    }
    else
    {
        last->next = temp;
        last = temp;
    }
}
