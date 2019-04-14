/*input
4
2 3
3 4
4 1
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
	ll n;cin>>n;
	ll a[n+1][2];

	rep(i,0,n)
	{
		cin>>a[i+1][0]>>a[i+1][1];
	}

	vi ans(n+1);
	ans[1]=1;
	ll l = 1;
	rep(i,2,n+1)
	{
		ll c,d;
		c = a[l][0];
		d = a[l][1];

		// cout<<c<<" "<<d<<"\n";

		if(a[c][0]==d || a[c][1]==d)
		{
			ans[i]=c;
			ans[i+1]=d;
		}
		else 
		{
			ans[i]=d;
			ans[i+1]=c;
		}

		l=ans[i+1];
		i+=1;	
	}

	rep(i,1,n+1)
		cout<<ans[i]<<" ";
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