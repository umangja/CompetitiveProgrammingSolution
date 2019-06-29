/*input
2 1
1 2
1 2


*/


//assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define vs			vector< string >
#define vvi         vector< vector< ll > >
#define all(it,a)   for(auto it=(a).begin();it!=(a).end();it++) 
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define inf         1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define repr(i,a,b) for(ll int i=a;i>b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define graph(n)    adj(n,vector< ll > () )

int solve()
{
	ll n,mm;cin>>n>>mm;
	vi a(n+1),pos(n+1);
	vector< pii > p(mm);
	vvi graph(n+1);
	vi allowed;
	
	rep(i,1,n+1)
	{
		cin>>a[i];
		pos[a[i]]=i;
	}

	ll nasha = a[n];
	map< pair< ll,ll >,ll > m;
	rep(i,0,mm)
	{
		cin>>p[i].F>>p[i].S;
		adj[p[i].F].pb(p[i].S);
		if(p[i].S==nasha)
			allowed.pb(p[i].F);
		m[p[i]]=1;
	}

	set< ll > s;
	ll ans=0;
	repr(i,n-1,0)
	{
		if(m[mp(a[i],nasha)]==0)
		{
			s.insert(a[i]);
		}
		else
		{
			ll f=1;
			all(it,s)
			{
				if(m[mp(a[i],*it)]==1)
					continue;
				else
					f=0;
			}

			if(f)
			{
				ans++;
				continue;
			}
			else
				s.insert(a[i]);
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