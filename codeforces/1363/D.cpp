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
ll cnt=0;
ll query(vi a)
{
	assert(cnt<12);
	cout<<"? "<<sz(a)<<" ";
	rep(i,0,sz(a)) cout<<a[i]<<" ";
	cout<<"\n"<<flush;
	ll ans;cin>>ans;
	return ans;
}

int solve()
{
	cnt=0;
	ll n,k;cin>>n>>k;
	vvi a(k, vi());
	rep(i,0,k)
	{
		ll x;cin>>x;
		a[i].resize(x);
		rep(j,0,x) cin>>a[i][j];
	}

	vi ans;
	rep(i,1,n+1) ans.pb(i);
	ll mx = query(ans);

	ll low = 1,high = n;
	while(low<high)
	{
		ll mid = low+(high-low)/2;
		ans.clear();
		rep(i,low,mid+1) ans.pb(i);
		ll t = query(ans);
		if(t==mx) high = mid;
		else low = mid+1;
	}

	ll mx_idx = low;
	ans.clear();
	ans.resize(k);
	rep(i,0,k)
	{
		ll pre=0;
		rep(j,0,sz(a[i])) if(a[i][j]==mx_idx) pre=1;
		if(!pre) ans[i]=mx;
		else
		{
			set<ll> st;
			rep(ii,1,n+1) st.insert(ii);
			rep(j,0,sz(a[i])) st.erase(a[i][j]);

			vi ans_temp(st.begin(), st.end());

			ans[i] = query(ans_temp);
		} 
	}

	cout<<"! ";
	rep(i,0,k) cout<<ans[i]<<" ";
	cout<<"\n"<<flush;
	string s;cin>>s;
	assert(s=="Correct");

	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	// ios_base::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);

	ll test_cases=1;
	cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	//cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}