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

const ll N = 3e5+5;
vi bit(N,0);
void add(ll idx,ll v)
{
	for(ll i=idx;i<N;i+=(i&-i)) bit[i]+=v;
	return ;
}

ll sum(ll idx)
{
	ll ans=0;
	for(ll i=idx;i>0;i-=(i&-i)) ans+=bit[i];
	return ans;
}

ll range_sum(ll l,ll r)
{
	return sum(r)-sum(l-1);
}

int solve()
{
	ll n;cin>>n;
	rep(i,0,n+3) bit[i]=0;

	vi a(n);
	set<ll> st;
	rep(i,0,n) cin>>a[i],st.insert(a[i]);

	ll num=0;
	map<ll,ll> hash;
	all(it,st) hash[*it]=num++;
	rep(i,0,n) a[i]=hash[a[i]];
	
	vi mx(num,-1);
	vi mn(num,inf);
	rep(i,0,n) mx[a[i]]=max(mx[a[i]],i),mn[a[i]]=min(mn[a[i]],i);

	// n values and num-1 numbers

	// debug_v(mn);

	vi dp(num);
	dp[0]=1;
	ll ans=num-dp[0];
	rep(i,1,num)
	{
		if(mx[i-1]<mn[i]) dp[i]=dp[i-1]+1;
		else dp[i]=1;
		ans=min(ans,num-dp[i]);
	}

	cout<<ans<<"\n";







	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

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