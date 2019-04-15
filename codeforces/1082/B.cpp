/*input
3
SSS



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
	vector< char  > v(n);
	string s;cin>>s;
	
	rep(i,0,n)
		v[i]=s[i];

	vector< pair< ll,ll > > l;
	rep(i,0,n)
	{
		if(v[i]=='G')
		{
			// cout<<i;
			ll j=i;
			for(;j<n;j++)
			{
				if(v[j]!='G')
					break;
			}

			l.pb(mp(i,j-1));
			i=j;
		}
	}

	ll ans=0;
	// cout<<sz(l);
	if(sz(l)==1)
		ans = l[0].S-l[0].F+1;
	else if(sz(l)>1)
		ans = l[0].S-l[0].F+2;


	rep(i,1,sz(l))
	{
		if(l[i].F-l[i-1].S==2)
		{
			if(sz(l)>=3)
				ans=max(ans,l[i].S-l[i-1].F+1);
			else
				ans=max(ans,l[i].S-l[i-1].F);
		}
		else
		{
			ans=max(ans,l[i].S-l[i].F+2);
		}
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