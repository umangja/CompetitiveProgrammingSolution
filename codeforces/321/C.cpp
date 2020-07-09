/*input

*/


// assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

const ll N = 1e5+5;
ll n;
vvi g(N,vi ());
vi vis(N,0),siz(N,0),col(N,-1);

ll dfs1(ll u,ll p)
{
	siz[u]=1;
	rep(i,0,sz(g[u]))
	{
		ll ch = g[u][i];
		if(ch==p || vis[ch]==1) continue;
		else siz[u]+=dfs1(g[u][i],u);
	}
	return siz[u];
}

void dfs2(ll u,ll p=0,ll last=0,ll cur=0)
{
	rep(i,0,sz(g[u])) if(g[u][i]!=p && vis[g[u][i]]==0 && 2*siz[g[u][i]]>siz[cur]) return dfs2(g[u][i],u,last,cur);

	if(vis[last]==0) col[u]=0;
	else col[u]=col[last]+1;

	vis[u]=1;

	// cout<<"centroid is "<<u+1<<"\n";
	rep(i,0,sz(g[u])) if(vis[g[u][i]]==0) dfs1(g[u][i],u),dfs2(g[u][i],u,u,g[u][i]);
	return ;
}

int solve()
{
	cin>>n;
	rep(i,0,n-1)
	{
		ll x,y;cin>>x>>y;
		x--,y--;
		g[x].pb(y);
		g[y].pb(x);
	}

	dfs1(0,-1);
	dfs2(0,0,0,0);
	// rep(i,0,n) cout<<col[i]<<"\n";
	rep(i,0,n) cout<<(char)(col[i]+'A')<<"\n";

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