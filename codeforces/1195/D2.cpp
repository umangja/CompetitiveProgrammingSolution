/*input
100
3615 1436 2205 5695 9684 7621 391 1579 557 420 1756 5265 247 5494 3509 6089 2931 7372 4939 8030 2901 1150 5389 7168 6213 2723 4301 7250 3857 9178 4723 1932 1161 1412 8200 5226 1474 3495 9533 8555 6372 1517 8034 6547 1148 9651 2399 3065 9675 3418 7758 3226 9844 4234 510 7652 162 8010 8162 2732 2112 4041 3392 6344 671 4120 4659 7718 8660 7102 9098 6195 6999 9411 6710 2261 4388 7125 3808 978 398 9286 1280 7382 1095 8203 5687 9281 3722 8159 470 5735 4210 3694 2197 5422 816 7546 9965 2963
*/

//assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define pii         pair<ll int,ll int>
#define vpii        vector< pii >
#define vi          vector<ll int>
#define vs			vector< string >
#define vvi         vector< vector< ll > >
#define inf			1e18
#define all(it,a)   for(auto it=(a).begin();it!=(a).end();it++) 
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define repr(i,a,b) for(ll int i=a;i>b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define whatis(x)   cout << #x << " is " << x << "\n";
#define graph(n)    adj(n,vector< ll > () )
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll power_10[30];
const ll mod = 998244353;
vvi v(12,vi ());

void preprocess()
{
	power_10[0]=1;
	rep(i,1,30) power_10[i]=(power_10[i-1]*10)%mod;
}

void init()
{
	rep(i,0,12)
		v[i].clear();
}

ll g(ll n)
{
	ll ans=0;
	while(n) ans++,n/=10;
	return ans;
} 

ll f(ll n)
{
	vi d;d.clear();
	while(n) d.pb(n%10),n/=10;

	ll nd = sz(d);
	ll ans=0;

	ll ans2[12];
	rep(i,0,nd) ans2[i]=0;

	rep(i,0,nd)
	{
		ans2[i] = ((i-1>=0?ans2[i-1]:0)+(d[i]*power_10[2*i])%mod)%mod;
		if(ans2[i]>=mod) ans2[i]-=mod;
		ans2[i] = (ans2[i]+(d[i]*power_10[2*i+1])%mod)%mod;
		if(ans2[i]>=mod) ans2[i]-=mod;
	}

	rep(j,1,11)
	{
		if(j>=nd)
		{
			// whatis(j);
			// whatis(sz(v[j]))
			ans = (ans+(ans2[nd-1]*sz(v[j]))%mod)%mod;
			if(ans>mod) ans-=mod;
		}
		else
		{
			ll ans3=0;
			ans3 = ans2[j-1];
			rep(i,j,nd)
			{
				ans3 = (ans3+(2*((d[i]*power_10[i+j])%mod))%mod)%mod;
				if(ans3>=mod) ans-=mod;
			}

			ans = (ans+(ans3*sz(v[j]))%mod)%mod;
			if(ans>=mod) ans-=mod;
		}
	}
	return (ans)%mod;
}

int solve()
{
	init();
	ll n;cin>>n;
	ll ans=0;
	vi a(n);
	rep(i,0,n)
	{
		ll x;cin>>x;
		ll nd = g(x);
		v[nd].pb(x);
		a[i]=x;
	}

	rep(i,0,n)
	{
		ll t = f(a[i]);
		assert(t>0);
		ans = ans+t;
		if(ans>=mod) ans-=mod;
	}
	cout<<ans;
	cout<<"\n";
	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	preprocess();

	ll test_cases=1;
	// cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}