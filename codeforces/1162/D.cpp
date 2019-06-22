/*input
12 6
1 3
3 7
5 7
7 11
9 11
11 3


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
	ll n,m;cin>>n>>m;
	set< pair< ll,ll > > a;
	rep(i,0,m)
	{
		ll x,y;
		scanf("%lld %lld",&x,&y);
		a.insert(mp(min(x,y),max(x,y)));
	}

	vi div;
	div.pb(1);
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			div.pb(i);
			if(n/i!=i)
				div.pb(n/i);
		}
	}

	rep(i,0,sz(div))
	{
		ll sp = div[i];
		ll f=0;
		all(it,a)
		{
			ll x = (*it).F;
			ll y = (*it).S;
			x = (x+sp)%n;y = (y+sp)%n;
			if(x==0)
				x=n;
			if(y==0)
				y=n;

			pair< ll,ll > p = mp(min(x,y),max(x,y));
			if(a.find(p)!=a.end())
				continue;
			else
			{
			    // cout<<p.F<<" "<<p.S<<"\n";
				f=1;
				break;
			}
		}

		if(f==0)
		{
			cout<<"Yes";
			return 0;
		}
	}

	cout<<"No";
	return 0;
}

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);

	ll t=1;
	//cin>>t;
	while(t--)
		solve();
}