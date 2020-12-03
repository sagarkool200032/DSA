#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node * lchild;
    struct Node * rchild;
    int data;
}*root=NULL;

// Time Complexity: O(logn)
void Insert(int key)
{
    struct Node*t=root;
    struct Node *r,*p,*temp;  // r is tailing pointer
    if(root==NULL)
    {
        p=(struct Node*)malloc(sizeof(struct Node));
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return;
    }
    while(t!=NULL)
    {
        r=t;
        if(key<t->data)
            t=t->lchild;
        else if(key>t->data)
            t=t->rchild;
        else return;
    }
    p=(struct Node*)malloc(sizeof(struct Node));
    p->data=key;
    p->lchild=p->rchild=NULL;
    if(key<r->data)
        r->lchild=p;
    else
        r->rchild=p;
}

// Time Complexity: O(logn)
struct Node * Search(int key)
{
    struct Node * t = root;
    while(t!=NULL)
    {
        if(key==t->data)
            return t;
        else if (key<t->data)
            t=t->lchild;
        else
            t=t->rchild;
    }
    return NULL; 
}

void inorder(struct Node* q)
{
    if(q)
    {
        inorder(q->lchild);
        printf("%d ",q->data);
        inorder(q->rchild);
    }
}

int main()
{
    struct Node * res;
    Insert(5);
    Insert(15);
    Insert(10);
    Insert(20);
    Insert(55);
    Insert(155);
    Insert(105);
    Insert(205);
    Insert(58);
    Insert(152);
    inorder(root);
    printf("\n");
    res = Search(10);
    if(res!=NULL)
        printf("Element %d is found\n",res->data);
    else
        printf("Element is not found");    
    return 0;
}