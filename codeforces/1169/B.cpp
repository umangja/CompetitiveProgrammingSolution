/*input
300000 5
1 2
1 2
1 2
1 2
1 2






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
	vector< pair< ll,ll > > v(m);
	rep(i,0,m)
	{
		ll x,y;
		cin>>x>>y;
		v[i]=mp(x,y);
	}

	rep(k,0,2)
	{
		ll x = k*v[0].F+(1-k)*v[0].S;
		ll i=1;
		for(;i<m;i++)
		{
			if(v[i].F==x || v[i].S==x)
				continue;
			else
			{
				rep(k1,0,2)
				{
					ll y = k1*v[i].F+(1-k1)*v[i].S;
					ll j=i+1;
					for(;j<m;j++)
					{
						if(v[j].F==x || v[j].F==y ||v[j].S==x ||v[j].S==y )
							continue;
						else
							break;
					}
					if(j==m)
					{
						cout<<"YES";
						return 0;
					}
				}

				break;
			}
		}
		if(i==m)
		{
			cout<<"YES";
			return 0;
		}

	}
	cout<<"NO";
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