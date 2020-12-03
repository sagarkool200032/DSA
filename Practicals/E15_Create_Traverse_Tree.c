#include "Queue.h"
struct Node * root = NULL;
// Uses Queue
void createTree()
{
    struct Node * p;
    struct Node * t;
    int x;
    printf("Enter Root Value: ");
    scanf("%d",&x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = NULL;
    root->rchild = NULL;
    enqueue(root);
    while (!isEmpty())
    {
        p = dequeue();
        printf("Enter left child value of %d (if no child enter -1): ",p->data);
        scanf("%d",&x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = NULL;
            t->rchild = NULL;
            p->lchild = t;
            enqueue(t);
        }

        printf("Enter right child value of %d (if no child enter -1): ",p->data);
        scanf("%d",&x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = NULL;
            t->rchild = NULL;
            p->rchild = t;
            enqueue(t);
        } 
    }
}

// Tree Traversing Methods
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
    int option = 1;
    while(option!=0)
    {
        printf("\n\n1.Create\n2.Preorder\n3.Inorder \n4.Postorder \n5.Exit\nEnter Option:  ");
        scanf("%d",&option);
        if(option==1)
            createTree();
        else if(option==2)
        {
            printf("\nPreorder: ");
            preorder(root);
        }
        else if(option==3)
        {
            printf("\nInorder: ");
            inorder(root);
        }
        else if(option==4)
        {
            printf("\nPreorder: ");
            postorder(root);
        }
        else
            option = 0;    
    }
}