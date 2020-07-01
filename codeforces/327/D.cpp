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

const ll N = 501;

vvi vis(N,vi (N,0));
vvi vis2(N,vi (N,0));
vector<pair<char,pii>> ans;


vpii nodes;

ll n,m;
vs mat;

ll dx[] = {0,1,0,-1};
ll dy[] = {1,0,-1,0};

ll check(ll i,ll j)
{
	if(i>=0 && i<n && j>=0 && j<m && mat[i][j]=='.') return 1;
	return 0;
}

void dfs(ll x,ll y,ll col)
{
	vis[x][y]=1;
	nodes.pb(mp(x,y));

	rep(k,0,4)
	{
		ll i = x+dx[k];
		ll j = y+dy[k];
		if(check(i,j) && vis[i][j]==0) dfs(i,j,col^1);
	}
	return ;
}

void dfs2(ll x,ll y)
{
	vis2[x][y]=1;

	ll f=0;
	rep(k,0,4)
	{
		ll i = x+dx[k];
		ll j = y+dy[k];
		if(check(i,j) && vis2[i][j]==0) f=1;
	}

	if(f)
	{
		ans.pb(mp('D',mp(x,y)));
		ans.pb(mp('R',mp(x,y)));
	}

	rep(k,0,4)
	{
		ll i = x+dx[k];
		ll j = y+dy[k];
		if(check(i,j) && vis2[i][j]==0) dfs2(i,j);
	}


	return ;
}

int solve()
{
	cin>>n>>m;
	mat.resize(n);

	
	rep(i,0,n) cin>>mat[i];

	rep(i,0,n) rep(j,0,m) if(mat[i][j]=='.' && vis[i][j]==0) 
	{
		nodes.clear();
		dfs(i,j,0);
		reverse(nodes.begin(), nodes.end());
		rep(j1,0,sz(nodes))   ans.pb(mp('B',mp(nodes[j1].F,nodes[j1].S)));
		rep(j1,0,sz(nodes)-1) ans.pb(mp('D',mp(nodes[j1].F,nodes[j1].S))),ans.pb(mp('R',mp(nodes[j1].F,nodes[j1].S)));
	}

	cout<<sz(ans)<<"\n";
	rep(i,0,sz(ans)) cout<<ans[i].F<<" "<<ans[i].S.F+1<<" "<<ans[i].S.S+1<<"\n";

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