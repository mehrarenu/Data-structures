#include<iostream>
#include<vector>
using namespace std;

void in_out_code()
{
 #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
 #endif
}

bool isCycle(int node,int prev,vector<int>&visit,vector<int>adj[])
{
	visit[node]=1;
	for(auto itr:adj[node])
	{
		if(visit[itr]!=0)
		{
			if(isCycle(itr,node,visit,adj))return true;
		}
		else if(itr!=prev)return true;
	}

	return false;
}
bool dfs(int v,vector<int>adj[])
{	
	vector<int>visit(v+1,0);
	
	for(int i=1;i<=v;i++)
	{
		if(!visit[i])
		if(isCycle(i,-1,visit,adj))return true;
	}
	return false;
	
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

    cout<<dfs(v,adj);
  	
    
}
