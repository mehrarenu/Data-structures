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

bool cycleDetect(int i,int v,vector<int>&visit,vector<int>adj[])
{
	queue<pair<int,int>>q;
	visit[i]=true;
	q.push({i,-1});

	while(!q.empty())
	{
		int node=q.front().first;
		int prev=q.front().second;
		q.pop();
		for(auto itr:adj[node])
		{
			if(!visit[itr])
			{
				visit[itr]=true;
				q.push({itr,node});
			}
			else if(itr!=prev)
				return true;
		}
	}
	return false;
}


bool isCycle(int v,vector<int>adj[])
{
	vector<int>visit(v+1,0);
	for(int i=1;i<=v;i++)
	{
		if(!visit[i])
		{
			if(cycleDetect(i,v,visit,adj))
				return true;
		
	
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
		adj[b].push_back(a);
	}

    cout<<isCycle(v,adj);
  	
  }