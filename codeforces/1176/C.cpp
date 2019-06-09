/*input
12
4 4 4 4 15 8 16 15 16 23 42 8





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
	vi v(n);
	vector< vector< ll > > a(6,vector< ll >() );
	map< ll,ll > m;
	m[4]=0;
	m[8]=1;
	m[15]=2;
	m[16]=3;
	m[23]=4;
	m[42]=5;

	rep(i,0,n)
	{
		cin>>v[i];
		a[m[v[i]]].pb(i);
	}

	ll count=0;
	vi last(6,0);

	rep(i,0,sz(a[0]))
	{
		ll ind = a[0][i];
		// cout<<ind<<" ";
		rep(j,1,6)
		{
			auto it = ubnd(a[j].begin()+last[j], a[j].end(),ind);
			// cout<<*it<<" ";
			if(it==a[j].end())
			{
				cout<<n-count;
				return 0;
			}
			else
			{
				ind = *it;
				last[j] = it - a[j].begin()+1;
			}
		}
		// cout<<"\n";
		count+=6;
	}
cout<<n-count;
return 0;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll t=1;
	// cin>>t;
	while(t--)
		solve();
}