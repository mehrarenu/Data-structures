#include<iostream>
#include<stack>
#include <bits/stdc++.h>
#include<vector>
using namespace std;

void in_out_code()
{
 #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
 #endif
}
void toposort(vector<pair<int,int>>adj[],int node,int vis[],stack<int>&s)
{
	vis[node]=1;
	for(auto itr:adj[node])
	{
		if(!vis[itr.first])
		{
			toposort(adj,itr.first,vis,s);
		}
	}
	s.push(node);
}
void shortestpath(int src,vector<pair<int,int>>adj[],int n)
{
	int vis[n]={0};
	stack<int>s;
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			toposort(adj,i,vis,s);
		}
	}
	int dist[n];
	for(int i=0;i<n;i++)
		dist[i]=1e9;
	dist[src]=0;

	while(!s.empty())
	{
		int node=s.top();
		s.pop();
		if(dist[node]!=1e9)
		{
			for(auto itr:adj[node])
			{
				if(dist[node]+itr.second<dist[itr.first])
				{
					dist[itr.first]=itr.second+dist[node];
				}

			}
		}
	}
	for(int i=0;i<n;i++)
		(dist[i]==1e9)?cout<<"INF":cout<<dist[i]<<" ";
}
int main()
{
	in_out_code();
	int v,e,w;
	cin>>v>>e;
	vector<pair<int,int>>adj[v];
	for(int i=0;i<e;i++)
	{
		int a,b,w;
		cin>>a>>b>>w;
		adj[a].push_back({b,w});
	}
	shortestpath(0,adj,v);
}