#include<bits/stdc++.h>
using namespace std;

#define Size 50
//declare array and top globally
int A[Size];
int top=-1;

void push(int x)
{
    if(top==Size-1){
        printf("Size overflow\n");
        return;
    }
    A[++top] = x;
}

int Top(){
    return A[top];
}

void pop()
{
    if(top==-1){
        printf("No element\n");
        return;
    }
    top--;
}

bool isEmpty(){
    return top == -1;
}


int main(){

    push(1);
    push(2);
    push(3);
    push(4);
    cout<<Top()<<"\n";
    pop();
    cout<<Top()<<"\n";
    pop();
    pop();
}
