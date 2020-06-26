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
const ll N = 1000;
vvi ans(N,vi ());
ll edge=0;
vvi fun(ll n,ll st=0)
{
	vvi adj(n+3,vi ());
	vi deg(n+3,0);
	rep(i,2,n+1) adj[1].pb(i),adj[n+2].pb(i),adj[n+1].pb(i),deg[i]+=3;
	adj[n+1].pb(n+2);

	rep(i,2,n+1)
	{
		ll beg = (i%2==0?i+2:i+1);
		rep(j,beg,n+1) adj[i].pb(j);
	} 
	rep(i,1,n+3) rep(j,0,sz(adj[i])) ans[i+st].pb(adj[i][j]+st),edge++;
	return adj;
}


int solve()
{	
	ll n;cin>>n;
	if(!(n&1))
	{
		cout<<"NO\n";
		return 0;
	}

	if(n==1)
	{
		cout<<"YES\n2 1\n1 2";
		return 0;
	}

	fun(n);
	fun(n,n+2);
	ans[1].pb(n+3);
	edge++;

	vi deg(N,0);
	rep(i,0,N) rep(j,0,sz(ans[i])) deg[i]++,deg[ans[i][j]]++;

	// rep(i,1,2*n+5)  cout<<deg[i]<<"\n";

	cout<<"YES\n";
	cout<<2*n+4<<" "<<edge<<"\n";
	rep(i,0,N) rep(j,0,sz(ans[i])) cout<<i<<" "<<ans[i][j]<<"\n";
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