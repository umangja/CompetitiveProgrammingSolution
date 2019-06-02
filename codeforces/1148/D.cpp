/*input
5
1 7
6 4
2 10
9 8
3 5


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

bool sortbysec(const pair<ll,ll> &a, 
              const pair<ll,ll> &b) 
{ 
    return (a.second < b.second); 
}

int solve()
{
	ll n;cin>>n;
	vector< pair< ll,ll > > inc,dec;
	map< pair< ll,ll > ,ll> m;
	rep(i,0,n)
	{
		ll x,y;cin>>x>>y;
		if(y>x)
			inc.pb(mp(x,y));
		else
			dec.pb(mp(x,y));

		m[mp(x,y)]=i+1;
	}

	sort(inc.begin(), inc.end(),sortbysec);
	reverse(inc.begin(), inc.end());

	sort(dec.begin(), dec.end(),sortbysec);
	vector< ll > ans1,ans2;

	ll last=0;
	if(sz(inc)!=0)
{		ans1.pb(m[inc[0]]);

		rep(i,0,sz(inc))
		{
			if(i==0)
				continue;

			if(inc[i].F<inc[last].S)
			{
				ans1.pb(m[inc[i]]);
				last=i;
			}
		}}
	last=0;
	if(sz(dec)!=0)
	{
		ans2.pb(m[dec[0]]);
		rep(i,0,sz(dec))
		{
			if(i==0)
				continue;

			if(dec[i].F>dec[last].S)
			{
				ans2.pb(m[dec[i]]);
				last=i;
			}
		}

	}

	if(sz(ans1)>=sz(ans2))
	{
		cout<<sz(ans1)<<"\n";
		rep(i,0,sz(ans1))
		cout<<ans1[i]<<" ";
	}
	else
	{
		cout<<sz(ans2)<<"\n";
		rep(i,0,sz(ans2))
		cout<<ans2[i]<<" ";
	}

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