/*input
6 8
1 2
2 3
1 3
4 5
4 6
5 6
2 4
3 5

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
#define whatis(x)   cout << #x << " is " << x << "\n";
#define graph(n)    adj(n,vector< ll > () )
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll N = 1e5+5,M=3e5+5;
vvi graph(N),tree(N);
ll lvl[N];
ll dp[N];
ll vis[N];
ll nb=0;
map< pii,ll  > idx;
vpii ans(M,mp(-1,-1));

void dfs(ll u,ll p)
{
	dp[u]=0;
	rep(i,0,sz(adj[u]))
	{
		ll ch=adj[u][i];
		if(lvl[ch]==0)
		{
			lvl[ch]=lvl[u]+1;
			dfs(ch,u);
			dp[u]+=dp[ch];
		}
		else if(lvl[ch]<lvl[u]) dp[u]++;
		else if(lvl[ch]>lvl[u]) dp[u]--;
	}
	dp[u]--;
	if(p!=-1 && dp[u]==0)
		nb++;
}

void dfs2(ll u)
{
	vis[u]=1;
	rep(i,0,sz(adj[u]))
	{
		ll ch = adj[u][i];
		if(ans[idx[mp(u,ch)]].F==-1)
			ans[idx[mp(u,ch)]]=mp(u,ch);
		if(vis[ch]==0)
			dfs2(ch);
	}
}

int solve()
{
	ll n,m;cin>>n>>m;
	rep(i,0,m)
	{
		ll x,y;cin>>x>>y;x--;y--;
		adj[x].pb(y);
		adj[y].pb(x);
		idx[mp(x,y)]=i;
		idx[mp(y,x)]=i;
	}
	lvl[0]=1;
	dfs(0,-1);

	if(nb!=0)
		cout<<"0";
	else
	{
		dfs2(0);
		rep(i,0,m)
			cout<<ans[i].F+1<<" "<<ans[i].S+1<<"\n";
	}

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
// 	cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}