/*input
10
911605217 -1 -1
801852416 -1 -1
140035920 -1 9
981454947 10 2
404988051 6 3
307545107 8 7
278188888 4 1
523010786 -1 -1
441817740 -1 -1
789680429 -1 -1
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
const ll N = 1e5+5;
vvi graph(N);
ll val[N];

set< ll > s;
void dfs(ll v,ll mx,ll mn)
{
	if(val[v]<mn && val[v]>mx) s.insert(val[v]);
	rep(j,0,2)
	{
		if(j==0 && adj[v][j]!=-1) dfs(adj[v][j],mx,min(mn,val[v]));
		if(j==1 && adj[v][j]!=-1) dfs(adj[v][j],max(mx,val[v]),mn);
	}
}

int solve()
{
	ll n;cin>>n;
	vi par(n,-1);
	rep(i,0,n)
	{
		ll l,r;
		cin>>val[i]>>l>>r;
		if(l!=-1) adj[i].pb(--l),par[l]=i;
		else adj[i].pb(l);
		if(r!=-1) adj[i].pb(--r),par[r]=i;
		else adj[i].pb(r);
	}

	rep(i,0,n) if(par[i]==-1) {dfs(i,-1,inf);break;}
	ll ans=0;
	rep(i,0,n) if(s.find(val[i])==s.end()) ans++;
	cout<<ans; 
	return 0;

}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll test_cases=1;
	// cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}