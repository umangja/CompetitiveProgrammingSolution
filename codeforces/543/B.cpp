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

const ll N = 3000+5;
vvi dist;
vvi adj;
ll n,m;

vi fun(ll s)
{
	vi d(n,inf);
	d[s]=0;

	priority_queue<pii,vpii,greater<pii>> pq;
	pq.push(mp(0,s));
	while(!pq.empty())
	{
		pii p = pq.top();
		pq.pop();
		rep(i,0,sz(adj[p.S]))
		{
			ll ch = adj[p.S][i];
			if(p.F+1<d[ch])
			{
				d[ch]=p.F+1;
				pq.push(mp(d[ch],ch));
			}
		}
	}

	return d;
}

int solve()
{
	cin>>n>>m;
	dist.assign(n,vi (n,inf));
	adj.assign(n,vi ());
	rep(i,0,m)
	{
		ll x,y;cin>>x>>y;
		x--,y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	vi s(2),t(2),l(2);
	rep(i,0,2) cin>>s[i]>>t[i]>>l[i],s[i]--,t[i]--;

	rep(i,0,n) dist[i] = fun(i);

	// debug_v_v(dist);

	if(!(dist[s[0]][t[0]]<=l[0] && dist[s[1]][t[1]]<=l[1]))
	{
		cout<<"-1\n";
		return 0;
	}

	ll ans=dist[s[0]][t[0]]+dist[s[1]][t[1]];
	rep(x,0,n)
	{
		rep(y,0,n)
		{
			if((dist[s[0]][x] + dist[x][y] + dist[y][t[0]])<=l[0] && (dist[s[1]][x] + dist[x][y] + dist[y][t[1]])<=l[1])
			{
				ll path_len = dist[s[0]][x] + dist[y][t[0]]+ dist[s[1]][x] + dist[x][y] + dist[y][t[1]];
				ans=min(ans,path_len);
			}
		}
	}	

	// whatis(ans);

	swap(s[0],t[0]);
	rep(x,0,n)
	{
		rep(y,0,n)
		{
			if((dist[s[0]][x] + dist[x][y] + dist[y][t[0]])<=l[0] && (dist[s[1]][x] + dist[x][y] + dist[y][t[1]])<=l[1])
			{
				ll path_len = dist[s[0]][x] + dist[y][t[0]]+ dist[s[1]][x] + dist[x][y] + dist[y][t[1]];
				ans=min(ans,path_len);
			}
		}
	}	

	swap(s[0],t[0]);
	swap(s[1],t[1]);
	rep(x,0,n)
	{
		rep(y,0,n)
		{
			if((dist[s[0]][x] + dist[x][y] + dist[y][t[0]])<=l[0] && (dist[s[1]][x] + dist[x][y] + dist[y][t[1]])<=l[1])
			{
				ll path_len = dist[s[0]][x] + dist[y][t[0]]+ dist[s[1]][x] + dist[x][y] + dist[y][t[1]];
				ans=min(ans,path_len);
			}
		}
	}	




	cout<<m-ans<<"\n";


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