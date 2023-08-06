#include<bits/stdc++.h>
using namespace std;

struct node
{
    int value;
    struct node *left;
    struct node *right;
};
typedef struct node Node;

#define true 1
#define false 0
#define MAX(a,b)  (a < b ? b : a)

typedef struct que Queue;
struct que{
    int size;
    int front;
    int rear;
    Node **arr;
};


bool isEmpty(Queue q){
    return q.front==q.rear;
}

void Enqueue(Queue *q,Node *x)
{
    if((q->rear+1)%q->size == q->front){
        printf("queue is full\n");
        return;
    }
    q->rear=(q->rear+1) % q->size;
    q->arr[q->rear] = x;
}

void Dequeue(Queue *q)
{
    if(q->rear == q->front){
        printf("queue is empty\n");
        return;
    }
    q->front = (q->front+1) %  q->size;
}

Node* Front(Queue *q){
    if(q->front==-1)
        q->front++;
    return q->arr[q->front];
}

Node *createNode(int value)
{
    Node * newNode =  (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->right= NULL;
    newNode->left = NULL;

    return newNode;
}

Node *addNode(Node *root, int value)
{
    if(!root)
        return createNode(value);

    if (root->value > value)
        root->left = addNode(root->left, value);
    else
        root->right = addNode(root->right, value);

    return root;
}

int height( Node *root)
{
    if( !root )
        return 0;

    int lheight = height( root->left);
    int rheight = height( root->right);

    return 1 + MAX (lheight, rheight );
}

int isHeightBalanced( Node * root )
{
    if(!root) return true;

    int lheight = height( root->left );
    int rheight = height( root->right );

    return (abs( lheight-rheight) <= 1 )
           && isHeightBalanced( root->left )
           && isHeightBalanced( root->right );
}

void LevelOrder(Node *root){
    Queue q;
    Node *p = root;
    printf("%d ",p->value);
    Enqueue(&q,p);//push the node to queue
    while(!isEmpty(q)){
        p = Front(&q);
        Dequeue(&q);
        if(p->left){//check for the left child
            printf("%d ",p->left->value);
            Enqueue(&q,p->left);
        }
        if(p->right){////check for the right child
            printf("%d ",p->right->value);
            Enqueue(&q,p->right);
        }
    }
    printf("\n");
}


void PreOrder(Node *p){
    if(p!=NULL){
        printf("%d ",p->value);
        PreOrder(p->left);
        PreOrder(p->right);
    }
}


void InOrder(Node *p){
    if(p!=NULL){
        InOrder(p->left);
        printf("%d ",p->value);
        InOrder(p->right);
    }
}


void PostOrder(Node *p){
    if(p!=NULL){
        PostOrder(p->left);
        PostOrder(p->right);
        printf("%d ",p->value);
    }
}

int NodeCount(Node *p)
{
    int left,right;
    if(p!=NULL){
        left = NodeCount(p->left);
        right = NodeCount(p->right);
        return left+right+1;
    }
    return 0;
}

int NodeOfDegree2(Node *p)
{
    int left,right;
    if(p!=NULL){
        left = NodeCount(p->left);
        right = NodeCount(p->right);
        if(p->left&&p->right)
            return left+right+1;
        else
            return left+right;
    }
    return 0;
}

int LeafNodes(Node *p){
    int left,right;
    if(p!=NULL){
        left = NodeCount(p->left);
        right = NodeCount(p->right);
        if(p->left==NULL&&p->right==NULL)
            return left+right+1;
        else
            return left+right;
    }
    return 0;
}

int InternalNodes(Node *p)
{
    int left,right;
    if(p!=NULL){
        left = NodeCount(p->left);
        right = NodeCount(p->right);
        if(p->left || p->right)
            return left+right+1;
        else
            return left+right;
    }
    return 0;
}

int ExactDegree1(Node *p)
{
    int left,right;
    if(p!=NULL){
        left = NodeCount(p->left);
        right = NodeCount(p->right);
        /*(p->left&&p->right==NULL)||
           (p->left==NULL&&p->right)*/
        if(p->left ^ p->right)
            return left+right+1;
        else
            return left+right;
    }
    return 0;
}

int sumOfAllElements(Node *p)
{
    int left,right;
    if(p!=NULL){
        left = NodeCount(p->left);
        right = NodeCount(p->right);
        return left+right+p->value;
    }
    return 0;
}

int main()
{
    return 0;
}

