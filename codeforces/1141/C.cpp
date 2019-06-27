/*input
5
1 1 1 1

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
	vi q(n),p(n+1);
	rep(i,1,n)
		cin>>q[i];

	vi pf(n);
	pf[1] = q[1];
	rep(i,2,n)
		pf[i] = q[i]+pf[i-1];

	ll maxi = -1e18;
	ll mini = n+1;
	rep(i,1,n)
	{
		if(pf[i]>maxi)
		{
			maxi = pf[i];
			p[1]=n-maxi;
		}
	}

	if(p[1]==n+1)
		p[1]=n;

	rep(i,2,n+1)
		p[i] = q[i-1]+p[i-1];

	ll f=1;
	map< ll,ll > m;
	rep(i,1,n+1)
	{
		if(p[i]>=1 && p[i]<=n && m[p[i]]==0)
		{
			m[p[i]]++;
			continue;
		}
		else
			f=0;
	}

	if(!f)
		cout<<"-1";
	else
	{
		rep(i,1,n+1)
			cout<<p[i]<<" ";
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