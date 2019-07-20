/*input
3 3
1 2 0
2 3 0
3 1 1
2 2
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
#define graph(n)    adj(n,vector< pii >())
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll N = 3e5+5;
vector< vector< pii > > graph(N),tree(N,vector< pii >());
vpii bdg;
set< pii > s;
ll lvl[N];
ll dp[N];
ll vis[N];
ll p[N],rk[N];
ll f[N];
map< pair< ll,ll >,ll > edges;
ll a,b;

void init()
{
	rep(i,0,N) p[i]=i,rk[i]=1;
}

ll find_parent(ll x)
{
	return (p[x]==x?x:p[x]=find_parent(p[x]));
}

void merge(ll x,ll y)
{
	x = find_parent(x);
	y = find_parent(y);
	if(x==y) return ;
	if(rk[x]>rk[y]) swap(x,y);
	p[x]=y;
	rk[y]+=rk[x];
}

void dfs(ll u,ll par)
{
	dp[u]=0;
	rep(i,0,sz(adj[u]))
	{
		ll ch = adj[u][i].F;
		if(lvl[ch]==0)
		{
			lvl[ch]=lvl[u]+1;
			dfs(ch,u);
			dp[u]+=dp[ch];
		}
		else if(lvl[u]<lvl[ch]) dp[u]--;
		else if(lvl[u]>lvl[ch]) dp[u]++;
	}
	dp[u]--;
	if(par!=-1 && dp[u]==0){
		// cout<<"YES";
		bdg.pb(mp(u,par));
		s.insert(mp(u,par));
		s.insert(mp(par,u));
	}
}

void dfs1(ll u)
{	
	vis[u]=1;
	rep(i,0,sz(adj[u]))
	{
		ll ch = adj[u][i].F;
		if(s.find(mp(ch,u))==s.end())
		{
			ll yes=0;
			if(adj[u][i].S==1 || f[find_parent(ch)]==1 || f[find_parent(u)]==1)
				yes=1;
			merge(ch,u);
			if(yes) f[find_parent(u)]=1;
		}
		if(vis[ch]==0 && s.find(mp(ch,u))==s.end())
			dfs1(ch);
	}
}

void build()
{
	rep(i,0,sz(bdg))
	{
		ll x = find_parent(bdg[i].F);
		ll y = find_parent(bdg[i].S);
		ll fthis = edges[mp(bdg[i].F,bdg[i].S)];
		tree[x].pb(mp(y,fthis));
		tree[y].pb(mp(x,fthis));
	}
}

bool dfs3(ll u,ll st)
{
	vis[u]=1;
	if(f[u]==1)
		st|=1;

	if(u==b)
		return st;

	rep(i,0,sz(tree[u]))
	{
		ll ch = tree[u][i].F;
		if(vis[ch]==0)
		{
			ll dup=st;
			if(tree[u][i].S==1)
				dup|=1;
			if(dfs3(ch,dup))
				return true;
		}
	}

	return false;
}

// void dfs2(ll u)
// {
// 	vpii arr;
// 	vis[u]=1;
// 	rep(i,0,sz(tree[u]))
// 	{
// 		ll ch = tree[u][i];
// 		if(vis[ch]==0)
// 		{
// 			dfs2(ch);
// 			arr.pb(f[ch]);
// 		}
// 	}

// 	sort(arr.begin(), arr.end(),greater< pii > ());
// 	f[u]=mp(0,u);
// 	if(sz(arr)>=1) f[u].F=1+arr[0].F,f[u].S=arr[0].S;
// 	if(sz(arr)>=2)
// 	{ 
// 		g[u]=2+arr[0].F+arr[1].F;
// 		if(g[u]>ansf1) ansf1=g[u],ansf2=arr[0].S,ansf3=arr[1].S;
// 	}
// 	else
// 	{
// 		if(ansf1<f[u].F) ansf1=f[u].F,ansf2=f[u].S,ansf3=u;
// 	}

// }

int solve()
{
	ll n,m;cin>>n>>m;
	rep(i,0,m)
	{
		ll x,y,z;cin>>x>>y>>z;
		x--;y--;
		edges[mp(x,y)]=z;
		edges[mp(y,x)]=z;

		adj[x].pb(mp(y,z));
		adj[y].pb(mp(x,z));
	}

	init();
	lvl[0]=1;
	dfs(0,-1);
	rep(i,0,n) if(vis[i]==0) dfs1(i);
	// rep(i,0,n) cout<<p[i]<<" "<<f[i]<<"\n";

	build();
	rep(i,0,N) vis[i]=0;
	cin>>a>>b;a--;b--;
	a=find_parent(a);
	b=find_parent(b);
	if(dfs3(a,0)) cout<<"YES";
	else cout<<"NO";
	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll test_cases=1;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}