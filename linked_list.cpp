#include<bits/stdc++.h>
using namespace std;
typedef struct node Node;

struct node
{
    int data;
    Node *next;
}*head=NULL,*last=NULL;

void Insert(int x)
{
    Node *temp=new Node;
    temp->data=x;
    temp->next=NULL;
    if(head==NULL)
    {
        head=last=temp;
    }
    last->next=temp;
    last=temp;
}

void Delete(int n)
{
    Node *p=head;
    Node *temp,*q;
    if(n==1)
    {
        temp=head;
        head=head->next;
        delete temp;
        return;
    }
    n=n-1;
    while(n--)
    {
        q=p;
        p=p->next;
    }
    q->next=p->next;
    delete p;
}

void Print(Node *p)
{
    if(p==NULL)
    {
        cout<<"\n";
        return;
    }
    printf("%d ",p->data);
    Print(p->next);
}

int main()
{
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);
    Insert(5);
    Print(head);
    Delete(1);
    Print(head);
    return 0;
}
