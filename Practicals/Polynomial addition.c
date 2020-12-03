#include "LinkedList.h"
typedef struct Node * Node;

void addPoly(Node p1, Node p2)
{
    Node p3 = start3;
    int x,y;
    while(p1 && p2)
    {
        if(p1->expo > p2->expo )
        {
            x = p1->coef;
            y = p1->expo;
            p1 = p1->next;  
        }
        else if(p1->expo < p2->expo )
        {
            x = p2->coef;
            y = p2->expo;
            p2 = p2->next;
        }
        else if(p1->expo == p2->expo )
        {
            x = p1->coef+p2->coef;
            y = p1->expo;
            p1 = p1->next;
            p2 = p2->next;
        }
        enterData(3,start3,x,y);
    }
    while(p1)
    {
        x = p1->coef;
        y = p1->expo;
        enterData(3,start3,x,y);
        p1 = p1->next;
    }
    while(p2)
    {
        x = p2->coef;
        y = p2->expo;
        enterData(3,start3,x,y);
        p2 = p2->next;
    }    
}

int main()
{
    int x,y,terms;
    printf("Enter Total Terms in  1st Expression: ");
    scanf("%d",&terms);
    for(int i=0;i<terms;i++)
    {
        printf("Enter %d Term Coeffecient and Exponent: ",i+1);
        scanf("%d %d",&x,&y);
        enterData(1,start1,x,y);
    }
    printf("Expression 1: ");display(start1);

    printf("Enter Total Terms in 2nd Expression: ");
    scanf("%d",&terms);
    for(int i=0;i<terms;i++)
    {
        printf("Enter %d Term Coeffecient and Exponent: ",i+1);
        scanf("%d %d",&x,&y);
        enterData(2,start2,x,y);
    }
    printf("Expression 2: ");display(start2);  
      
    addPoly(start1,start2);
    printf("Answer: ");display(start3);  
}