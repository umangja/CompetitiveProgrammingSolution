/*input

*/


// assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define ll          long long int
#define pb          push_back
#define pii         pair<ll ,ll >
#define vpii        vector< pii >
#define vi          vector<ll >
#define vs			vector< string >
#define vvi         vector< vector< ll > >
#define inf			(ll)1e18
#define all(it,a)   for(auto it=(a).begin();it!=(a).end();it++) 
#define F           first
#define S           second
#define sz(x)       (ll )x.size()
#define rep(i,a,b)	for(ll  i=a;i<b;i++)
#define repr(i,a,b) for(ll  i=a;i>b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define whatis(x)   cout << #x << " is " << x << "\n";
#define graph(n)    adj(n,vector< ll > () )
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define debug(x)     cout << #x << " " << x << endl;
#define debug_p(x)   cout << #x << " " << x.F << " " << x.S << endl;
#define debug_v(x)   {cout << #x << " "; for (auto ioi : x) cout << ioi << " "; cout << endl;}
#define debug_vp(x)  {cout << #x << " "; for (auto ioi : x) cout << '[' << ioi.F << " " << ioi.S << ']'; cout << endl;}
#define debug_v_v(x) {cout << #x << "/*\n"; for (auto ioi : x) { for (auto ioi2 : ioi) cout << ioi2 << " "; cout << '\n';} cout << "*/" << #x << endl;}

const ll N = 51,M = 2505;
vi A,B,C,D;
vvi dist(N,vi (M,inf));
vvi vis(N,vi (M,0));
vvi adj(N,vi ());
map<pii,ll> edge;
ll n,m,s;



void dikstra()
{
	priority_queue<  pair< ll,pair< ll,ll > > , vector< pair< ll,pair< ll,ll > > > , greater< pair< ll,pair< ll,ll > > > > q;
	s=min(s,M-1);
	dist[0][s] = 0;
	q.push(mp(0,mp(0,s)));

	// ll cnt=0;
	while(!q.empty())
	{
		ll d = q.top().F;
		pii cur = q.top().S;
		q.pop();

		if(vis[cur.F][cur.S]==1) continue;
		vis[cur.F][cur.S]=1;
		ll silver = cur.S;
		ll cur_have = silver;
		ll cur_d = d;


		cur_have+=C[cur.F];
		cur_d+=D[cur.F];
		if(cur_have<M && cur_d<dist[cur.F][cur_have] )
		{
			dist[cur.F][cur_have] = cur_d;
			q.push(mp(cur_d,mp(cur.F,cur_have)));	
		}
		

		rep(i,0,sz(adj[cur.F]))
		{
			// cnt++;
			ll ch = adj[cur.F][i];
			ll edge_id = edge[mp(cur.F,ch)];
			ll silver_req = A[edge_id];
			if(silver_req<=silver)
			{ 
				ll nd = d+B[edge_id];
				if(nd<dist[ch][silver-silver_req])
				{
					dist[ch][silver-silver_req] = nd;
					q.push(mp(nd,mp(ch,silver-silver_req)));	
				}			
			}
		}

	}

	// cout<<cnt<<"\n";

}

int solve()
{
	cin>>n>>m>>s;
	rep(i,0,m)
	{
		ll x,y;cin>>x>>y;
		x--,y--;
		ll a,b;cin>>a>>b;
		A.pb(a);B.pb(b);
		adj[x].pb(y);
		adj[y].pb(x);
		edge[mp(x,y)] = i;
		edge[mp(y,x)] = i;

	}

	rep(i,0,n)
	{
		ll c,d;cin>>c>>d;
		C.pb(c);D.pb(d);
	}

	dikstra();

	rep(i,1,n)
	{
		ll ans = inf;
		rep(j,0,2500) ans=min(ans,dist[i][j]);
		cout<<ans<<"\n";
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