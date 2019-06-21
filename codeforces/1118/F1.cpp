/*input
3
1 1 2
2 3
1 3

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

vi col(3e5+5);
vector< vector< ll > > adj(3e5+5,vector< ll > () );
vi visited(3e5+5,0);
ll ans=0,red=0,blue=0;

pair< ll,ll > dfs(ll v)
{
	visited[v]=1;
	ll r=0,b=0;

	if(col[v]==1)
		r++;
	else if(col[v]==2)
		b++;


	rep(i,0,sz(adj[v]))
	{
		ll ch = adj[v][i];
		if(visited[ch]==0)
		{
			// cout<<"YES";
			pair< ll,ll > p  = dfs(ch);
			// cout<<p.F<<" "<<p.S<<" "<<ch<<"\n";
			r+=p.F;
			b+=p.S;

			if((p.F==red && p.S==0)||(p.F==0 && p.S==blue ))
				ans++;
			
		}
	}

	return mp(r,b);
}

int solve()
{
	ll n;cin>>n;
	ll r;
	rep(i,1,n+1)
	{
		cin>>col[i];
		if(col[i]==1)
			red++;
		else if(col[i]==2)
			blue++;
	}

	rep(i,0,n-1)
	{
		ll x,y;cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	dfs(1);
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