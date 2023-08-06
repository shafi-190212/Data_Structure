#include<bits/stdc++.h>
using namespace std;

struct node
{
    bool endmark;
    node *next[26+1];
    node()
    {
        endmark=false;
        for(int i=0;i<26;i++)
            next[i]=NULL;
    }
}*root;

void Insert(char *str)
{
    node *curr=root;
    for(int i=0;i<strlen(str);i++)
    {
        int idx=str[i]-'a';
        if(curr->next[idx]==NULL)
            curr->next[idx]=new node();
        curr=curr->next[idx];
    }
    curr->endmark=true;
}

bool Search(char *str)
{
    node *curr=root;
    for(int i=0;i<strlen(str);i++)
    {
        int idx=str[i]-'a';
        if(curr->next[idx]==NULL)
            return false;
        curr=curr->next[idx];
    }
    return curr->endmark;
}

void Del(node *curr)
{
    for(int i=0;i<26;i++)
        if(curr->next[i])
            Del(curr->next[i]);
    delete curr;
}

int main()
{
    int n;
    cout<<"Number of Words: ";
    cin>>n;
    root=new node();
    for(int i=0;i<n;i++)
    {
        char str[50];
        cin>>str;
        Insert(str);
    }
    int query;
    cout<<"No of query: ";
    cin>>query;
    for(int i=0;i<query;i++)
    {
        char st[50];
        cin>>st;
        if(Search(st))
            puts("FOUND");
        else
            puts("NOT FOUND");
    }
    Del(root);
    return 0;
}

