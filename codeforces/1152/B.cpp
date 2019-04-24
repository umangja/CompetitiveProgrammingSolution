/*input
39



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
	ll x;cin>>x;
	ll n;
	ll count=0;
	vi ans;
	double c;
	ll t=40;
	while(t--)
	{
		ll lbp = floor(log2(x))+1;
		// cout<<lbp;
		ll mask = (1<<(lbp))-1;
		// cout<<mask;
		ans.pb(lbp);

		count++;
		x = x^mask;
		// cout<<x;

		c =log2(x+1); 
		if( floor(c) ==c )
		{
			// cout<<x;
			break;
		}

		// cout<<x<<" ";
		count++;
		x++;
		c =log2(x+1); 
		if( floor(c) ==c )
		{
			// cout<<x;
			break;
		}

		// cout<<x<<" ";

	}
	// cout<<x;
	cout<<count<<"\n";
	rep(i,0,sz(ans))
	cout<<ans[i]<<" ";

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