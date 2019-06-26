/*input
3 5
1 2 1
2 3 0

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

ll MOD = 1e9+7;
vector< vector< ll > > adj(1e5+5,vector< ll > () );
vi visited(1e5+5,0);
ll ans=0;
void dfs(ll v)
{
	visited[v]=1;
	ans++;
	rep(i,0,sz(adj[v]))
	{
		if(visited[adj[v][i]]==0)
			dfs(adj[v][i]);
	}
}

ll p(ll x,ll y)
{
	if(y==0)
		return 1;

	if(y%2==0)
		return p((x*x)%MOD,y/2)%MOD;
	else
		return ((x%MOD)*(p((x*x)%MOD,y/2)%MOD))%MOD;
}


int solve()
{
	ll n,k;cin>>n>>k;
	
	rep(i,0,n-1)
	{
		ll x,y,c;cin>>x>>y>>c;
		if(c==1)
			continue;

		adj[x].pb(y);
		adj[y].pb(x);
	}

	ll ans1=0;
	rep(i,1,n+1)	
	{
		if(visited[i]==0)
		{
			ans=0;
			dfs(i);
			ans1 = (ans1+p(ans,k))%MOD;
		}
	}

	ans1 = (p(n,k)-ans1+MOD)%MOD;

	cout<<ans1;
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