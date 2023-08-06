#include<bits/stdc++.h>
using namespace std;
typedef struct node Node;

struct node
{
    int data;
    Node *next;
}*Front=NULL,*Rear=NULL;

void Enqueue(int x)
{
    Node *t;
    t=new Node;
    if(t==NULL)
        cout<<"Queue is Full\n";
    else{
        t->data=x;
        t->next=NULL;
        if(Front==NULL)
            Front=Rear=t;
        else
        {
            Rear->next=t;
            Rear=t;
        }
    }
}

int Dequeue()
{
    int x=-1;
    Node *t;
    if(Front==NULL)
    {
        cout<<"Queue is Empty\n";
    }
    else{
        x=Front->data;
        t=Front;
        Front=Front->next;
        delete t;
    }
    return x;
}

int isEmpty()
{
    return Front==NULL;
}

int node,edge;
int adj[100][100];
int visited[100];

void DFS(int start)
{
    if(visited[start]==0)
    {
        printf("%d ",start);
        visited[start]=1;
        for(int j=0;j<node;j++)
        {
            if(adj[start][j]==1&&visited[j]==0)
                DFS(j);
        }
    }
}

void BFS(int start)
{
    int i=start;
    cout<<i<<" ";
    visited[i]=1;
    Enqueue(i);
    while(!isEmpty())
    {
        i=Dequeue();
        for(int j=0;j<node;j++)
        {
            if(adj[i][j]==1&&visited[j]==0)
            {
                cout<<j<<" ";
                visited[j]=1;
                Enqueue(j);
            }
        }
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    cin>>node>>edge;
    int n1,n2;
    for(int i=0;i<edge;i++)
    {
        cin>>n1>>n2;
        adj[n1][n2]=1;
        adj[n2][n1]=1;
    }
    for(int i=0;i<node;i++)
    {
        cout<<"Node "<<i<<": ";
        for(int j=0;j<node;j++)
        {
            if(adj[i][j]==1)
            {
                cout<<j<<" ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
    BFS(3);
}
