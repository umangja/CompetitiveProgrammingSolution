/*input
5 3
0 0 0 1 2

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

ll n,m;
vi a(n);
ll f(ll mid)
{
	ll last = 0;
	rep(i,0,n)
	{
		if(a[i]>=last)
		{
			if(m-a[i]+last<=mid)
				continue;
			else
				last=a[i];
			
		}
		else
		{
			if(a[i]+mid>=last)
				continue;
			else
				return 0;
		}
	}
	// cout<<last<<"\n";
	return 1;
}

int solve()
{
	cin>>n>>m;
	rep(i,0,n)
	{
		ll c;cin>>c;
		a.pb(c);
	}

	ll low=0,high=m+1;
	while(low<high)
	{
		ll mid = low+(high-low)/2;
		if(f(mid))
			high=mid;
		else
			low=mid+1;
	}

	cout<<low;
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