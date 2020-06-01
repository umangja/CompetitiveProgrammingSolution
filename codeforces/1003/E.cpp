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
ll n,d,k,od;
vvi adj;
vi deg;
set<ll> cd;

void dfs(ll u,ll p=-1)
{
	if(deg[u]==1) cd.insert(u);
	for(ll i=0;i<sz(adj[u]);i++)
	{
		ll ch  = adj[u][i];
		if(ch==p) continue;
		dfs(ch,u);
	}
}

int solve()
{
	cin>>n>>d>>k;
	adj.assign(n,vi ());
	if(n==1)
	{
		if(d==0) cout<<"YES\n";
		else cout<<"NO\n";
		return 0;
	}

	if(n==2)
	{
		if(d==1) cout<<"YES\n1 2\n";
		else cout<<"NO\n";
		return 0;
	}

	if(k==1 || n<d+1)
	{
		cout<<"NO\n";
		return 0;
	}


	// whatis(d);
	if(d&1) od=1,d--;

	deg.assign(n,0);
	vi par(n,0);
	vi dist(n,0);

	set<pii> st;

	rep(i,1,d/2+1)
	{
				// whatis(i);
		// whatis(i-1);
		par[i]=i-1;
		deg[i]++;
		deg[i-1]++;
		dist[i]=dist[i-1]+1;
		adj[i].pb(i-1);
		adj[i-1].pb(i);

		st.insert(mp(deg[i],i));
	}

	ll cur_par=0;
	rep(i,d/2+1,d+1)
	{
		// whatis(i);
		// whatis(cur_par);
		par[i]=cur_par;
		deg[i]++;
		deg[cur_par]++;

		adj[i].pb(cur_par);
		adj[cur_par].pb(i);

		dist[i]=dist[cur_par]+1;
		st.insert(mp(deg[i],i));
		cur_par=i;
	}

	st.insert(mp(deg[0],0ll));

	ll cur = d+1;
	while(cur<n-od && !st.empty())
	{
		pii p = *st.begin();
		if(deg[p.S]==k) st.erase(p);
		else if(dist[p.S]==d/2) st.erase(p);
		else
		{
			par[cur]=p.S;
			deg[cur]++;
			deg[p.S]++;
			dist[cur] = dist[p.S]+1;
			st.erase(p);
			st.insert(mp(deg[cur],cur));
			st.insert(mp(deg[p.S],p.S));


			adj[cur].pb(p.S);
			adj[p.S].pb(cur);

			cur++;
		}
	}

	if(od)
	{
		// whatis(cur);
		dfs(1,0);
		// whatis(sz(cd));
		all(it,cd)
		{
			ll i = *it;
			while(deg[i]<k && cur<n)
			{
				// whatis(cur);
				// whatis(i);
				deg[i]++;
				deg[cur]++;
				par[cur]=i;
				dist[cur]=dist[i]+1;
				cur++;
			}
		}
	}


	ll w=1;
	if(cur!=n) w=0;
	rep(i,0,n) if(deg[i]>k) w=0;

	if(w)
	{
		cout<<"YES\n";
		rep(i,1,n) cout<<i+1<<" "<<par[i]+1<<"\n";

	}
	else cout<<"NO\n";

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