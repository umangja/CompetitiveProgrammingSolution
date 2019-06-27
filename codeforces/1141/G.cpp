/*input
10 2
10 3
1 2
1 3
1 4
2 5
2 6
2 7
3 8
3 9


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
vector< vector< ll > > adj(N,vector< ll > () );
vi dg(N,0);
vi visited(N,0);
vi col(N);
ll c;
map< pair< ll,ll >,ll > m;

void dfs(ll u,ll v,ll cl)
{
	visited[u]=1;
	col[m[mp(u,v)]]=cl;
	rep(i,0,sz(adj[u]))
	{
		ll ch = adj[u][i];
		if(visited[ch]==0)
		{
			cl = (cl+1)%c;
			if(cl==0)
				cl=c;
			dfs(ch,u,cl);
		}
	}
}

int solve()
{
	ll n,k;cin>>n>>k;
	rep(i,0,n-1)
	{
		ll x,y;cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
		m[mp(x,y)]=i;
		m[mp(y,x)]=i;
	}

	rep(i,1,n+1)
		dg[i] = sz(adj[i]);

	sort(dg.begin(), dg.end(),greater<ll> () );
	c = dg[k];

	cout<<c<<"\n";
	dfs(1,-1,0);

	rep(i,0,n-1)
		cout<<col[i]<<" ";

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