/*input
2 1
179
1329

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
	ll m;cin>>m;

	vector< vector< ll > > v(n,vector< ll > (m));
	vector< vector< ll > > a(n,vector< ll > () ),b(m,vector< ll > () );

	rep(i,0,n)
		rep(j,0,m)
			cin>>v[i][j];

	rep(i,0,n)
	{
		set< ll > s;
		rep(j,0,m)
			s.insert(v[i][j]);

		all(it,s)
			a[i].pb(*it);
	}

	rep(j,0,m)
	{
		set< ll > s;
		rep(i,0,n)
			s.insert(v[i][j]);

		all(it,s)
			b[j].pb(*it);

	}

	rep(i,0,n)
	{
		rep(j,0,m)
		{
			ll el = v[i][j];
			ll idx1 = lbnd(a[i].begin(), a[i].end(),el)-a[i].begin();
			ll idx2 = lbnd(b[j].begin(), b[j].end(),el)-b[j].begin();

			cout<<max(idx1,idx2)+1+max(sz(a[i])-idx1-1,sz(b[j])-idx2-1)<<" ";
		}
		cout<<"\n";
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