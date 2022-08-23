#include<iostream>
#include<vector>
using namespace std;

void dfsGraph(int node,vector<int>&visit,vector<int>adj[])
{
	visit[node]=1;
	cout<<node<<" ";
	for(int itr:adj[node])    
	{
		if(!visit[itr])
			dfsGraph(itr,visit,adj);
	}
}
void dfs(int v,vector<int>adj[])
{	
	vector<int>visit(v+1,0);
	
	for(int i=1;i<=v;i++)
	{
		if(!visit[i])
		dfsGraph(i,visit,adj);
	}
	
}

int main()
{
	int v,e;
	cout<<"enter vertices : ";
	cin>>v;
	cout<<"\nenter edges : ";
	cin>>e;

	vector<int>adj[v+1];
	

	for(int i=0;i<e;i++)
	{
		int a,b;
		cout<<"\nenter vertex : ";
		cin>>a;
		cout<<"\nenter adjacent vertex : ";
		cin>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

    dfs(v,adj);
  	
    
}