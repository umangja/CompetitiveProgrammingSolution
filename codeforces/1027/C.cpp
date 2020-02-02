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

vi ans(2);
ll min_ans = inf;

double fun(ll x,ll y)
{
	return (double)((x+y)*(x+y))/(double)(x*y);
}

int solve()
{
	ll n;cin>>n;
	map<ll,ll> m;
	vi a(n);
	vpii b;
	rep(i,0,n) cin>>a[i],m[a[i]]++;
	all(it,m) if(it->S>=2) b.pb(mp(it->F,it->S));  

	sort(b.begin(), b.end());
	n=sz(b);
	rep(i,0,n) if(b[i].S>=4) 
	{
		cout<<b[i].F<<" "<<b[i].F<<" "<<b[i].F<<" "<<b[i].F<<"\n";
		return 0;
	} 

	double mn = inf;

	rep(i,0,n)
	{
		ll x = b[i].F;
		if(i+1<n)
		{
			double v = fun(x,b[i+1].F);
			if(v<mn) mn=v,ans[0]=x,ans[1]=b[i+1].F;
		} 
		if(i-1>=0)
		{
			double v = fun(x,b[i-1].F);
			if(v<mn) mn=v,ans[0]=x,ans[1]=b[i-1].F;
		} 
	}

	cout<<ans[0]<<" "<<ans[0]<<" "<<ans[1]<<" "<<ans[1]<<"\n";

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
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}