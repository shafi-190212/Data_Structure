#include<bits/stdc++.h>
using namespace std;
#define WHITE 1
#define GRAY 2
#define BLACK 3
int adj[100][100];
int color[100];
int st[100];
int ft[100];
int t=1;
int node,edge;

void Visit(int x)
{
    color[x]=GRAY;
    st[x]=t;
    t++;
    for(int i=0;i<node;i++)
    {
        if(adj[x][i]==1)
        {
            if(color[i]==WHITE)
            {
                Visit(i);
            }
        }
    }
    color[x]=BLACK;
    ft[x]=t;
    t++;
}

void DFS()
{
    for(int i=0;i<node;i++)
    {
        color[i]=WHITE;
    }
    for(int i=0;i<node;i++)
    {
        if(color[i]==WHITE)
            Visit(i);
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
        //adj[n2][n1]=1;
    }

    for(int i=0;i<node;i++)
    {
        for(int j=0;j<node;j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\nAdjacent Node: \n";
    for(int i=0;i<node;i++)
    {
        cout<<"Node "<<i<<": ";
        for(int j=0;j<node;j++)
        {
            if(adj[i][j]==1)
                cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    DFS();
    for(int i=0;i<node;i++)
    {
        cout<<"Node "<<(char)('A'+i)<<": "<<st[i]<<" "<<ft[i]<<endl;
    }
}

