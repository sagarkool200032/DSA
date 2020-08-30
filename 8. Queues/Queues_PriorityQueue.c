// Limited Set of Priorities
#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

int isEmpty(struct Queue q)
{
    if(q.rear==q.front) return 1;
    else return 0;
}

void Display(struct Queue q)
{
    if(isEmpty(q))
        return ;
    int i=q.front+1;
    do
    {
        printf("%d ",q.Q[i]);
        i=(i+1)%q.size;
    }while(i!=(q.rear+1)%q.size);
    printf("\n");
}

void create(struct Queue *qp1,struct Queue *qp2,struct Queue *qp3)
{
    printf("Enter Number of elements: ");
    scanf("%d",&qp1->size);
    qp1->front=qp1->rear=0;
    qp1->Q=(int *)malloc(sizeof(int)*(qp1->size));
    qp3->front=qp2->front=0;
    qp3->rear=qp2->rear=0;
    qp3->size=qp2->size=qp1->size;
    qp2->Q=(int *)malloc(sizeof(int)*(qp2->size));
    qp3->Q=(int *)malloc(sizeof(int)*(qp3->size));
}

void enqueue(struct Queue *q,int x)
{
    if((q->rear+1)%q->size==q->front)
        printf("Queue if Full\n");
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

int dequeue(struct Queue *q)
{
    int x=-1;
    if(q->rear==q->front)
        printf("Queue is empty\n");
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}

int delete(struct Queue *q1,struct Queue *q2,struct Queue *q3)

{
    int x=-1;
    if(!isEmpty(*q1))
        x=dequeue(q1);
    else if(!isEmpty(*q2))
        x=dequeue(q2);
    else
        x=dequeue(q3);
    return x;
}

int main()
{
    int i;
    
    struct Queue qp1,qp2,qp3;
    create(&qp1,&qp2,&qp3);
    printf("Enter elements with there priorities:\n");
    for(i=0;i<qp1.size;i++)
    {
        int value,prio;
        scanf("%d%d",&value,&prio);
        switch(prio){
            case 1:
                enqueue(&qp1,value);
                break;
            case 2:
                enqueue(&qp2,value);
                break;
            case 3:
                enqueue(&qp3,value);
                break;
            default:
                printf("Not a valid value");
        }
    }

    delete(&qp1,&qp2,&qp3);
    delete(&qp1,&qp2,&qp3);
    delete(&qp1,&qp2,&qp3);

    Display(qp1);
    Display(qp2);
    Display(qp3);

    return 0;

}