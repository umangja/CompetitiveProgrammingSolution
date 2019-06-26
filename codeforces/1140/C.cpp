/*input
7 3
12 31
112 4
100 100
200 101
200 99
13 55
55 50


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

bool cmp(pair< ll,ll > a,pair< ll,ll > b)
{
	if(a.S==b.S)
		b.F>a.F;
	return b.S>a.S;
}
int solve()
{
	ll n,k,ans = -1;cin>>n>>k;
	vector< pair< ll,ll > > v(n);
	rep(i,0,n)
	{
		ll x,y;cin>>x>>y;
		v[i]=mp(x,y);
	}

	sort(v.begin(), v.end(),cmp);
	// rep(i,0,n)
		// cout<<v[i].F<<" "<<v[i].S<<"\n";

	set< pair< ll,ll > > s;
	ll sum =0;
	repr(i,n-1,-1)
	{
		ans = max(ans,v[i].S*(sum+v[i].F));

		s.insert(mp(v[i].F,i));
		sum+=v[i].F;

		while(sz(s)>(k-1))
		{
			auto it = s.begin();
			sum-=it->F;
			s.erase(*it);
		}

	}	

	cout<<ans;
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