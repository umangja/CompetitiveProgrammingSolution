/*input
2 1 2
-1000000000 1000000000



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
	ll n,m,k;cin>>n>>m>>k;vi a(n);
	vppi b;
	rep(i,0,n)
	{
		cin>>a[i];
		b.pb(mp(a[i],i));
	}

	sort(b.begin(), b.end(),greater< pair<ll,ll> > ());
	ll s=0;
	vi ind;
	rep(i,0,m*k)
	{
		s+=b[i].F;
		ind.pb(b[i].S);
	}

	sort(ind.begin(), ind.end());
	
	vvi id(k,vector< ll > (m));
	rep(i,0,m*k)
		id[i/m].pb(ind[i]);

	cout<<s<<"\n";
	rep(i,0,k-1)
	{
		cout<<id[i][sz(id[i])-1]+1<<" ";
	}

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