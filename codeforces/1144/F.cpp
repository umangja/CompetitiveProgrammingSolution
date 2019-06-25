/*input
6 5
1 5
2 1
1 4
3 1
6 1

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

string ans="";
ll f=0;
vector< ll > color(2e5+5,-1),visited(2e5+5,0);
vector< vector< ll > > adj(2e5+5,vector< ll > () );

void dfs(ll v,ll c)
{
	visited[v]=1;
	color[v]=c;
	rep(i,0,sz(adj[v]))
	{
		ll ch = adj[v][i];
		if(visited[ch]==0)
		{
			dfs(ch,1-c);
		}
		else if(ch!=v && color[ch]==c)
			f=1;
	}
}

int solve()
{
	ll n,m;cin>>n>>m;
	vector< pair< ll,ll > > v;
 	rep(i,0,m)
	{
		ll x,y;cin>>x>>y;
		v.pb(mp(x,y));
		adj[x].pb(y);
		adj[y].pb(x);
	}

	dfs(1,0);

	if(f==1)
	{
		cout<<"NO\n";
		return 0;
	}
	
	cout<<"YES\n";

	rep(i,0,m)
	{
		auto p = v[i];
		if(color[p.F]==1)
			ans+='1';
		else
			ans+='0';
	}

	cout<<ans;
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