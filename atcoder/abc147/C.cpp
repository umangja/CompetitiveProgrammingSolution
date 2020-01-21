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
const ll N = 15;
ll n;
vector< vpii > a(N, vpii ());
ll ans = 0;
void fun(ll mask)
{
	vi honest;
	vi not_h;
	rep(i,0,n) if(((mask>>i)&1)==1)
	{
		honest.pb(i);
		rep(j,0,sz(a[i])) if(a[i][j].S==1) honest.pb(a[i][j].F); else not_h.pb(a[i][j].F);
	} 
	ll f=1;
	rep(i,0,sz(honest)) if(((mask>>honest[i])&1)!=1) f=0;
	rep(i,0,sz(not_h)) if(((mask>>not_h[i])&1)!=0) f=0;
	set<ll> s(honest.begin(), honest.end());
	if(f) ans=max(ans,sz(s));
}

int solve()
{
	cin>>n;
	rep(i,0,n)
	{
		ll m;cin>>m;
		rep(j,0,m)
		{
			ll x,y;cin>>x>>y;
			x--;
			a[i].pb(mp(x,y));
		}
	}

	rep(i,0,1<<n) fun(i);
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