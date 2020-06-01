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
const ll N = 2e5+5;
ll n,m,k;
vvi adj;
vi vis;
vi dist;
map<pii,ll> edge;
vvi inEdges;
string ans = "";
vs anss;

void dikstra()
{
	priority_queue<pii,vpii,greater<pii> > q;
	q.push(mp(0,0));
	dist[0]=0;

	while(!q.empty())
	{
		pii p = q.top();
		q.pop();

		rep(i,0,sz(adj[p.S]))
		{
			ll ch = adj[p.S][i];
			if(p.F+1==dist[ch]) inEdges[ch].pb(p.S);
			else if(p.F+1<dist[ch])
			{
				dist[ch]=p.F+1;
				inEdges[ch].clear();
				inEdges[ch].pb(p.S);
				q.push(mp(dist[ch],ch));
			}

		}
	}
	return ;
}

void init()
{
	adj.clear();
	vis.clear();
	dist.clear();
	ans="";
	anss.clear();
	inEdges.clear();

	adj.assign(n,vi ());
	inEdges.assign(n,vi ());

	vis.assign(n,0);
	dist.assign(n,inf);
}

void fun(ll pos)
{

	if(sz(anss)>=k) return ;

	if(pos>=n)
	{
		if(sz(anss)<k) anss.pb(ans);
		return ;
	}

	rep(i,0,sz(inEdges[pos]))
	{
		ll par = inEdges[pos][i];
		ll idx = edge[mp(par,pos)];
		ans[idx]='1';
		fun(pos+1);
		ans[idx]='0';
	}
	return ;
}

int solve()
{
	cin>>n>>m>>k;
	init();

	rep(i,0,m)
	{
		ll x,y;cin>>x>>y;
		x--,y--;
		edge[mp(x,y)]=i;
		edge[mp(y,x)]=i;
		adj[x].pb(y);
		adj[y].pb(x);
		ans+='0';
	}

	dikstra();
	fun(1);

	cout<<sz(anss)<<"\n";
	rep(i,0,sz(anss)) cout<<anss[i]<<"\n";







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