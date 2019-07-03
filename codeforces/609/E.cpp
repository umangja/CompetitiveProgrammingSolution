/*input
5 7
1 2 3
1 3 1
1 4 5
2 3 2
2 5 3
3 4 2
4 5 4
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
#define graph(n)    adj(n,vector< ll > () )
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll N = 2e5+5;
// vvi graph(N);
vvi tree(N,vector< ll > ());
vi tin(N,0),tout(N,0),depth(N,0);
ll timer=0;
ll L = (ll)ceil(log2(N));
vvi up(N,vector< ll > (L,0));
vvi maxd(N,vector< ll > (L,0));

map<pii,ll> wm;
vpii subset(N);

void dfs(ll v,ll p, ll cost)
{
	tin[v]=++timer;
	up[v][0]=p;
 	maxd[v][0]=cost;
 	for(ll i=1;i<L;i++)
 	{
 		up[v][i]=up[up[v][i-1]][i-1];
 		maxd[v][i]=max(maxd[up[v][i-1]][i-1],maxd[v][i-1]);
 	}

	rep(i,0,sz(tree[v]))
	{
		if(tree[v][i]==p)
			continue;

		depth[tree[v][i]]=depth[v]+1;
		ll tcost = wm[mp(v,tree[v][i])];
		dfs(tree[v][i],v,tcost);
	}

	tout[v]=++timer;
	return;
}

bool is_ancestor(ll u,ll v)
{
	return (tin[u]<=tin[v] && tout[u]>=tout[v]);
}

ll lca(ll u,ll v)
{
	if(is_ancestor(u,v))
		return u;
	else if(is_ancestor(v,u))
		return v;
	else
	{
		for(ll i=L-1;i>=0;i--)
		{
			if(!is_ancestor(up[u][i],v))
				u=up[u][i];
		}

		return up[u][0];
	}
}

void init()
{
	rep(i,0,N)
	{
		subset[i] = mp(i,0);
	}
}

ll find_parent(ll x)
{
	if(subset[x].F!=x)
		return subset[x].F=find_parent(subset[x].F);
	return x;
}

void merge(ll x,ll y)
{
	ll x_p = find_parent(x);
	ll y_p = find_parent(y);

	if(subset[x_p].S<subset[y_p].S)
		subset[x_p].F=y_p;
	else if(subset[y_p].S<subset[x_p].S)
		subset[y_p].F=x_p;
	else
	{
		subset[y_p].F=x_p;
		subset[y_p].S++;
	}
	return;
}

ll get_max(ll u,ll dep)
{
	ll j=0;
	for(ll i=L-1;i>=0;i--)
	{
		if(dep&1<<i)
		{
			j=max(j,maxd[u][i]);
			u=up[u][i];
		}
	}

	return j;
}

int solve()
{
	init();
	ll n,m;cin>>n>>m;
	vector< pair< ll,pair< ll,ll > > > edges,edges1;
	rep(i,0,m)
	{
		ll x,y,w;cin>>x>>y>>w;
		edges.pb(mp(w,mp(x,y)));
		edges1.pb(mp(w,mp(x,y)));
	}

	sort(edges1.begin(), edges1.end());

	ll cost=0;
	for(ll i=0;i<m;i++)
	{
		ll w = edges1[i].F;pii p = edges1[i].S;
		ll x = find_parent(p.F);
		ll y = find_parent(p.S);

		if(x==y)
			continue;

		tree[p.F].pb(p.S);
		tree[p.S].pb(p.F);

		wm[p]=w;
		wm[mp(p.S,p.F)]=w;
		
		merge(p.S,p.F);
		cost+=w;
	}

	dfs(1,1,0);

	// rep(i,1,n+1)
	// 	cout<<depth[i]<<" ";
	// cout<<"\n";
	rep(i,0,m)
	{
		if(wm.find(edges[i].S)!=wm.end())
		{
			cout<<cost<<"\n";
			continue;
		}

		ll u = edges[i].S.F;
		ll v = edges[i].S.S;

		ll lc = lca(u,v);

		ll j=0;
		j=max(j,get_max(u,depth[u]-depth[lc]));
		j=max(j,get_max(v,depth[v]-depth[lc]));

		cout<<cost-j+edges[i].F<<"\n";

	}

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