#include <stdio.h>
#include <stdlib.h>

struct Node{
    int coef,expo;
    struct Node * next;
}* start1 = NULL,* start2 = NULL,* start3 = NULL;

void display(struct Node *p)
{
    while(p!=NULL)
    {
        if(p->expo == 0)
            printf(" %d",p->coef);
        else
            printf(" %dx^%d +",p->coef,p->expo);
        p = p->next;
    }
    printf("\n\n\n");     
}

void enterData(int exp, struct Node * p,int x, int y)
{
    struct Node * temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->coef = x;
    temp->expo = y;
    temp->next = NULL;
    if(p == NULL)
    {
        if(exp == 1)
            start1 = temp;
        else if(exp == 2)
            start2 = temp;
        else if(exp == 3) 
            start3 = temp;
    }
    else
    {
        while(p->next!=NULL)
            p = p->next;
        p->next = temp;
    }
}


