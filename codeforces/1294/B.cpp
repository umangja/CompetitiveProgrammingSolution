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

vpii p;
int solve()
{
	p.clear();
	ll n;cin>>n;
	rep(i,0,n)
	{
		ll x,y;cin>>x>>y;
		p.pb(mp(x,y));
	}

	sort(p.begin(), p.end());

	ll f=1;
	string ans;
	rep(i,0,p[0].F) ans+='R';
	rep(i,0,p[0].S) ans+='U';
	rep(i,1,n)
	{
		if(p[i].S<p[i-1].S) f=0;
		else
		{
			rep(j,0,p[i].F-p[i-1].F) ans+='R';
			rep(j,0,p[i].S-p[i-1].S) ans+='U';
		}
	}
	if(f) cout<<"YES\n"<<ans<<"\n";
	else cout<<"NO\n";

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