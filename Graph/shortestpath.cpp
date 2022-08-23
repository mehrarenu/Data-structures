#include<iostream>
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
void shortpath(vector<int>adj[],int n,int src)
{
	queue<int>q;
	int dist[n];
 	dist[src]=0;
	for(int i=1;i<n;i++)
		dist[i]=32999999;
	q.push(src);
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(auto itr:adj[node])
		{
			if(dist[node]+1<dist[itr])
			{
				dist[itr]=dist[node]+1;
				q.push(itr);
			}
		}
	}
	for(int i=0;i<n;i++)
		cout<<dist[i]<<" ";

}
int main()
{
	in_out_code();
	int v,e,src=0;
    cin>>v>>e;

	vector<int>adj[v];


	for(int i=0;i<e;i++)
	{
		int a,b;
        cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	shortpath(adj,v,src);
}