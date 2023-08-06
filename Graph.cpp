#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    int vertex;
    int edge;
    cin>>vertex>>edge;
    vector<pair<int,int>>v[vertex];
    for(int i=0;i<edge;i++)
    {
        int s1,s2,w;
        cin>>s1>>s2>>w;
        v[s1].push_back({s2,w});
       // v[s2].push_back({s1,w});
    }
    for(int i=0;i<vertex;i++)
    {
        cout<<i<<" -- ";
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j].first<<"-"<<v[i][j].second<<" ";
        }
        cout<<endl;
    }
}
