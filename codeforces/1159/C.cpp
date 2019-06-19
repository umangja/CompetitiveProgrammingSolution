/*input
2 3
1 0
1 1 2



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
	vi a(n),b(m);
	rep(i,0,n)
		cin>>a[i];
	rep(j,0,m)
		cin>>b[j];

	// ll b_min(m,0);
	sort(a.begin(), a.end(),greater<> () );
	sort(b.begin(), b.end(),greater<> () );

	rep(i,0,m)
	{
		ll df = b[i]-a[0];
		if(df<0)
		{
			cout<<"-1";
			return 0;
		}
	}


	ll ans=0;
	rep(i,0,n)
	{
		ans+=m*a[i];
	}
	if(m==1)
	{
		cout<<ans;
		return 0;
	}

	// cout<<ans;

	rep(i,0,m-1)
	{
		ll df = b[i]-a[0];
		ans+=df;
	}

	if(n>=2 && b[m-1]!=a[0])
		ans+=b[m-1]-a[1];


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