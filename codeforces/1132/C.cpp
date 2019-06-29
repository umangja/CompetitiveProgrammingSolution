/*input
4 4
1 1
2 2
2 3
3 4


*/


//assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define pii         pair<ll int,ll int>
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
	ll n,q;
	cin>>n>>q;
	vector< pair< ll,ll > > v;
	vi a(n+1,0);
	ll ans=-1;
	rep(i,0,q)
	{
		ll x,y;cin>>x>>y;
		v.pb(mp(x,y));
		rep(j,x,y+1)
			a[j]++;
		// rep(i,1,n+1)
		// 	cout<<a[i]<<" ";
		// cout<<"\n";
	}


	rep(i,0,q)
	{
		rep(j,v[i].F,v[i].S+1)
			a[j]--;

		ll tot=0;
		rep(j,1,n+1)
			tot+=(a[j]>=1);

		vi p(n+1,0);
		rep(j,1,n+1)
			p[j] = (a[j]==1);

		rep(j,1,n+1)
			p[j]+=p[j-1];

		ll mini = 1e18;
		rep(j,0,q)
		{
			if(j==i)
				continue;

			ll k = p[v[j].S]-p[v[j].F-1];
			mini=min(mini,k);
		}

		ans = max(ans,tot-mini);

		rep(j,v[i].F,v[i].S+1)
			a[j]++;

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