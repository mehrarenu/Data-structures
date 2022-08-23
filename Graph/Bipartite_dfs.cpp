#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

void in_out_code()
{
 #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 #endif
}
bool isBipartite(int node,vector<int>adj[],int color[])
{
	if(color[node]==-1)
	color[node]=1;
	for(auto itr:adj[node])
	{
		if(color[itr]==-1)
		{
			color[itr]=1-color[node];
			if(!isBipartite(itr,adj,color))
			{
				return false;
			}
		}else if(color[itr]==color[node]) return false;
	}
	return true;
}

bool checkBipartite(int n,vector<int>adj[])
{
	int color[n];
	memset(color,-1,sizeof color);
	for(int i=1;i<=n;i++)
	{
		if(color[i]==-1)
		{
			if(!isBipartite(n,adj,color))
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
	int a,b;
	vector<int>adj[v+1];
	for(int i=0;i<e;i++)
	{
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cout<<checkBipartite(v,adj);


}