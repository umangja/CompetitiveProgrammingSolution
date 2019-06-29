/*input
10 5
3 1 4 3 4 2 3 1 0 1
2 5 3 5 2 5 4 4 1 4
5
4
2
10
7
1


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

ll const N = 5005;
ll n,m;
vi p(N),c(N);
vvi graph(N);
vi visited(N,0);
vi matchR(N,-1);


bool bpm(ll pot)
{
	rep(i,0,sz(adj[pot]))
	{
		ll club = adj[pot][i];
		if(visited[club]==0)
		{
			visited[club]=1;
			if( (matchR[club]==-1 || bpm(matchR[club])) )
			{
				matchR[club]=pot;
				return true;
			}
		}
	}
	return false;
}


bool match(ll u)
{
	rep(i,0,N)
		visited[i]=0;

	return bpm(u);
}

int solve()
{
	cin>>n>>m;
	rep(i,1,n+1)
		scanf("%lld",&p[i]);
	rep(i,1,n+1)
		scanf("%lld",&c[i]);

	ll d;cin>>d;
	vi del(d);
	vi deleted(N,0);
	rep(i,0,d)
	{
		scanf("%lld",&del[i]);
		deleted[del[i]]=1;
	}

	rep(i,1,n+1)
	{
		if(deleted[i]==0)
			adj[p[i]].pb(c[i]);
	}


	ll j=0;
	vi ans;
	repr(i,d-1,-1)
	{
		while(match(j))
			j++;
		ans.pb(j);
		adj[p[del[i]]].pb(c[del[i]]);
	}

	reverse(ans.begin(), ans.end());
	rep(i,0,sz(ans))
		printf("%lld\n",ans[i]);
	return 0;
}

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);

	ll t=1;
	//cin>>t;
	while(t--)
		solve();
}