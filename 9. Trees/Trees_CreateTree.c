#include <stdio.h>
#include "Queue.h"

struct Node * root = NULL;

// Uses Queue
void createTree()
{
    struct Node * p;
    struct Node * t;
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

// Tree Tranversing Methods
// Time Complexity: O(n)
// Space Complexity: O(n)
void preorder(struct Node * p)
{
    if (p)
    {
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(struct Node * p)
{
    if (p)
    {
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}

void postorder(struct Node * p)
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->data);
    }
}

int main()
{
    createTree();

    printf("Preorder: ");
    preorder(root);

    printf("\nInorder: ");
    inorder(root);

    printf("\nPostorder: ");
    postorder(root);

}