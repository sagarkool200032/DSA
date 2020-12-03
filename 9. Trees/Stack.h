// Stack using Array
// All the operations are done in O(n)
#include <stdio.h>
#include <stdlib.h>

typedef struct Node * Node;
struct Stack
{
    int size;
    int top;
    struct Node **S;
};

void createStack(struct Stack *st,int size)
{
    st->size=size;
    st->top=-1;
    st->S=(Node *)malloc(st->size*sizeof(Node));
}

void Display(struct Stack st)
{
    int i;
    for(i=st.top;i>=0;i--)
        printf("%d ",st.S[i]);
    printf("\n");
}

void push(struct Stack *st,Node x)
{
    if(st->top==st->size-1)
        printf("Stack overflow\n");
    else
    {
        st->top++;
        st->S[st->top]=x;
    }
}

Node pop(struct Stack *st)
{
    Node x=NULL;

    if(st->top==-1)
        printf("Stack Underflow\n");
    else
        x=st->S[st->top--];
    return x;
}

// Formula: top-index+1
// Node peek(struct Stack st,Node index)
// {
//     int x=NULL;
//     if(st.top-index+1<0)
//         printf("Invalid Index \n");
//     x=st.S[st.top-index+1];
//     return x;
// }

int isStackEmpty(struct Stack st)
{
    if(st.top==-1)
        return 1;
    return 0;
}

int isFull(struct Stack st)
{
    return st.top==st.size-1;
}

Node stackTop(struct Stack st)
{
    if(!isStackEmpty(st))
        return st.S[st.top];
    return NULL;
}
