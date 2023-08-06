#include<bits/stdc++.h>
using namespace std;

vector<string>vname;
map<string,int>vnum;

int main()
{
    freopen("Graph.txt","r",stdin);
    int vertex;
    int edge;
    cin>>vertex>>edge;
    vector<pair<int,int>>v[vertex];
    for(int i=0;i<vertex;i++)
    {
        string str;
        cin>>str;
        vname.push_back(str);
        vnum[str]=i;
    }

    for(int i=0;i<edge;i++)
    {
        string s1,s2;
        int w;
        cin>>s1>>s2>>w;
        int x,y;
        x=vnum[s1];
        y=vnum[s2];
        v[x].push_back({y,w});
        v[y].push_back({x,w});
    }

    for(int i=0;i<vertex;i++)
    {
        cout<<vname[i]<<"-- ";
        for(int j=0;j<v[i].size();j++)
        {
            cout<<vname[v[i][j].first]<<"-"<<v[i][j].second<<"  ";
        }
        cout<<endl;
    }
}

