/*input
1
5 6
-1 1 5 11 15
-4 -3 -2 6 7 15
2 2
-1 1
-1000000000 1000000000
2 2
-1000000000 1000000000
-1 1
3 5
-1 1 2
-2 -1 1 2 5
2 1
1 2
10

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

ll fun(vi a,vi b){
	ll n = sz(a);
	ll m = sz(b);

	// debug_v(a);

	if(n==0 || m==0) return 0;
	ll ans=0;
	ll cnt=0;
	for(ll i = m-1;i>=0;i--){
		ll upto = upper_bound(a.begin(), a.end(),b[i]) - a.begin()-1;
		// cout<<i+1<<"\n";
		// cout<<upto+1<<"\n";
		if(upto>=0){
			ll R = b[i];
			ll L = R-upto;

			ll Ridx = upper_bound(b.begin(), b.end(),R) - b.begin();
			ll Lidx = lower_bound(b.begin(), b.end(),L) - b.begin();
			// cout<<L<<" "<<R<<" "<<Lidx+1<<" "<<Ridx+1<<"\n";
			assert(Ridx>=Lidx);
			ans = max(ans,Ridx - Lidx + cnt);
			// whatis(Ridx - Lidx + cnt);
			if(a[upto]==b[i]) cnt++;
		}
	}
	return ans;
}

int solve()
{
	ll n,m;cin>>n>>m;
	vi posa,posb,nega,negb;
	rep(i,0,n){
		ll x;cin>>x;
		if(x>0) posa.pb(x);
		else nega.pb(-1*x);
	} 
	rep(i,0,m) {
		ll x;cin>>x;
		if(x>0) posb.pb(x);
		else negb.pb(-1*x);
	}
	sort(nega.begin(), nega.end());
	sort(negb.begin(), negb.end());
	cout<<fun(posa,posb)+fun(nega,negb)<<"\n";


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