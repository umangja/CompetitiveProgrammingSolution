/*input
1 10
5 3

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
	ll n,k;cin>>n>>k;
	ll a,b;cin>>a>>b;

	ll N = n*k;
	ll ans1=1e18,ans2=-1e18;
	for(ll i=-1;i<2;i+=2)
	{
		for(ll j=-1;j<2;j+=2)
		{
			ll v = (a*i+b*j+n*k)%N;
			ll l;
			rep(i1,0,n+1)
			{
				l = i1*k-v;
				if(l>0)
				{
					ans1 = min(ans1,N/__gcd(N,l));
					ans2 = max(ans2,N/__gcd(N,l));
				}
			}
		}
	}

	cout<<ans1<<" "<<ans2;
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