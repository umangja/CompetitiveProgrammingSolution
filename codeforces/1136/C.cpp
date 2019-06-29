/*input
1 4
5 6 7 8
5 1 1 8

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

void fun()
{
	cout<<"NO";
	exit(0);
}

int solve()
{
	ll n,m;cin>>n>>m; 
	ll N = 1500;
	vvi a(N,vector<ll> () ),b(N,vector<ll> () );

	rep(i,0,n)
	{
		rep(j,0,m)
		{
			ll x;cin>>x;
			a[i+j].pb(x);
		}
	}

	rep(i,0,n)
	{
		rep(j,0,m)
		{
			ll x;cin>>x;
			b[i+j].pb(x);
		}
	}

	rep(i,0,N)
	{
		sort(a[i].begin(), a[i].end());
		sort(b[i].begin(), b[i].end());
		if(a[i]!=b[i])
			fun();
	}


	cout<<"YES";

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