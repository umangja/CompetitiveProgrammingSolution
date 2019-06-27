/*input
3 3
1 2
2 3
3 1

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

const ll N = 2e5+6;
vector< vector< ll > > adj(N,vector< ll > () );
vi degree(N,0);
vi visited(N,0);

int solve()
{
	ll n,m;cin>>n>>m; 
	rep(i,0,m)
	{
		ll x,y;cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
		degree[x]++;degree[y]++;
	}

	ll root = max_element(degree.begin(), degree.end()) - degree.begin();
	// cout<<root;
	queue< ll > q;
	q.push(root);
	visited[root]=1;
	
	while(sz(q)!=0)
	{
		ll u = q.front();
		q.pop();

		rep(i,0,sz(adj[u]))
		{
			ll ch = adj[u][i];
			if(visited[ch]==0)
			{
				visited[ch]=1;
				cout<<u<<" "<<ch<<"\n";
				q.push(ch);
			}
		}
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