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
const ll N = 4e5+5;
ll n,x;
vi d;
vi pf,sf;
vi pf2,sf2;

ll fun(ll xx)
{
	return (xx*xx+xx)/2;
}

ll bs(ll idx,ll left)
{

	if(pf[idx]<left) return -inf;
	if(pf[idx]==left) return pf2[idx];

	ll low = 0,high = idx;
	while(low<high)
	{
		ll mid = low+(high-low+1)/2;
		ll sum = pf[idx] - (mid-1>=0?pf[mid-1]:0);
		if(sum>left) low=mid;
		else high = mid-1;
	}

	ll ans=pf2[idx]-pf2[low];
	left = left-(pf[idx]-pf[low]);
	// whatis(ans);

	ll k = d[low];
	ans+=fun(k)-fun(k-left);
	return ans;
}

ll bs2(ll idx,ll left)
{
	if(sf[idx]<left) return -inf;
	if(sf[idx]==left) return sf2[idx];

	ll low = idx,high = n-1;
	while(low<high)
	{
		ll mid = low+(high-low)/2;
		ll sum = sf[idx] - (mid+1<n?sf[mid+1]:0);
		if(sum>left) high=mid;
		else low=mid+1;
	}


	ll ans = sf2[idx]-sf2[low];
	left= left-(sf[idx]-sf[low]);


	ans+=fun(left);
	return ans;


}

int solve()
{
	cin>>n>>x;
	d.assign(2*n,0);
	pf.assign(2*n,0);
	pf2.assign(2*n,0);

	sf.assign(2*n,0);
	sf2.assign(2*n,0);

	rep(i,0,n) cin>>d[i];
	rep(i,n,2*n) d[i]=d[i-n];
	n*=2;

	rep(i,0,n) pf[i]=(i-1>=0?pf[i-1]:0)+d[i];
	rep(i,0,n) pf2[i]=(i-1>=0?pf2[i-1]:0)+fun(d[i]);

	repr(i,n-1,-1) sf[i] =(i+1<n?sf[i+1]:0)+d[i];
	repr(i,n-1,-1) sf2[i]=(i+1<n?sf2[i+1]:0)+fun(d[i]);


	ll ans=0;
	rep(i,0,n)
	{
		if(d[i]>=x)
		{
			ll temp_ans = fun(d[i]) - fun(d[i]-x);
			ans=max(ans,temp_ans);
		}
		else
		{
			if(i!=0 )
			{
				ll left = x-d[i];
				ll temp_ans = fun(d[i]);
				temp_ans+=bs(i-1,left);

				ans=max(ans,temp_ans);
			}

			if(i!=n-1)
			{
				ll left = x-d[i];

				ll temp_ans = fun(d[i]);
				temp_ans+=bs2(i+1,left);
				// whatis(bs2(i+1,left));
				// whatis(temp_ans);				
				ans=max(ans,temp_ans);
			}

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