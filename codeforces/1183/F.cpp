/*input
3
4
5 6 15 30
4
10 6 30 15
3
3 4 6

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
	vi a;
	map< ll,ll > m;
	rep(i,0,n)
	{
		ll x;cin>>x;
		m[x]++;
		if(m[x]==1)
			a.pb(x);		
	}

	n = sz(a);
	sort(a.begin(), a.end() ,greater< ll > () );
	ll ans=-1;

	rep(i,0,n)
	{
		ll el = a[i];
		set< ll > div;
		for(ll j=2;j*j<=el;j++)
		{
			if(el%j==0)
			{
				div.insert(j);
				if(el/j!=j)
					div.insert(el/j);
			}
		}

		ll x=0,y=0;
		rep(j,i+1,n)
		{
			auto it = div.find(a[j]);

			if(it!=div.end())
				continue;

			if(it==div.end() && x==0)
			{
				x=a[j];
				for(ll j=2;j*j<=x;j++)
				{
					if(x%j==0)
					{
						div.insert(j);
						if(x/j!=j)
							div.insert(x/j);
					}
				}
			}
			else if(it==div.end() && y==0)
			{
				y=a[j];
				break;
			}
		}

		ans = max(ans,x+y+el);
	}

	cout<<ans<<"\n";
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll t=1;
	cin>>t;
	while(t--)
		solve();
}