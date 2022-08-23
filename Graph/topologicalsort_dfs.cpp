#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void in_out_code()
{
 #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
 #endif
}
void findTopSort(int node,vector<int>&visit,stack<int>&s,vector<int>adj[])
{
	visit[node]=1;
	for(auto itr:adj[node])
	{
		if(!visit[itr])
		{
			findTopSort(itr,visit,s,adj);
		}
	}
	s.push(node);
}

vector<int>toposort(int n, vector<int>adj[])
{
	vector<int>visit(n,0);
	stack<int>s;
	vector<int>topo;
	for(int i=0;i<n;i++)
	{
		if(!visit[i])
			findTopSort(i,visit,s,adj);
	}
	while(!s.empty())
	{
		topo.push_back(s.top());
		s.pop();
	}
	return topo;
}

int main()
{
 in_out_code();
	int v,e;
    cin>>v>>e;

	vector<int>adj[v];
	

	for(int i=0;i<e;i++)
	{
		int a,b;
        cin>>a>>b;
		adj[a].push_back(b);
	}
	vector<int>topo;
	topo=toposort(v,adj);
	for(auto i:topo)
		cout<<i<<" ";
}