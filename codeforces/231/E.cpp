/*input
14 16
1 14
1 2
2 3
3 4
4 5
5 1
6 5
10 9
9 12
11 12
11 10
7 9
8 7
8 13
6 8
7 6
10
14 1
14 12
10 12
7 9
7 5
9 5
1 6
13 8
13 11
1 13
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
const ll N = 2e5+5,lim = (ll)ceil(log2(N)),mod=1e9+7;
vvi adj(N,vector< ll > ()),tree(N,vi ());
set< pii > bdg;
ll timer=0;
ll tin[N],low[N],lvl[N],vis[N],comp[N],color[N],freq[N],cnt[N],tin2[N],tout2[N],power_2[N];
ll up[N][lim];
ll n,m;

void preprocess()
{
	power_2[0]=1;
	rep(i,1,N) power_2[i] = (power_2[i-1]*2)%mod;
}

void dfs0(ll u,ll p=-1)
{	
	tin[u]=low[u]=++timer;
	rep(i,0,sz(adj[u]))
	{
		ll ch = adj[u][i];
		if(ch==p) continue;
		if(lvl[ch]==0)
		{
			lvl[ch]=lvl[u]+1;
			dfs0(ch,u);
			low[u]=min(low[u],low[ch]);
			if(low[ch]>tin[u])
				bdg.insert(mp(ch,u)),bdg.insert(mp(u,ch));
		}
		else  low[u]=min(low[u],tin[ch]);
	}
}

void dfs1(ll u,ll c_no)
{
	vis[u]=1;
	comp[u]=c_no;
	rep(i,0,sz(adj[u]))
	{
		ll ch = adj[u][i];
		if(vis[ch]==0 && bdg.find(mp(ch,u))==bdg.end())
			dfs1(ch,c_no);
	}
}

void build()
{
	all(it,bdg)
	{
		tree[comp[it->F]].pb(comp[it->S]);
		// cout<<comp[it->F]<<" "<<comp[it->S]<<"\n";
	}
}

void colour()
{
	rep(i,0,N)
		freq[comp[i]]++;
	rep(i,0,N)
		if(freq[comp[i]]==1) 
			color[comp[i]]=1;
}

void calculate(ll u,ll p)
{
	vis[u]=1;
	cnt[u]=(color[u]==0)+(p==-1?0:cnt[p]);
	rep(i,0,sz(tree[u]))
	{
		if(vis[tree[u][i]]==0)
			calculate(tree[u][i],u);
	}
}

void dfs2(ll u,ll p)
{
	tin2[u]=++timer;
	vis[u]=1;
	up[u][0]=p;
	for(ll k=1;k<lim;k++)
		up[u][k]=up[up[u][k-1]][k-1];
	rep(i,0,sz(tree[u]))
	{
		if(vis[tree[u][i]]==0) dfs2(tree[u][i],u);
	}
	tout2[u]=++timer;
}

bool is_ances(ll u,ll v)
{
	return tin2[u]<=tin2[v] && tout2[u]>=tout2[v];
}

ll find_lca(ll u,ll v)
{
	if(is_ances(u,v)) return u;
	if(is_ances(v,u)) return v;

	for(ll k=lim-1;k>=0;k--)
	{
		if(!is_ances(up[u][k],v))
			u=up[u][k];
	}

	return up[u][0];
}

int solve()
{
	cin>>n>>m;
	rep(i,0,m)
	{
		ll x,y;cin>>x>>y;
		x--,y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	lvl[0]=1;
	dfs0(0,-1);

	ll cnti=n;
	rep(i,0,n)
		if(vis[i]==0)
			dfs1(i,cnti++);

	build();
	colour();
	// rep(i,0,2*n) cout<<i<<" "<<color[i]<<"\n";

	rep(i,0,N) vis[i]=0;
	calculate(n,-1);
	// rep(i,n,cnti) cout<<cnt[i]<<" ";

	timer=0;
	rep(i,0,N) vis[i]=0;
	dfs2(comp[0],comp[0]);

	preprocess();

	ll q;cin>>q;
	while(q--)
	{
		ll a,b;cin>>a>>b;a--,b--;
		a=comp[a];
		b=comp[b];

		ll lca = find_lca(a,b);
		
		// cout<<lca<<" "<<b<<"\n";
		ll ans = cnt[a]+cnt[b]-2*cnt[lca]+(color[lca]==0);
		cout<<power_2[ans]<<"\n";
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
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}