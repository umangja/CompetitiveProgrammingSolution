/*input
7 9
4 3
2 6
7 1
4 1
7 3
3 5
7 4
6 5
2 5

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
const ll N = 4e5+5;
ll lvl[N],dp[N];
vvi graph(N),tree(N),tree1(N);
map<pii,ll> idx,bdg;
vpii ans(N,mp(-1,-1));
vpii bridge;
ll cnt=0;
ll vis[N];
ll visited[N];

void dfs(ll u,ll p)
{
	dp[u]=0;

	rep(i,0,sz(adj[u]))
	{
		ll ch = adj[u][i];
		if(lvl[ch]==0)
		{
			lvl[ch]=lvl[u]+1;
			tree[u].pb(ch);
			tree[ch].pb(u);
			dfs(ch,u);
			dp[u]+=dp[ch];
		}
		else if(lvl[ch]>lvl[u]) {dp[u]--;}
		else if(lvl[ch]<lvl[u] && ch!=p){dp[u]++;}	
	}

	if(p!=-1 && dp[u]==0)
		bridge.pb(mp(p,u)),bdg[mp(p,u)]=1,bdg[mp(u,p)]=1;
}

void dfs2(ll u)
{
	cnt++;
	vis[u]=1;
	for(ll i=0;i<sz(tree[u]);i++)
	{
		ll ch = tree[u][i];
		if(vis[ch]==0 && bdg.find(mp(u,ch))==bdg.end())
			dfs2(ch);
	}
}

void dfs3(ll u)
{
	visited[u]=1;
	rep(i,0,sz(adj[u]))
	{
		ll ch = adj[u][i];
		if(visited[ch]==0)
		{
			if(bdg.find(mp(u,ch))==bdg.end())
				ans[idx[mp(u,ch)]]=mp(u,ch);
			else
				ans[idx[mp(ch,u)]]=mp(ch,u);
			dfs3(ch);
		}
		else
		{
			if(ans[idx[mp(u,ch)]].F==-1)
				ans[idx[mp(u,ch)]]=mp(u,ch);
		}
			
	}
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
		idx[mp(x,y)]=i;
		idx[mp(y,x)]=i;
	}

	lvl[0]=1;
	dfs(0,-1);

	ll ansf=-1;
	ll root=0;
	rep(i,0,sz(bridge))
	{
		ll p = bridge[i].F;
		ll ch = bridge[i].S;

		ll c1=-1,c2=-1;
		if(vis[p]==0)
			cnt=0,dfs2(p),c1=cnt;
		if(vis[ch]==0)
			cnt=0,dfs2(ch),c2=cnt;

		if(ansf<c1) ansf=c1,root=p;
		if(ansf<c2) ansf=c2,root=ch;
	}
	dfs3(root);
	if(ansf==-1) ansf=n;
	cout<<ansf<<"\n";
	rep(i,0,m)
		cout<<ans[i].F+1<<" "<<ans[i].S+1<<"\n";


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