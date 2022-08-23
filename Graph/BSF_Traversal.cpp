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

vector<int>bsfGraph(int v,vector<int>adj[])
{
	vector<int>bsf;
	vector<int>vis(v+1,0);

	queue<int>q;
	for(int i=1;i<=v;i++)
	{
		if(!vis[i])
		{
			q.push(i);
			vis[i]=1;
		}
		while(!q.empty())
		{
			int node=q.front();
			q.pop();
			bsf.push_back(node);


			for(int itr:adj[node])
			{
				if(!vis[itr])
				{
					q.push(itr);
					vis[itr]=1;
				}
			}
		}
	}
	return bsf;

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

  vector<int>ar=	bsfGraph(v,adj);
  vector<int>::iterator ptr;
  for (ptr = ar.begin(); ptr < ar.end(); ptr++)
        cout << *ptr << " ";
      
}