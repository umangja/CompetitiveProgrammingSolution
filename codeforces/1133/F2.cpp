/*input
4 5 
1 2
1 3
1 4
2 3
3 4




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

ll d;
const ll N = 2e5+6;
vector< vector< ll > > adj(N,vector< ll > () ),ans(N,vector< ll > () );
vi degree(N,0);
vi visited(N,0);
vector< pair< ll,ll > > ansf;
set< ll > s;

void dfs(ll v)
{
	visited[v]=1;
	rep(i,0,sz(adj[v]))
	{
		ll ch = adj[v][i];
		if(visited[ch]==0)
		{
			ans[v].pb(ch);
			ans[ch].pb(v);
			dfs(ch);
		}
	}
}

int solve()
{
	ll n,m;cin>>n>>m>>d; 
	rep(i,0,m)
	{
		ll x,y;cin>>x>>y;
	

		adj[x].pb(y);
		adj[y].pb(x);
		degree[x]++;degree[y]++;
		if(x==1)
			s.insert(y);
		else if(y==1)
			s.insert(x);
	}

	ll cnt=0;
	visited[1]=1;
	rep(i,0,sz(adj[1]))
	{
		ll ch  =adj[1][i];
		if(visited[ch]==0)
		{
			cnt++;
			
			ans[1].pb(ch);
			ans[ch].pb(1);

			s.erase(ch);	
			dfs(ch);
		}
	}	

	if(d>degree[1] || d<cnt)
	{
		cout<<"NO";
		return 0;
	}

	d-=cnt;
	rep(i,0,d)
	{
		auto it = s.begin();
		
		ans[1].pb(*it);
		ans[*it].pb(1);

		s.erase(*it);
	}

	rep(i,0,N)
		visited[i]=0;

	queue< ll > q;q.push(1);visited[1]=1;
	while(sz(q)!=0)
	{
		ll v = q.front();q.pop();
		rep(i,0,sz(ans[v]))
		{
			if(visited[ans[v][i]]==0)
			{
				ansf.pb(mp(v,ans[v][i]));
				visited[ans[v][i]]=1;
				q.push(ans[v][i]);	
			}
		}
	}

	cout<<"YES\n";
	rep(i,0,sz(ansf))
		cout<<ansf[i].F<<" "<<ansf[i].S<<"\n";
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