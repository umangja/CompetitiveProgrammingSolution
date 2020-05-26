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
	ll n,k;cin>>n>>k;
	vi a(n);
	
	rep(i,0,n) cin>>a[i];
	sort(a.begin(), a.end());
	// debug_v(a);
	ll ans = *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end());
	// whatis(ans);
	vi sf(n,0),pf(n,0);

	rep(i,1,n) pf[i]=(i-1>=0?pf[i-1]:0)+(a[i]-a[i-1])*i;
	repr(i,n-2,-1) sf[i]=sf[i+1]+(a[i+1]-a[i])*(n-1-i);

	ll cost=0;
	rep(i,0,n)
	{
		cost=pf[i];
		ll left = k-cost;
		if(left>=0)
		{
			ll low = a[i],high = a[n-1];
			while(low<high)
			{
				ll mid = low+(high-low)/2;
				ll idx =  lower_bound(a.begin(), a.end(),mid) - a.begin();
				ll temp_cost = sf[idx]+(n-idx)*(a[idx]-mid);

				if(temp_cost<=left) high=mid;
				else low = mid+1;
			}
			ans=min(ans,low-a[i]);
			// if(ans==69) whatis(i);
		}
	}
	// whatis(ans);
	repr(i,n-1,-1)
	{
		cost=sf[i];
		ll left = k-cost;
		if(left>=0)
		{
			ll low = a[0],high = a[i];
			while(low<high)
			{
				ll mid = low+(high-low+1)/2;
				ll idx =  upper_bound(a.begin(), a.end(),mid) - a.begin()-1;
				ll temp_cost = pf[idx]+(idx+1)*(mid-a[idx]);

				if(temp_cost<=left) low=mid;
				else high = mid-1;
			}
			// whatis(a[i]-low);
			ans=min(ans,a[i]-low);
		}
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
	//cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	//cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}