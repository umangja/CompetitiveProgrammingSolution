/*input
9
1 2
2 3
2 5
2 6
1 4
4 9
9 7
9 8

*/


//assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define pii         pair<ll int,ll int>
#define vppi        vector< pii >
#define vi          vector<ll int>
#define vs			vector< string >
#define vvi         vector< vector< ll > >
#define inf			1e18;
#define all(it,a)   for(auto it=(a).begin();it!=(a).end();it++) 
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define repr(i,a,b) for(ll int i=a;i>b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define graph(n)    adj(n,vector< ll > () )
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll const N = 2e5+5;
vvi graph(N);
vi s(N,1),dp(N,0);
ll ans=0;

void dfs(ll u,ll p)
{
	s[u]=1;
	dp[u]=0;
	rep(i,0,sz(adj[u]))
	{
		if(adj[u][i]==p)
			continue;
		dfs(adj[u][i],u);
		s[u]+=s[adj[u][i]];
		dp[u]+=dp[adj[u][i]];
	}
	dp[u]+=s[u];
	return ;
}

void dfs2(ll u,ll p)
{	

	rep(i,0,sz(adj[u]))
	{
		ll c = adj[u][i];
		if(c==p)
			continue;

		dp[u]-=dp[c];
		dp[u]-=s[c];
		s[u]-=s[c];
		s[c]+=s[u];
		dp[c]+=dp[u];
		dp[c]+=s[u];

		ans=max(dp[c],ans);

		dfs2(c,u);
		
		dp[c]-=s[u];
		dp[c]-=dp[u];
		s[c]-=s[u];
		s[u]+=s[c];
		dp[u]+=s[c];
		dp[u]+=dp[c];
	}
	return ;

}



int solve()
{
	ll n;cin>>n;
	rep(i,0,n-1)
	{
		ll x,y;cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	dfs(1,-1);
	ans=dp[1];
	dfs2(1,-1);

	cout<<ans;
	return 0;

}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll t=1;
	//cin>>t;
	while(t--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}