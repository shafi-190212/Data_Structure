//Doubly Linked List Implementation
#include<bits/stdc++.h>
using namespace std;

typedef struct node Node;
struct node
{
    int data;
    Node *prev;
    Node *next;
};

Node *head = NULL;//declare head globally

//inserting at the beginning
void insertAtFirst(int value)// complexity- O(1)
{
    Node *temp = new Node();
    //Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = head;
    if(head==NULL){
        temp->prev = head;
        head = temp;
        return;
    }
    head->prev = temp;
    head = temp;
}

//inserting node at nth position
void insertAt(int value,int position)
{
    Node *temp = new Node();
    temp->data = value;
    //if position==1 we have to apply the logic of insertFirst
    if(position==1){
        temp->next = head;
        temp->prev = NULL;
        head = temp;
    }

    Node *p = head;
    for(int i=1; i<position-1; i++)
    {
        p = p->next;
    }
    Node *q = p->next;
    temp->next = q;
    q->prev = temp;
    p->next = temp;
    temp->prev = p;
}

//inserting an element at last
void insertAtLast(int value)
{
    Node *temp = new Node();
    temp->data = value;
    temp->next = NULL;
    Node *p = head;
    while(p->next!=NULL)
    {
        p = p->next;
    }
    p->next = temp;
    temp->prev = p;
}

//Delete a node at nth position
void Delete(int position)
{
    Node *p = head;
    if(position==1){
        head = head->next;
        head->prev = NULL;
        free(p);
        return;
    }
    for(int i=1;i<position-1;i++)
    {
        p = p->next;
    }
    Node *q = p->next;
    Node *r = q->next;
    p->next = r;
    r->prev = p;
    free(q);
}

void Print(){
    Node *p = head;
    cout<<"List is: ";
    while(p->next!=NULL){
        p = p->next;
    }
    while(p!=NULL){
        cout<< p->data <<" ";
        p = p->prev;
    }
    cout<<"\n";
}

//printing Linked List recursively
void print(Node* p){
    if(p==NULL){
        printf("\n");
        return;
    }
    printf("%d ",p->data);
    print(p->next);
}

//printing Linked List reversely
void printRev(Node* p){
    if(p==NULL){
        printf("\n");
        return;
    }
    printRev(p->next);
    printf("%d ",p->data);
}


int main(){

    insertAtFirst(6);
    insertAtFirst(4);
    insertAtFirst(3);
    insertAtFirst(2);
    insertAtFirst(1);
    print(head);
    insertAt(5,5);
    Print();
    insertAtLast(7);
    insertAtLast(8);
    print(head);
    Delete(5);
    print(head);
//    printRev(head);
}

