/*input
5 5
1 2
2 3
3 1
4 1
5 2

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
const ll N = 3e5+5;
vvi graph(N),tree(N);
vpii bdg;
set< pii > s;
ll lvl[N];
ll dp[N];
ll vis[N];
ll p[N],rk[N];
ll f[N],g[N];
ll ansf=-1;
ll st=0;

void init()
{
	rep(i,0,N)	rk[i]=1,p[i]=i;	
}

ll find_parent(ll x)
{
	return (p[x]==x?x:p[x]=find_parent(p[x]));
}

void merge(ll x,ll y)
{
	ll xp = find_parent(x);
	ll yp = find_parent(y);
	if(xp==yp) return ;
	if(rk[xp]>rk[yp]) swap(xp,yp);
	p[xp]=yp;
	rk[yp]+=rk[xp];
}

void dfs(ll u,ll par)
{
	dp[u]=0;
	rep(i,0,sz(adj[u]))
	{
		ll ch = adj[u][i];
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
		bdg.pb(mp(u,par));
		s.insert(mp(u,par));
		s.insert(mp(par,u));
	}
}

void dfs2(ll u)
{
	vis[u]=1;
	rep(i,0,sz(adj[u]))
	{
		ll ch = adj[u][i];
		if(vis[ch]==0 && s.find(mp(u,ch))==s.end())
		{
			merge(u,ch);
			dfs2(ch);
		}
	}
}

void build()
{
	rep(i,0,sz(bdg))
	{
		ll x = find_parent(bdg[i].F);
		ll y = find_parent(bdg[i].S);
		// cout<<x<<" "<<y<<"\n";
		st=x;
		tree[x].pb(y);
		tree[y].pb(x);
	}
}

void dfs1(ll u)
{
	vis[u]=1;
	vi arr;
	rep(i,0,sz(tree[u]))
	{
		ll ch =tree[u][i];
		if(vis[ch]==0) {dfs1(ch);arr.pb(f[ch]);}
	}

	f[u]=0;
	sort(arr.begin(), arr.end());
	if(sz(arr)>=1) f[u]=1+arr[sz(arr)-1];
	if(sz(arr)>=2) g[u]=2+arr[sz(arr)-1]+arr[sz(arr)-2];
	ansf=max(ansf,max(f[u],g[u]));
}


int solve()
{
	ll n,m;cin>>n>>m;
	rep(i,0,m)
	{
		ll x,y;cin>>x>>y;
		x--;y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	init();
	lvl[0]=1;
	dfs(0,-1);
	rep(i,0,n) if(vis[i]==0) dfs2(i);
	build();
	rep(i,0,N) vis[i]=0;
	dfs1(st);

	cout<<ansf;
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