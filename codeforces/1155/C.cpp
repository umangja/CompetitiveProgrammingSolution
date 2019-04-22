/*input
3 1
2 12 32
5 




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
	vi x(n),p(m);
	rep(i,0,n)
	{
		cin>>x[i];
	}
	rep(i,0,m)
	cin>>p[i];

	vi dif(n-1);
	rep(i,1,n)
	{
		dif[i-1] = x[i]-x[0];
	}

	ll g=dif[0];
	rep(i,0,n-1)
	{
		g = __gcd(g,dif[i]);
	}

	// cout<<g;

	if(n==2)
	{
		rep(i,0,m)
		{
			if((x[1]-x[0])%p[i]==0)
			{
				cout<<"YES\n"<<x[0]<<" "<<i+1;
				return 0;
			}
		}

		cout<<"NO";
		return 0;
	}

	rep(i,0,m)
	{
		if(g%p[i]==0)
		{
			cout<<"YES\n"<<x[0]<<" "<<i+1;
			// cout<<x[0]
			return 0;
		}
	}

	cout<<"NO";
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