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

double dist(pii p1,pii p2)
{
	return (double)sqrtl( (p1.F-p2.F)*(p1.F-p2.F) + (p1.S-p2.S)*(p1.S-p2.S) );
}

int solve()
{
	ll n,m;cin>>n>>m;
	if(n==0 || m==0)
	{
		vpii ans;
		if(n==0)
		{
			ans.pb(mp(0,1));
			ans.pb(mp(0,m));
			ans.pb(mp(0,0));
			ans.pb(mp(0,m-1));
		}
		else
		{
			ans.pb(mp(1,0));
			ans.pb(mp(n,0));
			ans.pb(mp(0,0));
			ans.pb(mp(n-1,0));
		}
		rep(i,0,4) cout<<ans[i].F<<" "<<ans[i].S<<"\n";
	}
	else
	{
		ll sw=0;
		if(n<m) swap(n,m),sw=1;
		
		vpii ans1;
		ans1.pb(mp(0,1));
		ans1.pb(mp(n,m));
		ans1.pb(mp(0,0));
		ans1.pb(mp(n,m-1));

		double d1 = sqrt(n*n+m*m) + 2*sqrt(n*n+(m-1)*(m-1));

		vpii ans2;
		ans2.pb(mp(0,0));
		ans2.pb(mp(n,m));
		ans2.pb(mp(0,m));
		ans2.pb(mp(n,0));

		double d2 = 2*sqrt(n*n+m*m)+n;

		vpii ans = ans2;
		if(d1>d2) ans=ans1;

		// whatis(d1);
		// whatis(d2);
		
		if(sw) rep(i,0,4) swap(ans[i].F,ans[i].S);
		rep(i,0,4) cout<<ans[i].F<<" "<<ans[i].S<<"\n";
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
	// cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	//cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}