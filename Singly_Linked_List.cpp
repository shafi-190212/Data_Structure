//Singly Linked List Implementation
#include<bits/stdc++.h>
using namespace std;

typedef struct node Node;
struct node
{
    int data;
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
    head = temp;
}

//inserting node at nth position
void insertAt(int value,int position)
{
    Node *temp = new Node();
    temp->data = value;
    temp->next = NULL;
    //if position==1 we have to apply the logic of insertFirst
    if(position==1){
        temp->next = head;
        head = temp;
        return;
    }

    Node *p = head;
    for(int i=1; i<position-1; i++)
    {
        p = p->next;
    }
    temp->next = p->next;
    p->next = temp;
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
}

//Delete a node at nth position
void Delete(int position)
{
    Node *p = head;
    if(position==1){
        head = head->next;
        free(p);
        return;
    }
    for(int i=1;i<position-1;i++)
    {
        p = p->next;
    }
    Node *q = p->next ;
    p->next = q->next;
    free(q);
}

void Print(){
    Node *p = head;
    cout<<"List is: ";
    while(p!=NULL){
        cout<< p->data <<" ";
        p = p->next;
    }
    cout<<"\n";
}

void Reverse()
{
    Node*current, *prev, *next;
    current = head;
    prev = NULL;
    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
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
    insertAtFirst(3);
    insertAtFirst(2);
    insertAtFirst(1);
    Print();
    insertAtLast(4);
    insertAtLast(5);
    print(head);
    insertAt(6,5);
    //Delete(5);
    printRev(head);
}
