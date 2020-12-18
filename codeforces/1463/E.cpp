/*input
5 1
2 3 0 5 3
4 5

     3
   2   5
 1 		4




*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> p;
vector<int> par;
vector<int> vis;
vector<int> rig,lef;
stack<int> st;


int findParent(int x)
{
	if(par[x]==x) return x;
	return par[x]=findParent(par[x]);
}

void merge(int x,int y)
{
	x = findParent(x);
	y = findParent(y);

	if(x==y) return ;
	par[x]=y;
}

void dfs(int x)
{
	vis[x]=1;
	for(int i=0;i<adj[x].size();i++)
	{
		int ch = adj[x][i];
		ch = findParent(ch);
		if(vis[ch]==0) dfs(ch);
	}
	st.push(x);
	return ;
}



int main()
{
	int T = 1; // cin>>T;
	while(T--)
	{
		int n,m;cin>>n>>m;
		p.clear(); p.resize(n);
		par.clear(); par.resize(n);
		adj.clear(); adj.resize(n,vector<int> ());
		vis.clear(); vis.assign(n,0);
		rig.clear(); rig.assign(n,-1);
		lef.clear(); lef.assign(n,-1);
		while(!st.empty()) st.pop();

		for(int i=0;i<n;i++) par[i]=i;

		for(int i=0;i<n;i++) 
		{
			int x;cin>>x;
			p[i]=(--x);
			par[i]=i;
		}

		for(int i=0;i<m;i++)
		{
			int x,y;cin>>x>>y;
			x--,y--;
			rig[x]=y;
			lef[y]=x;
			merge(x,y);
		}

		for(int i=0;i<n;i++)
		{
			if(p[i]!=-1)
			{
				// cout<<i<<" "<<p[i]<<"\n";
				int x = findParent(i);
				int y = findParent(p[i]);

				adj[y].push_back(x);
			}
		}

		for(int i=0;i<n;i++)
		{
			int x = findParent(i);
			if(vis[x]==0) dfs(x);
		}


		vector<int> top;
		while(!st.empty()) top.push_back(st.top()),st.pop();

		// {
		// 	cout<<"Topological Sorting is :- ";
		// 	for(int i=0;i<top.size();i++) cout<<top[i]+1<<" "; cout<<"\n";
		// }

		// {
		// 	for(int i=0;i<n;i++) cout<<lef[i]<<" "; cout<<"\n";
		// 	for(int i=0;i<n;i++) cout<<rig[i]<<" "; cout<<"\n";
		// }

		int pos=1;
		vector<int> ans;
		for(int i=0;i<top.size();i++)
		{
			int x = top[i];
			while(lef[x]!=-1 && lef[x]!=top[i]) x=lef[x];
			if(lef[x]==top[i]) 
			{ 
				pos=0; 
				break;
			}
			else 
			{
				while(rig[x]!=-1)
				{
					ans.push_back(x);
					x=rig[x];
				} 
				ans.push_back(x);
			}	
		}

		if(!pos) cout<<"0";
		else
		{
			for(int i=0;i<n;i++) vis[i]=0;
			for(int i=0;i<n;i++)
			{
				if(p[ans[i]]!=-1 && vis[p[ans[i]]]==0) pos=0;  
				vis[ans[i]]=1;
			} 
			if(!pos) cout<<"0";
			else for(int i=0;i<n;i++) cout<<ans[i]+1<<" ";
		} 
		cout<<"\n";
	}
	return 0;
}
