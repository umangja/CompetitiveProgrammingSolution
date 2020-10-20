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

ll fun1(ll n)
{
	ll ans = 1;
	for(ll i=n;i>n/2;i--) ans*=i;
	for(ll i=1;i<=n/2;i++) ans/=i;
	return ans;
}


ll fun2(ll n)
{
	ll ans=1;
	rep(i,2,n) ans*=i;
	return ans;
}

// ll fun2(ll n)
// {
// 	unordered_set< vector<ll> > st;
// 	vector<ll> a;
// 	rep(i,1,n+1) a.pb(i);

// 	do
// 	{
// 		vi temp(a.begin(), a.end());
// 		ll j = 0;
// 		while(j<n && a[j]!=1) j++;
// 		assert(a[j]==1);
// 		vi temp2(temp.begin(), temp.end());
// 		rep(i,0,n)
// 		{
// 			ll nidx = ((i-j)%n+n)%n;
// 			temp2[nidx]=temp[i];
// 		} 	

// 		// debug_v(temp);
// 		// debug_v(temp2);

// 		st.insert(temp2);
// 	}while(next_permutation(a.begin(), a.end()));
// 	whatis(sz(st));
// 	return sz(st);
// }

int solve()
{
	ll n;cin>>n;
	ll ans1  = fun1(n)/2;
	ll ans2  = fun2(n/2);
	// cout<<ans1<<" "<<ans2<<"\n";
	cout<<ans1*ans2*ans2<<"\n";
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
	//cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	//cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}