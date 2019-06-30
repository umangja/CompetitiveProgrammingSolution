/*input
6 9

*/


//assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define pii         pair<ll int,ll int>
#define vppi        vector< pii >
#define vi          vector<ll int>
#define vs			vector< string >
#define vvi         vector< vector< ll > >
#define all(it,a)   for(auto it=(a).begin();it!=(a).end();it++) 
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define inf         1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define repr(i,a,b) for(ll int i=a;i>b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define graph(n)    adj(n,vector< ll > () )

int solve()
{
	ll N,b;cin>>N>>b;
	vector< pii > pd;

	for(ll i=2;i*i<=b;i++)
	{
		ll c=0;
		while(b%i==0)
		{
			c++;
			b/=i;
		}
		if(c)
			pd.pb(mp(i,c));
	}

	if(b!=1)
		pd.pb(mp(b,1));


	ll ans=1e18;
	rep(i,0,sz(pd))
	{
		ll p = pd[i].F;
		ll n=N;
		ll c=0;
		// cout<<p<<" "<<pd[i].S<<"\n";
		while(n)
		{
			c+=n/p;
			n/=p;
		}

		ans=min(ans,c/pd[i].S);
	}

	cout<<ans;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll t=1;
	//cin>>t;
	while(t--)
		solve();
}