/*input
2
-100000 -100000
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

map< ll,vector< pair< ll,ll > > > m;

bool cmp(pair< ll,ll > a ,pair< ll,ll > b )
{
	if(b.S==a.S)
		return b.F>a.F;
	return b.S>a.S;
}

int solve()
{
	ll n;cin>>n;
	vi a(n);
	rep(i,0,n)
		cin>>a[i];

	rep(i,0,n)
	{
		ll sum=0;
		rep(j,i,n)
		{
			sum+=a[j];
			m[sum].pb(mp(i,j));
		}
	}



	ll count = 0;
	ll var;

	map< ll,set< pair< ll,ll > > > ans;
	all(it,m)
	{
		vector< pair< ll,ll > > s = it->S;
		sort(s.begin(), s.end(),cmp);

		ll k = it->F;
		ll sum=0;
		ll last = -1;

		// cout<<k<<"\n";
		all(it1,s)
		{
			pair< ll,ll > p = *it1;
			// cout<<p.F<<" "<<p.S<<"\n";
			if(p.F>last)
			{
				sum++;
				last = p.S;
				ans[k].insert(p);
			}
 		}

 		if(sum>count)
 		{
 			count=sum;
 			var =k;
 		}
	}

	cout<<sz(ans[var])<<"\n";
	all(it,ans[var])
	{
		cout<<it->F+1<<" "<<it->S+1<<"\n";
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