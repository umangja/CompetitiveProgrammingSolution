/*input
3
3
1 2
2 3
1 3
4
1 2
2 3
3 4
4 2
5
1 2
2 3
1 3
2 5
4 3

*/
#include<bits/stdc++.h>
using namespace std;
set<int> cycle;
void dfs(int u,int p,vector<vector<int>> &adj,vector<int> &vis,vector<int> &cur)
{
	vis[u]=1;
	cur.push_back(u);
	// for(int i=0;i<cur.size();i++) cout<<cur[i]<<" ";cout<<"\n";
	for(int i=0;i<adj[u].size();i++)
	{
		int ch = adj[u][i];
		if(vis[ch]==0)
		{
			dfs(ch,u,adj,vis,cur);
		} 
		else if(ch!=p && vis[ch]==1 && (int)cycle.size()==0)
		{
			int j = 0;
			while(j<cur.size() && cur[j]!=ch) j++;		
			assert(j<cur.size());

			while(j<cur.size()) cycle.insert(cur[j++]);
		}
	}
	cur.pop_back();
	return ;
}

void dfs2(int u,int &cnt,vector<vector<int>> &adj,vector<int> &vis)
{
	vis[u]=1;
	cnt++;
	for(int i=0;i<adj[u].size();i++)
	{
		int ch = adj[u][i];
		if(vis[ch]==0 && cycle.find(ch)==cycle.end()) dfs2(ch,cnt,adj,vis);
	}
	return ;
}



int main()
{
	int T;cin>>T;
	while(T--)
	{
		cycle.clear();

		long long int n;cin>>n;
		vector< vector<int> > adj(n,vector<int> ());
		for(int i=0;i<n;i++)
		{
			int x,y;cin>>x>>y;
			x--,y--;
		
			adj[x].push_back(y);
			adj[y].push_back(x);
		
		}

		vector<int> vis(n,0);
		vector<int> cur;

		dfs(0,-1,adj,vis,cur);

		// for(auto it = cycle.begin();it!=cycle.end();it++) cout<<*it+1<<" "; cout<<"\n";

		vector<long long int> N;
		for(int i=0;i<n;i++) vis[i]=0;
		for(auto it = cycle.begin();it!=cycle.end();it++)
		{
			int cnt=0;
			dfs2(*it,cnt,adj,vis);
			N.push_back((long long int)(cnt-1));
		}

		// for(int i=0;i<N.size();i++) cout<<N[i]<<" "; cout<<"\n";

		long long int ans = 0,sum=0;
		long long int C = (long long int)N.size();
		// cout<<C<<"\n";
		for(int i=0;i<N.size();i++)
		{
			ans+=(N[i]*(N[i]-1))/2;
			ans-=N[i]*N[i];
			ans+=N[i]*(2*C-1);
			sum+=N[i];
		}

		ans+=sum*sum;
		ans+=C*(C-1);

		cout<<ans<<"\n";
	}
	return 0;
}
