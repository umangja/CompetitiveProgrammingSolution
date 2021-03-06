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

const ll mod = 1000000007; 
const ll INF = 1e10;
ll power(ll x,ll y)
{
	x%=mod;
	if(x<0) x+=mod;
	x%=mod;

	y%=(mod-1); //valid only if mod is prime number; 

	ll ans=1;
	while(y)
	{
		if(y&1)
		{
			ans = (ans*x)%mod;
		} 
		y>>=1;
		x=(x*x)%mod;
	}
	return ans;
}

pii need = mp(0,0);
int solve()
{
	ll n,p;cin>>n>>p;
	vi a(n);
	rep(i,0,n) cin>>a[i];
	sort(a.begin(), a.end());

	if(p==1)
	{
		cout<<(n&1)<<"\n";
		return 0;
	}

	// debug_v(a);

	repr(i,n-1,-1)
	{
		need = mp(a[i],1);
		ll j = i-1;
		while(j>=0)
		{
			ll cur = a[j];
			if(cur<need.F)
			{
				// int t = (p^(need.F-a[j]))*need.S;

				ll t = need.S;
				ll pos=1;
				ll left = need.F-a[j];
				while(left)
				{
					if(t<=INF/p) t*=p,left--;
					else
					{
						pos = 0;
						break;
					}
				}
				if(pos==0)
				{
					ll ans = power(p,a[i]);
					rep(k,0,i) 
					{
						ans = (ans - power(p,a[k]))%mod+mod;
						if(ans>=mod) ans-=mod;
					}
					cout<<ans<<"\n";
					return 0;
				}
				need=mp(a[j],t-1);
			}
			else 
			{
				need = mp(need.F,need.S-1);
				if(need.S==0) break;
			}
			j--;
		}
		i=j;
	}

	ll ans = (power(p,need.F)*need.S)%mod;
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