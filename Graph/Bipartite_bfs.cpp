#include<iostream>
#include <bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;

void in_out_code()
{
 #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 #endif
}

bool isBipartite(int n,vector<int>adj[],int color[])
{
    queue<int>q;
    q.push(n);
    color[n]=1;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto itr:adj[node])
        {
            if(color[itr]==-1)
            {
                color[itr]=1-color[node];
                q.push(itr);
            }else if(color[itr]==color[node]) return false;
        }
    }
    return true;
}
bool Bipartite(int n,vector<int>adj[])
{
    int color[n];
    memset(color,-1,sizeof color);
    for(int i=0;i<n;i++)
    {
        if(color[i]==-1)
        {
        if(!isBipartite(i,adj,color))
            return false;
        }
    }
    return true;
}
int main()
{
 in_out_code();
    int v,e;
    cin>>v>>e;

    vector<int>adj[v+1];
    

    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout<<Bipartite(v,adj);
    
    
}
