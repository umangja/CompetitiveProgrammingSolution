/*input
1000000 2
-7 4


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
//map <long long int,long long int> ma;
//set <long long int, greater <long long int> > s;


int solve()
{
	ll h,n;cin>>h>>n;
	vi a(n);
	ll sum=0;
	ll mini = 1e18;
	rep(i,0,n)
	{
		cin>>a[i];
		sum+=a[i];
		mini = min(sum,mini);
		if(h+sum<=0)
		{
			cout<<i+1;
			return 0;
		}
	}

	if(sum>=0)
	{
		cout<<"-1";
		return 0;
	}

	sum*=-1;mini*=-1;

	ll ans = (h-mini+sum-1)/sum;
	h-=ans*sum;
	// cout<<sum<<" "<<mini<<" "<<h<<" "<<ans<<"\n";

	sum=0;
	rep(i,0,n)
	{
		sum+=a[i];
		if(h+sum<=0)
		{
			cout<<ans*n+i+1;
			return 0;
		}
	}

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