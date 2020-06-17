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
const ll N = 1e5+6;
ll n,m,k;
vvi adj(N,vi ());
vvi g(N,vi ());

vi vis(N,0);
vi par(N,-1);
vi col(N,-1);
ll cycle=0;
vi cnt(2,0);
vi nodes;

void dfs(ll u,ll p,ll c)
{
	vis[u]=1;
	col[u]=c;
	par[u]=p;
	cnt[c]++;

	rep(i,0,sz(adj[u]))
	{
		ll ch = adj[u][i];
		if(ch==p) continue;
		if(vis[ch]==1)
		{
			if(sz(nodes)!=0) return ;

			cycle=1;
			while(u!=ch) nodes.push_back(u),u=par[u];
			nodes.push_back(ch);
			reverse(nodes.begin(),nodes.end());
			
			return ;
		}
	}

	rep(i,0,sz(adj[u]))
	{
		ll ch = adj[u][i];
		if(p==ch) continue;
		if(vis[ch]==0) dfs(ch,u,c^1);
	}

	return ;
}

int solve()
{
	cin>>n>>m>>k;
	rep(i,0,m)
	{
		ll x,y;
		cin>>x>>y;
		x--,y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}	

	dfs(0,-1,0);
	if(cycle==1)
	{
		ll len = sz(nodes);
		if(len<=k)
		{
			cout<<2<<"\n"<<len<<"\n";
			rep(i,0,len) cout<<nodes[i]+1<<" ";
		}
		else
		{
			cout<<1<<"\n";
			k=(k+1)/2;
			for(ll i=0;i<len && k;i+=2) cout<<nodes[i]+1<<" ",k--;
		}
	}
	else
	{
		ll cc=0;
		if(cnt[1]>=(k+1)/2) cc=1;
		k=(k+1)/2;
		cout<<1<<"\n";
		rep(i,0,N) if(col[i]==cc && k) cout<<i+1<<" ",k--;
		return 0;
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
	//cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}