/*input

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
#define inf			(ll)1e18
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

const ll mod = 1e9+7;
ll power(ll x,ll y)
{
	ll ans=1;
	while(y)
	{
		if(y&1) ans = (ans*x)%mod;
		y>>=1;
		x=(x*x)%mod;
	}
	return ans;
}
		
int solve()
{
	ll n,k;cin>>n>>k;

	vi dp(k+1);

	for(ll i = k;i>=1;i--)
	{
		dp[i] = power(k/i,n);
		for(ll j = 2*i;j<=k;j+=i) dp[i] = (dp[i]-dp[j]+mod)%mod;
		// whatis(dp[i]);
	}

	ll ans=0;
	rep(i,1,k+1) ans = (ans+(i*dp[i])%mod)%mod;

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
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}
