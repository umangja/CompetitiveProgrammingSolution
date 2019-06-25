/*input
8
2 1
-1 0
1 0
1 1
1 1
4 0
5 1
7 0


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

vector< vector< ll > > adj(1e5+5,vector< ll >() );
ll root;
vi cv(1e5+5);
vi visited(1e5+5,0);
vi ans;
int solve()
{
	ll n;cin>>n;
	rep(i,0,n)
	{
		ll p,c;cin>>p>>c;
		if (p!=-1)
			adj[p].pb(i+1);
		else
			root=i+1;
		cv[i+1]=c;
	}

	queue< ll > q;
	visited[root]=1;
	q.push(root);
	while(sz(q)!=0)
	{
		ll v = q.front();
		q.pop();

		ll f=1;
		if(cv[v]==0)
			f=0;

		rep(i,0,sz(adj[v]))
		{
			ll ch = adj[v][i];
			if(f==1 && cv[ch]==1)
				continue;
			else
			{
				f=0;
				break;
			}
		}

		if(f)
			ans.pb(v);

		rep(i,0,sz(adj[v]))
		{
			if(visited[adj[v][i]]==0)
			{
				visited[adj[v][i]]=1;
				q.push(adj[v][i]);	
			}
		}

	}

	sort(ans.begin(), ans.end());
	if(sz(ans)==0)
		cout<<"-1";
	else
	{
		rep(i,0,sz(ans))
			cout<<ans[i]<<" ";
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