/*input
5
1 1 1 1 1




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
	vi a(n);
	ll s=0;
	rep(i,0,n)
	{
		cin>>a[i];
		s+=a[i];
	}
	ll ans=0;
	// cout<<s;
	if(s%3==0 && n>=3)
	{
		s=s/3;
		vi p;
		ll cs=0;
		rep(i,0,n)
		{
			cs+=a[i];
			if(cs==2*s && i!=0 && i!=n-1)
				p.pb(i);
		}
		cs=0;
		ll t = sz(p);
		// cout<<t;
		rep(i,0,n)
		{
			cs+=a[i];
			if(cs==s)
			{

				ll j = ubnd(p.begin(), p.end(),i)-p.begin();
				ans+=t-j;
			}
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