/*input
2
2 1
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
	vector< ll > w(n),h(n),m1(n),m2(n);
	ll s=0;
	m1[0]=-inf,m2[n-1]=-inf;
	rep(i,0,n)
	{
		cin>>w[i]>>h[i];
		s+=w[i];
		if(i==0)
			continue;

		m1[i]=max(m1[i-1],h[i-1]);
	}

	repr(i,n-1,-1)
	{
		if(i==n-1)
			continue;
		m2[i]=max(m2[i+1],h[i+1]);
	}

	rep(i,0,n)
	{
		cout<<(s-w[i])*(max(m1[i],m2[i]))<<" ";
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