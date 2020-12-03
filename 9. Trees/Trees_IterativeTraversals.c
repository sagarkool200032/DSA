#include <stdio.h>
#include "Queue.h"
#include "Stack.h"

typedef struct Node * Node;
Node root = NULL;
 
void createTree()
{
    Node p;
    Node t;
    int x;
    struct Queue q;
    create(&q,100);
    printf("Enter Root Value: ");
    scanf("%d",&x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = NULL;
    root->rchild = NULL;
    enqueue(&q,root);
 
    while (! isEmpty(q))
    {
        p = dequeue(&q);
        printf("Enter left child value of %d: ",p->data);
        scanf("%d",&x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = NULL;
            t->rchild = NULL;
            p->lchild = t;
            enqueue(&q,t);
        }

        printf("Enter right child value of %d: ",p->data);
        scanf("%d",&x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = NULL;
            t->rchild = NULL;
            p->rchild = t;
            enqueue(&q,t);
        } 
    }
}

// Iterative Tree Tranversing Methods
// Time Complexity: O(n)
// Space Complexity: O(n)

// Uses Stack DS
void IPreorder(Node p)
{
    struct Stack st;
    createStack(&st,100);
    while (p != NULL || ! isStackEmpty(st))
    {
        if (p != NULL)
        {
            printf("%d ",p->data);
            push(&st,p);
            p = p->lchild;
        } 
        else
        {
            p = pop(&st);
            p = p->rchild;
        }
    }
    printf("\n");
}

void IInorder(Node p)
{
    struct Stack st;
    createStack(&st,100);
    while (p != NULL || ! isStackEmpty(st))
    {
        if (p != NULL)
        {
            push(&st,p);
            p = p->lchild;
        } 
        else
        {
            p = pop(&st);
            printf("%d ",p->data);
            p = p->rchild;
        }
    }
    printf("\n");
}

void IPostorder(Node p)
{
    long S[100];
    int Top=-1;
    long temp;
    while(p || Top!=-1)
    {
        if(p)
        {
            S[++Top]=(long)p;
            p=p->lchild;
        }
        else
        {
            temp=S[Top--];
            if(temp>0)
            {
                p=(Node)temp;
                p=p->rchild;
                S[++Top]=-temp;
            }
            else
            {
                p=(Node)-temp;
                printf("%d ",p->data);
                p=NULL;
            }
        }
    }
    printf("\n");
}

void ILevelorder(Node p)
{
    struct Queue q2;
    create(&q2,100);
    printf("%d ",p->data);
    enqueue(&q2,p);
    while(!isEmpty(q2))
    {
        p=dequeue(&q2);
        if(p->lchild)
        {
            printf("%d ",p->lchild->data);
            enqueue(&q2,p->lchild);
        }
        if(p->rchild)
        {
            printf("%d ",p->rchild->data);
            enqueue(&q2,p->rchild);
        }
    }
    printf("\n");
}

int main()
{
    createTree();
    IPreorder(root);
    IInorder(root);
    IPostorder(root);
    ILevelorder(root);
}