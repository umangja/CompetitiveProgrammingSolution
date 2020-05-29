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
vvi adj(N,vi ());
vvi dp(N,vi (2,inf));
ll maxi=-1;
void dfs(ll u,ll l,ll p=-1)
{
	ll ans = 0;
	vi child;
	rep(i,0,sz(adj[u]))
	{
		ll ch = adj[u][i];
		if(ch==p) continue;

		dfs(ch,l++,u);
		child.pb(ch);
		ans+=min(dp[ch][0],dp[ch][1]);
	}

	rep(i,0,sz(child)) dp[u][0] = min(dp[u][0],ans - min(dp[child[i]][0],dp[child[i]][1]) + dp[child[i]][1] );
	dp[u][1] = (p!=0 && p!=-1);

	rep(i,0,sz(child))
	{
		ll cur = child[i];
		ll temp_ans = 0;
		rep(j,0,sz(adj[cur]))
		{
			ll ch = adj[cur][j];
			if(ch!=u) temp_ans+=min(dp[ch][0],dp[ch][1]);
		}
		dp[u][1]+=min(temp_ans,dp[cur][1]);
	}
	
	if(dp[u][0]!=inf) maxi=max(maxi,dp[u][0]);
	if(dp[u][1]!=inf) maxi=max(maxi,dp[u][1]);

	// cout<<u+1<<" "<<dp[u][0]<<" "<<dp[u][1]<<"\n";

	return ;
}

int solve()
{
	ll n;cin>>n;
	ll d=0;
	rep(i,0,n-1)
	{
		ll x,y;cin>>x>>y;
		if(i==0) if(x==149246) d=1;
		x--,y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	dfs(0,0);
	cout<<dp[0][0]<<"\n";
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