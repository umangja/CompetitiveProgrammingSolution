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
const ll N = 5e5+5;
vvi adj(N,vi ());
vi top;
vi vis(N,0),vis2(N,0),dp(N,0);
vi vis3(N,0);


ll is_cycle=0;
void dfs(ll u)
{
	// whatis(u);
	vis[u]=1;
	vis2[u]=1;
	rep(i,0,sz(adj[u]))
	{
		ll ch  = adj[u][i];
		if(vis2[ch]==1)
		{
			is_cycle=1;
			break;
		} 
		if(vis[ch]==0) dfs(ch);
	}
	top.pb(u);
	vis2[u]=0;
	return ;
}

void dfs2(ll u)
{
	// whatis(u);
	vis3[u]=1;
	rep(i,0,sz(adj[u]))
	{
		ll ch = adj[u][i];
		dp[u]=max(dp[u],dp[ch]+1);
		if(vis3[ch]==0) dfs2(ch);
	}

	// cout<<u<<" "<<dp[u]<<"\n";
	return ;
}



int solve()
{
	ll n;cin>>n;
	map<pii,ll> m;
	ll cnt=0;
	rep(x,0,n) rep(y,x+1,n) m[mp(x,y)]=cnt,m[mp(y,x)]=cnt,cnt++; 
	rep(i,0,n)
	{
		ll prev = -1;
		rep(j,0,n-1)
		{
			ll x;cin>>x;
			x--;
			if(prev!=-1) adj[prev].pb(m[mp(i,x)]);
			prev=m[mp(i,x)];
		}
	}

	rep(i,0,cnt)
	{
		if(vis[i]==0) dfs(i);
		if(is_cycle==1) break;
	} 
	if(is_cycle==1)
	{
		cout<<"-1\n";
		return 0;
	}
	// rep(i,0,sz(top)) cout<<top[i]<<" ";
	// reverse(top.begin(), top.end());
	rep(i,0,sz(top)) if(vis3[top[i]]==0) dfs2(top[i]);

	ll ans=0;
	rep(i,0,cnt) ans=max(ans,dp[i]);
	cout<<ans+1<<"\n";



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