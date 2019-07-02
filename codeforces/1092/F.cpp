/*input
2
12345 65432
2 1

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
#define inf			1e18
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
const ll N = 2e5+5;
vi a(N,0);
vvi graph(N);
vi dp(N,0),sum(N,0);
ll ans=0,cost=0;

void dfs(ll u,ll p,ll d)
{
	sum[u]=a[u];
	rep(i,0,sz(adj[u]))
	{
		ll ch = adj[u][i];
		if(ch==p)
			continue;

		dfs(ch,u,d+1);
		sum[u]+=sum[ch];
		ans+=a[ch]*(d+1);
	}

	return ;
}

void dfs2(ll u,ll p)
{
	rep(i,0,sz(adj[u]))
	{
		ll ch = adj[u][i];
		if(ch==p)
			continue;

		sum[u]-=sum[ch];
		ans-=sum[ch];
		sum[ch]+=sum[u];
		ans+=sum[u];

		cost=max(cost,ans);
		dfs2(ch,u);

		ans-=sum[u];
		sum[ch]-=sum[u];
		ans+=sum[ch];
		sum[u]+=sum[ch];

	}

	return ;
}

int solve()
{
	ll n;cin>>n;
	rep(i,1,n+1)
		cin>>a[i];

	rep(i,0,n-1)
	{
		ll x,y;cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	dfs(1,-1,0);
	cost=ans;
	dfs2(1,-1);
	cout<<cost;
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