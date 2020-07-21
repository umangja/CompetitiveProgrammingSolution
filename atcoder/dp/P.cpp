/*input
10
8 5
10 8
6 5
1 5
4 8
2 10
3 6
9 2
1 7
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5,mod=1e9+7; 
int dp[N][2];
vector<int> g[N];
int fun(int u,int p,int col)
{
	if(dp[u][col]!=-1) return dp[u][col];
	long long int ans = 1;
	for(int i=0;i<(int)g[u].size();i++)
	{
		int ch = g[u][i];
		if(ch==p) continue;
		long long int temp = 0;
		if(col==1) 
		{
			temp+=fun(ch,u,col);
			temp+=fun(ch,u,col^1);
			temp%=mod;
		}
		else
		{
			temp+=fun(ch,u,1);
			temp%=mod;
		}
		ans*=temp;
		ans%=mod;
	}

	return dp[u][col]=(int)ans;
}


int main()
{
	memset(dp,-1,sizeof dp);
	int n;cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int x,y;cin>>x>>y;
		x--,y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}


	cout<<(fun(0,-1,0)+fun(0,-1,1))%mod<<"\n";



	return 0;
}
