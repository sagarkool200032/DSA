#include "CircularLL.h"

int main()
{
    struct Node *p;
    for(int i=1;i<=100;i++)
        enterData(i);
    p = head;
    do
    {
        struct Node *temp=p;
        printf("%d ",p->data);
        if(temp->next==head)
            head = temp->next->next;
        temp->next = temp->next->next;
        p=p->next;
        if(p==head)
            printf("\n");
    }while(head->next!=head);
    printf("Last Man Standing: %d \n",head->data);  
}
