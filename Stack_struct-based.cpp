#include<bits/stdc++.h>
using namespace std;

typedef struct stk Stack;
struct stk{
    int top;
    int size;
    int *arr;
};


void push(Stack *st,int x) //O(1)
{
    if(st->top == st->size-1){
        printf("Stack overflow\n");
    }else{
        st->top++;
        st->arr[st->top] = x;
    }
}

void pop(Stack *st)//O(1)
{
    if(st->top==-1){
        printf("No element\n");
        return;
    }
    st->top--;
}

int Top(Stack st){
    if(st.top==-1)
        return -1;
    return st.arr[st.top];
}

bool isEmpty(Stack st){
    return st.top==-1;
}

int main()
{
    Stack st;
    cout<<"Enter the Size of the Stack: ";
    cin>>st.size;
    st.arr = new int[st.size];
    st.top=-1;
}
