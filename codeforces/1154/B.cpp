/*input
2
2 8





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
	vi f(101,0);
	ll m=0;
	rep(i,0,n)
	{
		cin>>a[i];
		if(f[a[i]]==0)
		{
			m++;
		}
		f[a[i]]++;
	}
	// cout<<m;
	if(m>=4)
		cout<<"-1";
	else
	{
		vi t;
		rep(i,0,101)
		{
			if(f[i]>0)
				t.pb(i);
		}

		if(sz(t)==1)
			cout<<0;
		else if(sz(t)==2)
		{
			if((t[1]-t[0])%2==1)
				cout<<t[1]-t[0];
			else
				cout<<(t[1]-t[0])/2;
		}
		else if((t[1]-t[0])==(t[2]-t[1]))
			cout<<(t[1]-t[0]);
		else 
			cout<<"-1";
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