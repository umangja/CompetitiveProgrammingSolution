/*input
4 2
1 1 4
0 2 3



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
	ll n,m;cin>>n>>m;
	vi ans(n+1);
	vpii ranges,tests,temp;
	rep(i,0,m)
	{
		ll t,l,r;cin>>t>>l>>r;
		if(t==0)
			ranges.pb(mp(l,r));
		else
			tests.pb(mp(l,r));
	}

	sort(tests.begin(), tests.end());

	ans[0]=9000;
	rep(i,1,n+1)	
		ans[i]=ans[i-1]-1;

	rep(i,0,sz(tests))
	{
		pii p = tests[i];
		rep(j,p.F+1,p.S+1)
			ans[j]=ans[p.F];
	}


	rep(i,0,sz(ranges))
	{
		ll ss=0;
		rep(j,ranges[i].F+1,ranges[i].S+1)
		{
			if(ans[j]<ans[j-1])
				ss=1;
		}
		if(!ss)
		{
			cout<<"NO";
			return 0;
		}
	}

	cout<<"YES\n";
	rep(i,1,n+1)
	cout<<ans[i]<<" ";


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