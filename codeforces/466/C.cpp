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


int solve()
{
	ll n;cin>>n;
	vi a(n);
	ll s=0;
	rep(i,0,n) cin>>a[i],s+=a[i];
	ll ans=0;
	if(s%3==0)
	{
		s/=3;
		ll ts=0;
		vvi v(3,vi ());
		rep(i,0,n)
		{
			ts+=a[i];
			if(ts==s)   v[0].pb(i);
			if(ts==2*s) v[1].pb(i);
			if(ts==3*s) v[2].pb(i);
		}

		rep(i,0,sz(v[1]))
		{
			ll idx1 = v[1][i];
			if(idx1==n-1) continue;
			ll idx2 = lbnd(v[0].begin(), v[0].end(),idx1)-v[0].begin();
			ans+=idx2;
		}
	} 
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
	// cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}