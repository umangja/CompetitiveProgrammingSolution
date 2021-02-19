/*input
5 3
1 2 3 2 1


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
vi a;
ll n,k;
ll check(ll x){
	vi temp(n,0);
	vi mn(n,inf);
	rep(i,0,n){
		if(a[i]>=x) temp[i]=1;
		else if(a[i]<x) temp[i]=-1;
		temp[i] += (i-1>=0?temp[i-1]:0);
		mn[i] = min((i-1>=0?mn[i-1]:0),temp[i]);
	}

	if(temp[k-1]>0) return 1;

	rep(i,k,n){
		if( temp[i] - mn[i-k]>0 ) return 1;
	}
	return 0;

}

int solve()
{
	cin>>n>>k;
	a.resize(n);
	rep(i,0,n) cin>>a[i];

	map<ll,ll> hash,revHash;
	set<ll> st(a.begin(), a.end());
	ll cur = 1;
	for(ll x : st) {
		hash[x] = cur;
		revHash[cur] = x;
		cur++;
	}

	rep(i,0,n) a[i] = hash[a[i]];

	// rep(i,0,n) cout<<a[i]<<" "; cout<<"\n";

	ll low = 1,high = cur;
	while(low<high){
		ll mid = low + (high - low +1)/2;
		if(check(mid)) low = mid;
		else high = mid-1;
	}
	cout<<revHash[low]<<"\n";

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