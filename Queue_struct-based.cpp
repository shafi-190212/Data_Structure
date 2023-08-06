#include<bits/stdc++.h>
using namespace std;


typedef struct node Queue;
struct node{
    int size;
    int front;
    int rear;
    int *arr;
};

bool isEmpty(Queue *q){
    return q->front==q->rear;
}

void enqueue(Queue *q,int x)
{
    if((q->rear+1)%q->size == q->front){
        printf("queue is full\n");
        return;
    }
    q->rear=(q->rear+1) % q->size;
    q->arr[q->rear] = x;
}

void dequeue(Queue *q)
{
    if(q->rear == q->front){
        printf("queue is empty\n");
        return;
    }
    q->front = (q->front+1) %  q->size;
}

int Front(Queue *q){
    if(q->front==-1)
        q->front++;
    return q->arr[q->front % q->size];
}


int main()
{
    return 0;
}
