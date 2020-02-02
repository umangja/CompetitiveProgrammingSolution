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
vi c(N),a(N);
vvi adj(N,vi ());
vi vis(N,0),ans(N,0);
ll ansf=0;
ll mn=inf;
set<ll> path;

void dfs2(ll u,ll f)
{
	path.insert(u);
	mn=min(mn,c[u]);
	if(adj[u][0]!=f) dfs2(adj[u][0],f);
}

void dfs(ll u)
{
	vis[u]=1;
	rep(i,0,sz(adj[u]))
	{
		ll ch = adj[u][i];
		if(vis[ch])
		{	
			if(ans[ch])
			{
				ans[u]=ans[ch];
				return ;
			} 
			else
			{
				mn=inf;
				path.clear();
				dfs2(u,u);
				all(it,path) ans[*it] = mn;
				ansf+=mn; 
				// whatis(mn);
				// all(it,path) cout<<*it<<" ";
				// cout<<"\n";
			}
		}
		else
		{
			dfs(ch);
			ans[u]=ans[ch];
		} 
	}
	return ;
}

int solve()
{
	ll n;cin>>n;
	rep(i,0,n) cin>>c[i];
	rep(i,0,n) cin>>a[i],a[i]--;

	rep(i,0,n) adj[i].pb(a[i]);

	rep(i,0,n)
	{
		if(vis[i]==0)
		{
			mn=inf;
			dfs(i);
		}
	}

	// rep(i,0,n) cout<<ans[i]<<" ";

	cout<<ansf<<"\n";




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
