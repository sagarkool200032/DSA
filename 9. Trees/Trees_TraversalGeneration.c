#include<stdio.h>
#include<stdlib.h>

struct node {
struct node *lchild;
struct node *rchild;
int data;
}*root=NULL;

int inde(int *inorder,int x)
{
    int i=0;
    int size = sizeof(inorder)/sizeof(inorder[0])-1;
    while(inorder[i]!=x)
    {
        i++;
    }
    return i;
}

struct node* build(int *inorder,int *preorder,int start,int stop)
{
    static int p=0;
    int split;
    struct node *t;
    if(start>stop)
        return NULL;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=preorder[p++];
    if(start==stop)
    {
        t->lchild=NULL;
        t->rchild=NULL;
        return t;
    }
    split=inde(inorder,t->data);
    t->lchild=build(inorder,preorder,start,split-1);
    t->rchild=build(inorder,preorder,split+1,stop);
    return t;
}

void rpreorder(struct node *p)
{
if(p!=0)
{
printf("%d ",p->data);
rpreorder(p->lchild);
rpreorder(p->rchild);
}
}



int main()

{

int inorder[]={1,31,2,30,3,32,4};

int preorder[]={30,31,1,2,32,3,4};

int size = sizeof(inorder)/sizeof(inorder[0])-1;

struct node *r=build(inorder,preorder,0,size);



rpreorder(r);

}