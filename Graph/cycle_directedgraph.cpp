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
bool isCycle(int node,vector<int>&visit,vector<int>&dfsvis,vector<int>adj[])
{
	visit[node]=1;
	dfsvis[node]=1;
	for(auto itr:adj[node])
	{
		if(!visit[itr])
		{
			if(isCycle(itr,visit,dfsvis,adj))return true;
		}else if(dfsvis[itr])return true;
	}
	dfsvis[node]=0;
	return false;
}
bool checkCycle(int v,vector<int>adj[])
{	
	vector<int>visit(v+1,0);
	vector<int>dfsvis(v+1,0);
	
	for(int i=0;i<=v;i++)
	{
		if(!visit[i])
		{
		if(!isCycle(i,visit,dfsvis,adj))return true;
		}
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
	}

    cout<<checkCycle(v,adj);
  	
    
}