#include<iostream>
#include<queue>
#include<vector>
using namespace std;
void in_out_code()
{
 #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
 #endif
}
void toposort(vector<int>adj[],int n)
{
	vector<int>indegree(n,0);
	queue<int>q;
	for(int i=0;i<n;i++)
	{
		for(auto itr:adj[i])
		{
			indegree[itr]++; 
		}
	}
	for(int i=0;i<n;i++)
	{
		if(indegree[i]==0)
			q.push(i);
	}
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		cout<<node<<" ";
		for(auto itr:adj[node])
		{
			indegree[itr]--;
			if(indegree[itr]==0)
			{
				q.push(itr);
				
			}
		}
	
	}
}

int main()
{
	//in_out_code();
	int v,e;
    cin>>v>>e;

	vector<int>adj[v];
	

	for(int i=0;i<e;i++)
	{
		int a,b;
        cin>>a>>b;
		adj[a].push_back(b);
	}
	toposort(adj,v);
}