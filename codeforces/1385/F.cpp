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

int solve()
{
	ll n,k;cin>>n>>k;
	vvi g(n,vi ());
	vi deg(n,0);

	rep(i,0,n-1)
	{
		ll x,y;cin>>x>>y;
		x--,y--;
		g[x].pb(y);
		g[y].pb(x);

		deg[x]++;
		deg[y]++;
	}

	set<ll> Kleafs,MoreThanK;
	vi cnt(n,0);
	rep(i,0,n)
	{
		rep(j,0,sz(g[i])) if(deg[g[i][j]]==1) cnt[i]++;
		if(cnt[i]<k) continue;
		else if(cnt[i]==k) Kleafs.insert(i);
		else MoreThanK.insert(i);
	}

	vector<set<ll>> adj(n);
	rep(i,0,n) rep(j,0,sz(g[i])) adj[i].insert(g[i][j]);

	ll ans=0;
	set<ll> dead;
	while(!Kleafs.empty() || !MoreThanK.empty())
	{
		while(!Kleafs.empty())
		{
			ll cur = *Kleafs.begin();
			Kleafs.erase(cur);

			vi del;
			all(it,adj[cur]) if(deg[*it]==1) del.pb(*it);

			if(sz(del)==k) ans++;
			else continue;

			rep(i,0,k)
			{
				dead.insert(del[i]);
				adj[cur].erase(del[i]);
			} 

			deg[cur]-=k;
			cnt[cur]-=k;

			if(deg[cur]==1)
			{
				assert(sz(adj[cur])==1);
				ll par = *adj[cur].begin();
				cnt[par]++;
				if(cnt[par]==k) Kleafs.insert(par);
				else if(cnt[par]>k)
				{
					Kleafs.erase(par);
					MoreThanK.insert(par);
				} 
			}

		}


		if(!MoreThanK.empty())
		{
			ll cur = *MoreThanK.begin();
			MoreThanK.erase(cur);

			// if(dead.find(cur)!=dead.end()) continue;
			// dead.insert(cur);
			// whatis(cur+1);

			ans+=cnt[cur]/k;

			vi del;
			all(it,adj[cur]) if(deg[*it]==1) del.pb(*it);
			rep(i,0,(cnt[cur]/k)*k) adj[cur].erase(del[i]);
			
			deg[cur]-=(cnt[cur]/k)*k;
			cnt[cur]-=(cnt[cur]/k)*k;

			if(deg[cur]==1 )
			{
				assert(sz(adj[cur])==1);
				ll par = *adj[cur].begin();
				// whatis(par+1);
				cnt[par]++;
				if(cnt[par]==k) Kleafs.insert(par);
				else if(cnt[par]>k)
				{
					Kleafs.erase(par);
					MoreThanK.insert(par);
				} 
			}

		}

	}


	cout<<ans<<"\n";

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
	cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	//cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}