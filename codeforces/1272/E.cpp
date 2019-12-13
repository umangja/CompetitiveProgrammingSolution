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
vvi adj(N,vi ());
vi a(N);
vi ans(N);
vi vis(N,0);
ll n;

int solve()
{
	cin>>n;
	rep(i,0,n) cin>>a[i];
	rep(i,0,n)
	{
		if(i+a[i]<n)  adj[i+a[i]].pb(i);
		if(i-a[i]>=0) adj[i-a[i]].pb(i);
	}

	vi odd,even,d(n,inf);
	rep(i,0,n) if((a[i]&1)==1) odd.pb(i); else even.pb(i);

	queue<ll> q;
	rep(i,0,sz(odd)) vis[odd[i]]=1,d[odd[i]]=0,q.push(odd[i]); 
	while(sz(q))
	{
		ll u = q.front();
		q.pop();
		rep(i,0,sz(adj[u])) if(vis[adj[u][i]]==0) d[adj[u][i]] = d[u]+1,vis[adj[u][i]]=1,q.push(adj[u][i]);
	}

	rep(i,0,sz(even))
	{
		ll e = even[i];
		if(d[e]==inf) ans[e]=-1;
		else ans[e]=d[e];
	}

	queue<ll> dq;
	q=dq;
	rep(i,0,n) vis[i]=0,d[i]=inf;
	
	rep(i,0,sz(even)) vis[even[i]]=1,d[even[i]]=0,q.push(even[i]); 
	while(sz(q))
	{
		ll u = q.front();
		q.pop();
		rep(i,0,sz(adj[u])) if(vis[adj[u][i]]==0) d[adj[u][i]] = d[u]+1,vis[adj[u][i]]=1,q.push(adj[u][i]);
	}

	rep(i,0,sz(odd))
	{
		ll e = odd[i];
		if(d[e]==inf) ans[e]=-1;
		else ans[e]=d[e];
	}

	rep(i,0,n) cout<<ans[i]<<" ";
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
// 	cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}