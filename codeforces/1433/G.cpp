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

// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
const ll N = 1001;
ll n,m,k;
vector<vector<ll>> adj(N,vi ());
vpii routes(N);
map<pii,ll> edges;
map<ll,pii> idx;


vi fun(ll s)
{
	vi dist(n,inf);
	priority_queue< pii,vpii,greater<pii> > q;
	q.push(mp(0,s));
	dist[s]=0;

	while(!q.empty())
	{
		pii p = q.top();
		q.pop();

		rep(i,0,sz(adj[p.S]))
		{
			ll ch = adj[p.S][i];
			if(p.F+edges[mp(ch,p.S)]<dist[ch])
			{
				dist[ch]=p.F+edges[mp(ch,p.S)];
				q.push(mp(dist[ch],ch));
			}
		}
	}

	return dist;
 
}


int solve()
{
	cin>>n>>m>>k;
	rep(i,0,m)
	{
		ll x,y;cin>>x>>y;
		x--,y--;
		ll w;cin>>w;
		
		adj[x].pb(y);
		adj[y].pb(x);
		
		edges[mp(x,y)]=w;
		edges[mp(y,x)]=w;
		
		idx[i]=mp(x,y);
	}

	rep(i,0,k) cin>>routes[i].F>>routes[i].S;
	rep(i,0,k) routes[i].F--,routes[i].S--;


	vvi dist(n,vi (n,inf));
	rep(i,0,n) dist[i] = fun(i);

	ll ansf = inf;
	rep(j,0,m)
	{
		pii p = idx[j];
		
		ll ans=0;
		rep(i,0,k)
		{
			ll x = routes[i].F;
			ll y = routes[i].S;
			ll temp2 = dist[x][y];
			temp2=min(temp2,dist[x][p.F]+dist[p.S][y]);
			temp2=min(temp2,dist[y][p.F]+dist[p.S][x]);
			ans+=temp2;
		} 
		ansf=min(ans,ansf);
	}

	cout<<ansf<<"\n";




	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
	
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