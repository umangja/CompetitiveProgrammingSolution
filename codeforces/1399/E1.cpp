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
ll n,S;
vector<vpii> g;
map<pii,ll> edge;
vi cnt,par;
void dfs(ll u,ll p=-1)
{
	ll isLeaf=1;
	cnt[u]=0;
	par[u]=p;
	rep(i,0,sz(g[u]))
	{
		ll ch = g[u][i].F;
		if(ch==p) continue;
		dfs(ch,u);
		cnt[u]+=cnt[ch];
		isLeaf=0;
	}

	cnt[u]+=isLeaf;
	return ;
}

set< pii,greater<pii> > st;
ll sum;
ll ans;
void dfs2(ll u,ll p=-1)
{
	if(p!=-1)
	{
		ll w = edge[{p,u}];
		ll dif = w-w/2;
		st.insert({dif*cnt[u],u});
		sum+=cnt[u]*w;
	}

	rep(i,0,sz(g[u]))
	{
		ll ch = g[u][i].F;
		if(ch==p) continue;
		dfs2(ch,u);
	}

	return ;
}

int solve()
{
	cin>>n>>S;
	g.clear();edge.clear();cnt.clear();st.clear();par.clear();
	sum=0;ans=0;
	g.assign(n,vpii ());cnt.assign(n,0);par.resize(n);

	rep(i,0,n-1)
	{
		ll x,y;cin>>x>>y;
		x--,y--;
		ll w;cin>>w;

		g[x].pb(mp(y,w));
		g[y].pb(mp(x,w));

		edge[mp(x,y)]=w;
		edge[mp(y,x)]=w;
	}

	dfs(0);
	dfs2(0);

	while(sum>S)
	{
		pii pp = *st.begin();
		st.erase(pp);

		ans++;
		ll cur = pp.S;
		ll curp  = par[cur];
		assert(curp!=-1);
		assert(pp.F!=0);
		ll pw = edge[{curp,cur}]; 
		edge[{curp,cur}]=edge[{curp,cur}]/2;
		sum-=cnt[cur]*pw;
		sum+=cnt[cur]*edge[{curp,cur}];

		ll w = edge[{curp,cur}];
		ll dif = w-w/2;
		st.insert({dif*cnt[cur],cur});
	}

	cout<<ans<<"\n";
	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll test_cases=1;
	cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	//cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}