/*input
2 3

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
ll f(ll i,ll k)
{
	return k-i+1;
}
int solve()
{
	cin>>n>>m;
	for(ll i=1;i<=(n+1)/2;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			if(!(n%2==1 && i==(n+1)/2))
			{
				cout<<i<<" "<<j<<"\n";
				cout<<f(i,n)<<" "<<f(j,m)<<"\n";
			}
		}
	}

	if(n%2==1)
	{
		ll i=(n+1)/2;
		for(ll j=1;j<=(m+1)/2;j++)
		{
			if(f(j,m)!=j)
				cout<<i<<" "<<j<<"\n"<<i<<" "<<f(j,m)<<"\n";
			else
				cout<<i<<" "<<j<<"\n";
		}

	}
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