#include <stdio.h>

#include <stdlib.h>

#include<string.h>

struct Stack

{

    char data;

    struct Stack *next;

}*top=NULL;

void Push(char x)

{

    struct Stack *t;

    t=(struct Stack*)malloc(sizeof(struct Stack));

    if(t==NULL)

        printf("Stack Overflow");

    else

    {

        t->data=x;

        t->next=top;

        top=t;

    }

}

char Pop()

{

    struct Stack *t;

    char x='-1';

    if(top==NULL)

        printf("Stack empty\n");

    else

    {

        t=top;

        top=top->next;

        x=t->data;

        free(t);

    }

    return x;

}

void display()

{

    struct Stack *p;

    p=top;

    while(p!=NULL)

    {

        printf("%c\n",p->data);

        p=p->next;

    }

}

char Peek(int pos)

{

    struct Stack *p=top;

    char x='-1';

    for(int i=0;p!=NULL && i<pos-1;i++)

    {

        p=p->next;

    }

    if(p!=NULL)

        x=p->data;

    return x;

}

char Stacktop()

{

    char x='    ';

    if(top!=NULL)

        x=top->data;

    return x;

}

int isFull()

{

    struct Stack *t;

    t=(struct Stack*)malloc(sizeof(struct Stack));

    if(t==NULL)

        return 1;

    else

        return 0;

}

int isEmpty()

{

    if(top==NULL)

        return 1;

    else

        return 0;

}

int isBalanced(char *exp)  //paranthesis matching

{

    //char x;

    for(int i=0;exp[i]!='\0';i++)

    {

        if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')

            Push(exp[i]);

        else if(exp[i]==')'||exp[i]=='}'||exp[i]==']')

        {

            if(top==NULL)

                return 0;

            else if((exp[i]==')'&&Stacktop()=='(') || (exp[i]=='}'&&Stacktop()=='{') || (exp[i]==']'&&Stacktop()=='['))

            {

                Pop();

            }

            else

            {

                return 0;

            }

        }

    }

    return (top==NULL)?1:0;

}

int outpre(char x)

{

    if(x=='+' || x=='-')

        return 1;

    else if(x=='*' || x=='/')

        return 3;

    else if(x=='^')

        return 6;

    else if(x=='(')

        return 7;

    else if(x==')')

        return 0;

    return -1;

}

int inpre(char x)

{

    if(x=='+' || x=='-')

        return 2;

    else if(x=='*' || x=='/')

        return 4;

    else if(x=='^')

        return 5;

    else if(x=='(')

        return 0;

    return -1;

}

int isOperand(char x)

{

    if(x=='+' || x=='-' ||x=='*' || x=='/' || x=='(' || x==')' || x=='^')

        return 0;

    else

        return 1;

}

char* InfToPosfix(char *infix)

{

    char *postfix;

    int len=strlen(infix);

    postfix=(char*)malloc((len+1)*sizeof(char));

    int i=0,j=0;

    while(infix[i]!='\0')

    {

        if(isOperand(infix[i]))

            postfix[j++]=infix[i++];

        else

        {

            if(outpre(infix[i])>inpre(Stacktop()))

                Push(infix[i++]);

            else if(outpre(infix[i])<inpre(Stacktop()))

            {

                postfix[j++]=Pop();

            }

            else if(outpre(infix[i])==inpre(Stacktop()))

            {

                Pop();

                i++;

            }

        }

    }

    while(top!=NULL)

    {

        postfix[j++]=Pop();

    }

    postfix[j]='\0';

    return postfix;

}

int main()

{

    char *infix="((a+b)*c)-d^e^f";

    char *postfix=InfToPosfix(infix);

    printf("%s \n",postfix);

    free(infix);

    free(postfix);

    return 0;

}