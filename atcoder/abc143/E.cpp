/*input

*/


//assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define pii         pair<ll int,ll int>
#define vpii        vector< pii >
#define vi          vector<ll int>
#define vs			vector< string >
#define vvi         vector< vector< ll > >
#define inf			(ll)1e18
#define all(it,a)   for(auto it=(a).begin();it!=(a).end();it++) 
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define repr(i,a,b) for(ll int i=a;i>b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define whatis(x)   cout << #x << " is " << x << "\n";
#define graph(n)    adj(n,vector< ll > () )
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll N = 305;
ll n,m,l;
vector< vpii > adj(N,vpii ());
vvi ansf(N,vi (N));


vi dikstra(ll s)
{
	vpii dist(n,mp(inf,inf));
	vi vis(n,0);

	dist[s] = mp(0,0);
	priority_queue< pair< pii,ll > ,vector< pair< pii,ll > >,greater< pair< pii,ll > > > q;
	q.push(mp(dist[s],s));
	while(!q.empty())
	{
		ll u = q.top().S;
		q.pop();


		if(vis[u]==1) continue;

		vis[u]=1;
		ll used = dist[u].S;
		rep(i,0,sz(adj[u]))
		{
			if(vis[adj[u][i].F]==1) continue;

			ll v = adj[u][i].F;
			ll d = adj[u][i].S;

			
			ll req_chan = dist[u].F;
			ll total = used+d;
			if(total>l) req_chan++,total = d; 
			pii cur = mp(req_chan,total);
			if(cur<dist[v])
			{
				dist[v]=cur;	
				q.push(mp(dist[v],v));
			}
		}
	}

	vi ans(n);
	rep(i,0,n) ans[i]=(dist[i].F==inf?-1:dist[i].F);
	return ans;
}

int solve()
{
	cin>>n>>m>>l;
	rep(i,0,m)
	{
		ll x,y,d;
		cin>>x>>y>>d;
		if(d<=l)
		{
			x--,y--;
			adj[x].pb(mp(y,d));
			adj[y].pb(mp(x,d));

		}
	}

	rep(i,0,n) ansf[i] = dikstra(i);
	// ansf[0] = dikstra(0);

	ll q;cin>>q;
	while(q--)
	{
		ll x,y;cin>>x>>y;
		x--,y--;
		cout<<ansf[x][y]<<"\n";
	}
	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll test_cases=1;
	//cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	//cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}