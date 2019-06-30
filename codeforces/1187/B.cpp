/*input
9
arrayhead
5
arya
harry
ray
r
areahydra

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
	ll n;cin>>n;
	string s;cin>>s;
	vvi f(26,vector< ll > () );
	rep(i,0,n)
	{
		f[s[i]-'a'].pb(i);
	}

	ll m;cin>>m;
	rep(i,0,m)
	{
		string r;cin>>r;
		vi count(26,0);
		ll ans=0;
		rep(j,0,sz(r))
		{
			ll c = r[j]-'a';
			count[c]++;
			ans = max(ans,f[c][count[c]-1]);
		}
		cout<<ans+1<<"\n";
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