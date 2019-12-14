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
const ll N = 2e5+5;
ll a,b;
vvi adj(N,vi ());
vi vis(N,0);
vector< set<ll> > s(2);

void dfs(ll u,ll f,ll w)
{
	vis[u]=1;
	s[w].insert(u);
	rep(i,0,sz(adj[u]))
	{
		ll ch = adj[u][i];
		if(vis[ch]==0 && ch!=f) dfs(ch,f,w);
	}
}

int solve()
{
	s[0].clear();
	s[1].clear();

	ll n,m;cin>>n>>m;
	cin>>a>>b;
	a--;b--;
	rep(i,0,n) adj[i].clear();
	rep(i,0,m)
	{
		ll x,y;cin>>x>>y;
		x--;y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	rep(i,0,n) vis[i]=0;
	dfs(a,b,0);
	rep(i,0,n) vis[i]=0;
	dfs(b,a,1);

	// whatis(sz(s[0]));
	// whatis(sz(s[1]));

	set<ll> com;
	all(it,s[0]) if(s[1].find(*it)!=s[1].end()) com.insert(*it);
	cout<<(sz(s[0])-sz(com)-1)*(sz(s[1])-sz(com)-1)<<"\n";
	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll test_cases=1;
	cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}