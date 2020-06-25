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
const ll M = 25*(1e8);
const ll N = 1e3+1,N2 = 1e6;
map<pii,ll> pt;
vi ans;
vpii pts;

ll dist(ll x,ll y)
{
	return abs(pts[x].F-pts[y].F) + abs(pts[x].S-pts[y].S);
}

bool cmp(pii p1,pii p2)
{
	if(p1.S==p2.S) return p1.F<p2.F;
	return p1.S<p2.S;
}

bool cmp2(pii p1,pii p2)
{
	if(p1.S==p2.S) return p1.F<p2.F;
	return p1.S>p2.S;
}

int solve()
{
	ll n;cin>>n;
	vector< vpii > block(N,vpii ());
	rep(i,0,n)	
	{
		ll x,y;cin>>x>>y;
		pt[mp(x,y)] = i;
		pts.pb(mp(x,y));
		ll idx = x/N;
		block[idx].pb(mp(x,y));
	}

	rep(idx,0,N)
	{
		vpii a = block[idx];
		if(idx&1) sort(a.begin(), a.end(),cmp2);
		else      sort(a.begin(), a.end(),cmp);

		rep(i,0,sz(a)) ans.pb(pt[a[i]]);
	}


	ll d=0;
	rep(i,1,sz(ans)) d+=dist(ans[i],ans[i-1]);
	assert(d<=M);
	rep(i,0,sz(ans)) cout<<ans[i]+1<<" ";
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