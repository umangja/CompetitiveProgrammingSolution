/*input
2
4 6
1 2
1 3
1 4
2 3
2 4
3 4
6 8
2 5
5 4
4 3
4 1
1 3
2 3
2 6
5 6

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
const ll N = 2e5+5;


int solve()
{
	ll n,m;cin>>n>>m;
	vector< vector< ll > > adj(n+1,vector< ll > () );
	vi ans(n+1,-1);
	rep(i,0,m)
	{
		ll x,y;cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	ll c=1;
	ans[1]=c;
	queue< ll > q;
	q.push(c);

	while(!q.empty())
	{
		ll v = q.front();
		q.pop();

		for(ll i=0;i<sz(adj[v]);i++)
		{
			if(ans[adj[v][i]]==-1)
			{
				ans[adj[v][i]]=1-ans[v];
				q.push(adj[v][i]);
			}
		}
	}

	ll t=0;
	rep(i,1,n+1)
		t+=ans[i];

	// cout<<t<<"\n";
	if(t<=n/2)
	{
		cout<<t<<"\n";
		rep(i,1,n+1)
		{
			if(ans[i]==1)
				cout<<i<<" ";
		}
	}
	else
	{
		cout<<n-t<<"\n";
		rep(i,1,n+1)
		{
			if(ans[i]==0)
				cout<<i<<" ";
		}
	}

	cout<<"\n";

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll t=1;
	cin>>t;
	while(t--)
		solve();
}