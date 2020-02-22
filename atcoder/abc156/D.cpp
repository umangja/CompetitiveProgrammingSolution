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

const ll mod = 1e9+7,N = 2e5+5;
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

ll inv(ll n)
{
	return power(n,mod-2)%mod;
}


ll ncr(ll n,ll r)
{
	if(r<=n && n>=0 && r>=0)
	{
		ll ans = 1;
		rep(i,0,r)
		{ 
			ans =( ans * (((n-i)*inv(i+1))%mod))%mod;
		}
		return ans;
	}
	else return 0;
}




int solve()
{
	ll n,a,b;cin>>n>>a>>b;

	// cout<<ncr(10,5)<<"\n";

	cout<<(((power(2,n)-1 + mod)%mod - ncr(n,a) +mod)%mod -ncr(n,b)+mod)%mod<<"\n";
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