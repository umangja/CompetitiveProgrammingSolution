/*input

*/


//assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define pii         pair<ll int,ll int>
#define vpii        vector< pii >
#define vi          vector<ll int>
#define vs			vector< string >
#define vvi         vector< vector< ll > >
#define inf			(ll)1e18
#define all(it,a)   for(auto it=(a).begin();it!=(a).end();it++) 
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define repr(i,a,b) for(ll int i=a;i>b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define whatis(x)   cout << #x << " is " << x << "\n";
#define graph(n)    adj(n,vector< ll > () )
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll N = 2e5+5,mod = 1e9+7;
vi dp(N,0),ans(N,0),siz(N,0),fact(N,1),fact_inv(N,1);
vvi adj(N,vi ());
ll n;



ll power(ll x,ll y)
{
	ll anst=1;
	while(y)
	{
		if(y&1) anst = (anst*x)%mod;
		y>>=1;
		x=(x*x)%mod;
	}
	return anst;
}
		

void dfs(ll u,ll p)
{
	siz[u]=1;
	dp[u]=1;
	for(ll i=0;i<sz(adj[u]);i++)
	{
		ll ch = adj[u][i];
		if(ch==p) continue;


		dfs(ch,u);
		siz[u]+=siz[ch];
		dp[u] = (dp[u]*dp[ch])%mod;
		dp[u] = (dp[u]*fact_inv[siz[ch]])%mod;
	}

	dp[u] = (dp[u]*fact[siz[u]-1])%mod;
	return ;
}

void dfs2(ll u,ll p=-1)
{
	if(p==-1) ans[u]=dp[u];
	rep(i,0,sz(adj[u]))
	{
		ll ch = adj[u][i];
		if(ch==p) continue;


		ll temp = (ans[u]*fact_inv[n-1])%mod;
		temp = (temp*fact[siz[ch]])%mod;
		temp = (temp*power(dp[ch],mod-2))%mod;
		temp = (temp*fact[n-siz[ch]-1])%mod;
		


		ans[ch] = dp[ch];
		ans[ch] = (ans[ch]*temp)%mod;
		ans[ch] = (ans[ch]*fact_inv[n-siz[ch]])%mod;
		ans[ch] = (ans[ch]*fact[n-1])%mod;
		ans[ch] = (ans[ch]*fact_inv[siz[ch]-1])%mod;
		// ans[ch] = (ans[ch]*fact_inv[siz[ch]-1])%mod;


		dfs2(ch,u);
	}

	return ;
}


int solve()
{

	// ll k = (2*power(500,mod-2))%mod;
	// k = (k*500)%mod;
	// whatis(k);

	rep(i,1,N) fact[i] = (fact[i-1]*i)%mod,fact_inv[i] = (fact_inv[i-1]*power(i,mod-2))%mod;
	cin>>n;
	rep(i,0,n-1)
	{
		// adj[i].pb(i+1);
		// adj[i+1].pb(i);

		ll x,y;cin>>x>>y;
		x--,y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	dfs(0,-1);
	dfs2(0,-1);


	rep(i,0,n) cout<<ans[i]<<"\n";
	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll test_cases=1;
	//cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}