/*input
3
3
0 1 1 0 1 1 0

100000000
1 0 0 0 1 0 1
1
1 0 0 0 0 0 0

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
	ll k;cin>>k;
	ll n=7;
	vi a(n);
	ll w=0;
	rep(i,0,n)
	{
		cin>>a[i];
		w+=a[i];
	}

	// vi b(7);
	// b[0]=a[0];
	// rep(i,1,7)
	// 	b[i]=b[i-1]+a[i];

	ll t=0;
	if(k>w)
	{
		ll p = (k-w)/w;
		k-=p*w;
		t+=7*p;
	}

	while(k>w)
	{
		k-=w;
		t+=7;
	}

	ll tt=inf;
	if(k)
	{
		ll c=18;
		rep(l,1,8)
		{
			rep(i,0,7)
			{
				ll c=0;
				ll ans =0;
				for(ll j=i;c<l;j=(j+1)%7)
				{
					c++;
					ans+=a[j];
				}
				if(ans>=k)
				{
					// cout<<ans<<k;
					tt=l;
					cout<<t+tt<<"\n";
					return 0;
				}
			}
		}
	}

	
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