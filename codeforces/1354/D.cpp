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

#define ll          long int
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
const ll N = 1e6+5;
vi bit(N,0);

void add(ll idx, ll val) {
    for (++idx; idx < N; idx += idx & -idx) bit[idx] += val;
}

void range_add(ll l, ll r, ll val) {
    add(l, val);
    add(r + 1, -val);
}

ll point_query(ll idx) {
    ll ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx) ret += bit[idx];
    return ret;
}

int solve()
{
	ll n,q;
	cin>>n>>q;
	vi cnt(n+1,0);
	ll siz=0;
	rep(i,0,n)
	{
		ll x;cin>>x;
		siz++;
		cnt[x]++;
		range_add(x,n+2,1);
	}


	rep(i,0,q)
	{
		ll x;cin>>x;
		if(x>0)
		{
			siz++;
			cnt[x]++;
			range_add(x,n+2,1);
		}

		if(x<0)
		{
			x*=-1;
			siz--;
			// rep(i,1,n+1) cout<<point_query(i)<<" ";
			// cout<<"\n";

			ll low = 1,high = n+1;
			while(low<high)
			{
				ll mid = low+(high-low)/2;
				ll val = point_query(mid);
				if(val>=x) high=mid;
				else low = mid+1;
			}

			// whatis(low);
			range_add(low,n+2,-1);
			cnt[low]--;

		} 
	}

	if(siz==0) cout<<0;
	else
	{
		rep(i,1,n+1)
		{
			if(cnt[i]>0)
			{
				cout<<i;
				return 0;
			}

		} 
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
	//cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	//cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}