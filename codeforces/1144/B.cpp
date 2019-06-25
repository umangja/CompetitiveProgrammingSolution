/*input
6
5 1 2 4 6 3

*/


//assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define is_empty(v) v.empty()
#define vs			vector< string >
#define vvi			vector< vector< ll,ll > >
#define all(it,a)   for(auto it=(a).begin();it!=(a).end();it++) 
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define inf         1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define repr(i,a,b) for(ll int i=a;i>b;i--)
#define reprr(i,a,b) for(ll int i=a;i>=b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define sum(v)      accumulate(v.begin(),v.end(),(ll)0)
//map <long long int,long long int> ma;
//set <long long int, greater <long long int> > s;


int solve()
{
	ll n;cin>>n;
	vi a(n),o,e;
	rep(i,0,n)
	{
		cin>>a[i];
		if(a[i]%2==0)
			e.pb(a[i]);
		else
			o.pb(a[i]);
	}

	sort(e.begin(), e.end(),greater<> () );
	sort(o.begin(), o.end(),greater<> () );

	ll ans=0;
	if(sz(e)>sz(o))
	{
		ll in = sz(o);
		rep(i,in+1,sz(e))
			ans+=e[i];
	}
	else
	{
		ll in = sz(e);
		rep(i,in+1,sz(o))
		ans+=o[i];
	}

	cout<<ans;
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