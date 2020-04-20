/*input

*/


// assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll          long long int
#define pb          push_back
#define pii         pair<ll ,ll >
#define vpii        vector< pii >
#define vi          vector<ll >
#define vs			vector< string >
#define vvi         vector< vector< ll > >
#define inf			(ll)1e18
#define all(it,a)   for(auto it=(a).begin();it!=(a).end();it++) 
#define F           first
#define S           second
#define sz(x)       (ll )x.size()
#define rep(i,a,b)	for(ll  i=a;i<b;i++)
#define repr(i,a,b) for(ll  i=a;i>b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define whatis(x)   cout << #x << " is " << x << "\n";
#define graph(n)    adj(n,vector< ll > () )
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define debug(x)     cout << #x << " " << x << endl;
#define debug_p(x)   cout << #x << " " << x.F << " " << x.S << endl;
#define debug_v(x)   {cout << #x << " "; for (auto ioi : x) cout << ioi << " "; cout << endl;}
#define debug_vp(x)  {cout << #x << " "; for (auto ioi : x) cout << '[' << ioi.F << " " << ioi.S << ']'; cout << endl;}
#define debug_v_v(x) {cout << #x << "/*\n"; for (auto ioi : x) { for (auto ioi2 : ioi) cout << ioi2 << " "; cout << '\n';} cout << "*/" << #x << endl;}

const ll N = 2e5+5;
vvi adj;
vi col;
vi s(N,0);
vi ans;
ll tmr=0;
ll n;
vvi f(N,vi ());
vi tin(N,-1);
void dfs(ll u,ll p=-1)
{
	tin[u] = tmr++;

	s[u]=1;
	rep(i,0,sz(adj[u]))
	{
		ll ch = adj[u][i];
		if(ch==p) continue;
		dfs(ch,u);

		s[u]+=s[ch];

		ll w = s[ch];
		while(sz(f[col[u]]) && tin[f[col[u]].back()] > tin[u] ) w-=s[f[col[u]].back()],f[col[u]].pop_back();
		ans[col[u]]-=w*(w-1);
	}

	f[col[u]].pb(u);
	return ;
}

int solve()
{
	cin>>n;

	adj.assign(n,vi ());
	col.assign(n,0);
	ans.assign(n,n*(n-1));
	map<ll,ll> m;
	rep(i,0,n) cin>>col[i],col[i]--,m[col[i]]++;
	rep(i,0,n-1)
	{
		ll x,y;cin>>x>>y;
		x--,y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	dfs(0);

	rep(i,0,n)
	{
		ll w = n;
		while(sz(f[i])) w-=s[f[i].back()],f[i].pop_back();
		ans[i]-=w*(w-1);
	}

	rep(i,0,n) cout<<ans[i]/2 + m[i]<<"\n";





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
	//cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}
