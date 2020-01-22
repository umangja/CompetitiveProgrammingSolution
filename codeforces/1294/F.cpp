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

ll n;
const ll N = 2e5+5;
vvi graph(N);
vi ans(4);
set<ll> path;
vi parent(N,-1);
// vi vis(N,0);
vi depth(N,0);
ll mx=0,tot=0;

void dfs(ll u,ll p,ll forest,ll idx,ll add_p)
{
	if(add_p==1) parent[u]=p;
	// if(forest==1) vis[u]=1;
	rep(i,0,sz(adj[u]))
	{
		ll ch = adj[u][i];
		if(ch==p) continue;
		depth[ch] = depth[u]+1;
		if((forest==1 && path.find(ch)!=path.end())) depth[ch]=0;
		dfs(ch,u,forest,idx,add_p);
	}

	mx=max(mx,depth[u]);
	if(depth[u]==mx) ans[idx] = u;
}

int solve()
{
	cin>>n;
	rep(i,0,n-1)
	{
		ll x,y;cin>>x>>y;
		x--,y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	depth[0]=0;
	dfs(0,-1,0,0,0);

	rep(i,0,n) depth[i]=0;
	depth[ans[0]]=0;
	mx=0;
	dfs(ans[0],-1,0,1,1);
	tot+=depth[ans[1]];

	path.insert(ans[1]);
	ll u=ans[1];
	// vis[u]=1;
	//,vis[u]=1;
	while(parent[u]!=-1) u=parent[u],path.insert(u);

	rep(i,0,n) depth[i]=0;
	mx=0;
	dfs(ans[0],-1,1,2,0);
	tot+=(mx);
	if(ans[2]==ans[0] || ans[2]==ans[1]) rep(j,0,n) if(j!=ans[0] && j!=ans[1]) ans[2]=j;
	cout<<tot<<"\n"<<ans[0]+1<<" "<<ans[1]+1<<" "<<ans[2]+1<<"\n";



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