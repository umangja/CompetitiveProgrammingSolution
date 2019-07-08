/*input
2 3 10
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
const ll mod = 1e9+7,N = 1e6+6;
ll fact[N],fact_inv[N];

ll power(ll x,ll y)
{
	assert(!(x==0 && y==0));
	ll ans=1;
	while(y)
	{
		if(y&1) ans=(ans*x)%mod;
		y>>=1;
		x=(x*x)%mod;
	}
	return ans;
}

ll inv_mod(ll x)
{
	return power(x,mod-2);
}

void preprocess()
{
	fact[0]=1;
	fact_inv[0]=1;
	rep(i,1,N)
	{
		fact[i]=(fact[i-1]*i)%mod;
		fact_inv[i]=(fact_inv[i-1]*inv_mod(i))%mod;
	}
}

ll ncr(ll n,ll r)
{
	ll ans = fact[n];
	ans = (ans*fact_inv[n-r])%mod;
	ans = (ans*fact_inv[r])%mod;
	return ans;
}

int solve()
{
	ll a,b,n,ans=0;cin>>a>>b>>n;
	for(ll x=0;x<=n;x++)
	{
		ll s = a*x+b*(n-x);
		ll f=1;
		while(s)
		{
			ll d=s%10;
			s/=10;
			if(d==a||d==b) continue;
			else {f=0;break;}
		}



		if(f)
			ans=(ans+ncr(n,x))%mod;
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

	ll t=1;
	preprocess();
	while(t--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}