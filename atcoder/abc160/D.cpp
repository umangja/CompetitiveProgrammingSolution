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

const ll N = 2e3+3;
vvi adj(N,vi ());
ll n;

vi dikstra(ll s)
{
	vi d(n,inf);
	vi vis(n,0);
	d[s]=0;
	priority_queue< pii,vpii,greater<pii> > q;
	q.push(mp(0,s));
	while(!q.empty())
	{
		pii p = q.top();
		q.pop();
		if(vis[p.S]==1) continue;
		vis[p.S]=1;
		ll cur = p.S;
		rep(i,0,sz(adj[cur]))
		{
			ll ch = adj[cur][i];
			if(vis[ch]==1) continue;
			if(p.F+1<d[ch])
			{
				d[ch]=p.F+1;
				q.push(mp(d[ch],ch));
			}
		}
	}
	return d;
}

int solve()
{
	ll x,y;cin>>n>>x>>y;
	x--,y--;
	rep(i,0,n-1) adj[i].pb(i+1),adj[i+1].pb(i);
	adj[x].pb(y);
	adj[y].pb(x);


	vi ans(n);

	rep(i,0,n)
	{
		vi d = dikstra(i);
		rep(j,0,n) ans[d[j]]++;
	}

	rep(i,1,n) cout<<ans[i]/2<<"\n";


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