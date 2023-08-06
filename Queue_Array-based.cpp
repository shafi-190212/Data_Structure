#include<bits/stdc++.h>
using namespace std;


#define size 20
int A[20];
int front=0;
int rear =-1;

bool isEmpty(){
    return (front==-1 && rear==-1);
}

void enqueue(int x){
    if(rear == size-1){
        printf("queue is full\n");
        return;
    }
    A[++rear] = x;
}

void dequeue(){
    if(isEmpty()){
        printf("queue is empty\n");
        return;
    }
    front++;
}

int Front(){
    return A[front];
}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    cout<<Front()<<"\n";
    dequeue();
    cout<<Front()<<"\n";
    return 0;
}
