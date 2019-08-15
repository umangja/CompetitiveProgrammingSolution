/*input
10
0 1 2 1 4 4 4 0 8
0 0 0 1 0 1 1 0 0 1


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
const ll N = 1e5+5,mod=1e9+7;
vvi graph(N);
ll col[N];
ll dp[2][N];
void dfs(ll u,ll p)
{
	dp[0][u]=col[u],dp[1][u]=1-col[u];
	rep(i,0,sz(adj[u]))
	{
		ll ch=adj[u][i];
		if(ch==p) continue;
		dfs(ch,u);
		ll temp1=0,temp2=0;
		temp1+=(dp[1][ch]*dp[1][u])%mod;//white
		temp1+=(dp[1][u]*dp[0][ch])%mod;
		temp2+=((dp[0][u]*dp[1][ch])%mod+dp[0][ch]*dp[1][u])%mod;
		temp2+=(dp[0][ch]*dp[0][u])%mod;
		dp[0][u]=temp2%mod;
		dp[1][u]=temp1%mod;
	}
	return;
}
int solve()
{
	ll n;cin>>n;
	rep(i,1,n)
	{
		ll x;cin>>x;
		adj[i].pb(x);
		adj[x].pb(i);
	}
	rep(i,0,n) cin>>col[i];
	dfs(0,0);
	cout<<dp[0][0];
	// cout<<"\n"<<1352857633%mod<<"\n";
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