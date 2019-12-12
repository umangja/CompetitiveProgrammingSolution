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
const ll N = 1e5+5;
vvi graph(N);
vi ans;
vi degree(N,0);
vi vis(N,0);

void dfs(ll u)
{
	vis[u]=1;
	ans.pb(u);
	rep(i,0,sz(adj[u]))
	{
		ll ch = adj[u][i];
		if(vis[ch]==0) dfs(ch);
	}
	return ;
}

int solve()
{
	ll n;cin>>n;
	map<ll,ll> hash;
	map<ll,ll> rhash;
	ll num=0;
	rep(i,0,n)
	{
		ll x,y;cin>>x>>y;
		if(hash.find(x)==hash.end()) hash[x]=num++;
		if(hash.find(y)==hash.end()) hash[y]=num++;

		rhash[hash[x]]=x;
		rhash[hash[y]]=y;

		x=hash[x],y=hash[y];
		adj[x].pb(y);
		adj[y].pb(x);
		degree[x]++,degree[y]++;
	}

	rep(i,0,num+1) if(degree[i]==1) {dfs(i); break;}
	rep(i,0,sz(ans)) cout<<rhash[ans[i]]<<" ";


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