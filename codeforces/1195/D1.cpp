/*input
5
1000000000 1000000000 1000000000 1000000000 1000000000


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
void preprocess()
{
	power_10[0]=1;
	rep(i,1,30)
		power_10[i]=(power_10[i-1]*10)%mod;
}
ll N;
ll f(ll n)
{
	vi d;
	d.clear();
	while(n)
	{
		d.pb(n%10);
		n/=10;
	}

	ll ans=0;
	rep(i,0,sz(d))
	{
		ans = ans+d[i]*power_10[2*i];
		if(ans>=mod)
			ans-=mod;
		ans = ans+d[i]*power_10[2*i+1];
		if(ans>=mod)
			ans-=mod;
	}
	return (ans*N)%mod;
}

int solve()
{
	ll n;cin>>n;
	N=n;
	ll ans=0;
	rep(i,0,n)
	{
		ll x;cin>>x;
		ans = ans+f(x);
		if(ans>mod)
			ans-=mod;
	}

	cout<<ans;
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
	//cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}