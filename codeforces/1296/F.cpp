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
const ll N = 5e3+5;
ll n;
vvi adj(N,vi ());
vi parent(N,-1);
vector< vi > edge(N,vi (N,-1));
vi f_val(N,-1);

void dfs(ll u,ll f,ll p)
{
	parent[u]=p;
	if(u==f) return ;
	rep(i,0,sz(adj[u])) if(adj[u][i]!=p) dfs(adj[u][i],f,u);
	return ;
}

void find_path(ll u,ll f,ll val)
{
	rep(i,0,n) parent[i]=-1;
	dfs(u,f,-1);
	while(parent[f]!=-1)
	{
		ll p = parent[f];
		f_val[edge[p][f]]=val;
		f=p;
	}
	return ;
}

ll check_path(ll u,ll f,ll val)
{
	rep(i,0,n) parent[i]=-1;
	dfs(u,f,-1);
	ll at_l=0;
	while(parent[f]!=-1)
	{
		ll p = parent[f];
		if(f_val[edge[p][f]]==val) { at_l=1; break;}
		f=p;
	}
	return at_l;
}

int solve()
{
	cin>>n;
	rep(i,0,n-1)
	{
		ll x,y;cin>>x>>y;
		x--,y--;
		adj[x].pb(y);
		edge[x][y]=i;
		adj[y].pb(x);
		edge[y][x]=i;
	}

	ll m;cin>>m;
	vector< pair< ll,pii > > q(m);
	rep(i,0,m) cin>>q[i].S.F>>q[i].S.S>>q[i].F;
	sort(q.begin(), q.end());
	rep(i,0,m) find_path(q[i].S.F-1,q[i].S.S-1,q[i].F);
	rep(i,0,m) if(check_path(q[i].S.F-1,q[i].S.S-1,q[i].F)==0) {cout<<"-1\n"; return 0;}

	rep(i,0,n-1)
	{
		if(f_val[i]==-1) f_val[i] = 1e6;
		cout<<f_val[i]<<" ";
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