/*input
4 5
1 2
1 3
3 2
2 4
3 4
*/
#include<bits/stdc++.h>
using namespace std;

void dfs(int u,vector<int> &vis,vector<int> &dp,vector<vector<int>> &g)
{
	// cout<<u<<"\n";
	vis[u]=1;
	dp[u]=0;
	for(int i=0;i<g[u].size();i++)
	{
		if(vis[g[u][i]]==0) dfs(g[u][i],vis,dp,g); 
		dp[u]=max(dp[u],1+dp[g[u][i]]);
	} 
	return ;	
}

int main()
{
	int n,m;cin>>n>>m;
	vector<vector<int>> g(n,vector<int> ());
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		x--,y--;
		g[x].push_back(y);
	}


	vector<int> dp(n,0);
	vector<int> vis(n,0);

	for(int i=0;i<n;i++) if(vis[i]==0) dfs(i,vis,dp,g);
	// for(int i=0;i<n;i++) cout<<dp[i]<<" ";
	cout<<*max_element(dp.begin(), dp.end());
	return 0;
}
