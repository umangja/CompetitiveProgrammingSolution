/*input
4 3
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
vi p(N+2);

inline ll normalize(ll x)
{
	x%=mod;
	if(x<0) x+=mod;
	return x;
}

ll power(ll x,ll y)
{
	assert(!(x==0 && y==0));
	x=normalize(x);
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
	ll ans =  power(x,mod-2);
	return ans;
}

ll f(ll n,ll k)
{
	ll mul=1;
	for(ll j=1;j<=k+1;j++)
	{
		mul = (mul*(n-j))%mod;
		mul = (mul*inv_mod(-j))%mod;
		// cout<<mul<<"\n";
	}
	ll ans = p[0]*mul;
	for(ll i=1;i<=k+1;i++)
	{
		mul = (mul*(n-i+1))%mod;
		mul = (mul*inv_mod(n-i))%mod;
		mul = (mul*(normalize(i-1-k-1)))%mod;
		mul = (mul*inv_mod(i))%mod;
		ans = (ans+(p[i]*mul)%mod)%mod;
	}

	return ans;
}

int solve()
{

	ll n,k;cin>>n>>k;
	p[0]=0;
	rep(i,1,k+2)
		p[i] = (p[i-1]+power(i,k))%mod;

	// cout<<p[1]<<" "<<p[2]<<"\n";
	if(n<k+2)
		cout<<p[n];
	else
		cout<<f(n,k);

	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll t=1;
	while(t--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}