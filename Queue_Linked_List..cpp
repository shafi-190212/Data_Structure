#include<bits/stdc++.h>
using namespace std;


typedef struct node Node;
struct node{
    int data;
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;

void enqueue(int x)
{
    Node *temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if(front==NULL && rear==NULL){
        front=rear=temp;
    }
    rear->next = temp;
    rear = temp;
}

void dequeue(){
    Node *p = front;
    if(front==NULL){
        printf("queue is empty\n");
        return;
    }
    if(front==rear){
        front=rear=NULL;
        return;
    }
    else{
        front = front->next;
    }
    free(p);
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    cout<<front->data<<"\n;
    dequeue();
    cout<<front->data<<"\n";


}
