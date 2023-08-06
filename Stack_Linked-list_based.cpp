#include<bits/stdc++.h>
using namespace std;

typedef struct node Node;

struct node{
    int data;
    Node *next;
};

Node *top=NULL;

void push(int x){
    Node *temp = new Node();
    temp->data = x;
    temp->next = top;
    top = temp;
}

void pop(){
    Node *p;
    if(top==NULL){
        printf("Stack is empty\n");
        return;
    }
    p = top;
    top = top->next;
    free(p);

}

int Top(){
    if(top==NULL)
        return -1;
    return top->data;
}

bool isEmpty(){
    return top==NULL;
}



int main()
{
    push(1);
    push(2);
    push(3);
    cout<<Top();
    pop();
    cout<<Top();
    return 0;
}
