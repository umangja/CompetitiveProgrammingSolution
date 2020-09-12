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

int solve()
{
	ll n;cin>>n;
	vi pos,neg;
	ll z=0;
	rep(i,0,n)
	{
		ll x;cin>>x;
		if(x>0) pos.pb(x);
		else if(x<0) neg.pb(-1*x);
		else z++;
	}

	sort(pos.begin(), pos.end(),greater<ll> ());
	sort(neg.begin(), neg.end(),greater<ll> ());

	ll ans = -inf;
	n = sz(pos);
	ll m = sz(neg);

	rep(j,0,6)
	{
		if(m>=j && n>=5-j)
		{
			ll temp = 1;
			rep(i,0,j) temp*=-1*neg[m-1-i];
			rep(i,0,5-j) temp*=pos[n-1-i];
			ans=max(ans,temp);

			temp = 1;
			rep(i,0,j) temp*=-1*neg[i];
			rep(i,0,5-j) temp*=pos[i];
			ans=max(ans,temp);

			temp = 1;
			rep(i,0,j) temp*=-1*neg[m-1-i];
			rep(i,0,5-j) temp*=pos[i];
			ans=max(ans,temp);

			temp = 1;
			rep(i,0,j) temp*=-1*neg[i];
			rep(i,0,5-j) temp*=pos[n-1-i];
			ans=max(ans,temp);

		}
	}

	if(ans==-inf) ans=max(ans,0ll);
	if(ans<0 && z>0) ans=0;
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