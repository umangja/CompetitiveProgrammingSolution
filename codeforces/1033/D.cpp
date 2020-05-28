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

const ll mod = 998244353;

ll power(ll x,ll y)
{
	x%=mod;
	if(x<0) x+=mod;
	x%=mod;

	// y%=(mod-1) //valid only if mod is prime number; 

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

ll fun(ll x)
{
	ll low = 0,high = 1259922;
	while(low<high)
	{
		ll m  = low+(high-low+1)/2;
		if(m*m*m<=x) low = m;
		else high = m-1;
	}

	return low;
}


int solve()
{
	ll n;cin>>n;
	vi a(n);
	rep(i,0,n) cin>>a[i];
	vi b;
	map<ll,ll> cnt;

	rep(i,0,n)
	{
		ll el = a[i];
		ll elr = (ll)sqrtl(el);
		if(elr*elr==el)
		{
			ll elrr = (ll)sqrtl(elr);
			if(elrr*elrr==elr) cnt[elrr]+=4;
			else cnt[elr]+=2;
		}
		else
		{
			ll el3 = fun(el);
			if(el3*el3*el3==el) cnt[el3]+=3;
			else b.pb(el);
		}
	}

	ll p4=0;
	map<ll,ll> fq;
	rep(i,0,sz(b)) fq[b[i]]++;

	ll ans = 1;
	all(it,fq)
	{
		ll el = it->F;
		ll fd=0;
		rep(j,0,n)
		{
			ll g = __gcd(el,a[j]);
			if(g!=1 && g!=el)
			{
				cnt[g]+=it->S;
				cnt[el/g]+=it->S;
				fd=1;
				break;
			}
		}

		if(!fd)
		{
			ans = ans*(((it->S+1)*(it->S+1))%mod);
			ans%=mod;
		} 
	}

	all(it,cnt) ans = (ans*(it->S+1))%mod;

	// whatis(ans);
	// whatis(p4);

	// ans  = (ans*power(4,p4))%mod;
	cout<<ans<<"\n"<<flush;
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