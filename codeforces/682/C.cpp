/*input
9
88 22 83 14 95 91 98 53 11
3 24
7 -8
1 67
1 64
9 65
5 12
6 -80
3 8
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

const ll N = 1e5+5;
ll vis[N],ans=0;
ll max_dist[N];
ll siz[N];
ll sad[N];
ll a[N];
vvi graph(N);
map<pii,ll> edges;

void dfs1(ll u,ll p)
{
	siz[u]=1;
	rep(i,0,sz(adj[u])) if(adj[u][i]!=p) dfs1(adj[u][i],u),siz[u]+=siz[adj[u][i]];
}

void dfs(ll v,ll p)
{
	vis[v]=1;
	if(p==-1) max_dist[v]=0;
	else max_dist[v]=max(max_dist[p]+edges[mp(p,v)],(ll)0);

	if(max_dist[v]>a[v]) 
	{
		sad[v]=1;
		return ;
	}


	rep(i,0,sz(adj[v]))
	{
		if(vis[adj[v][i]]==0) dfs(adj[v][i],v);
	} 
}

int solve()
{
	ll n;cin>>n;
	rep(i,0,n) cin>>a[i];
	rep(i,0,n-1)
	{
		ll x;cin>>x;x--;
		ll y=i+1;
		ll p;cin>>p;
		adj[x].pb(y);
		adj[y].pb(x);
		edges[mp(x,y)]=p;
		edges[mp(y,x)]=p;
	}
	dfs1(0,-1);
	dfs(0,-1);
	rep(i,0,n) if(sad[i]==1){ans+=siz[i];}
	cout<<ans;
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