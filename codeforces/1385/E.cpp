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
vvi g;
vi vis,lvl,topo;
ll po;
set<ll> st;
void dfs(ll u,vi &temp,ll cur=0)
{
	vis[u]=1;
	lvl[u]=cur;
	st.insert(u);
	rep(i,0,sz(g[u]))
	{
		if(vis[g[u][i]]==0) dfs(g[u][i],temp,cur+1); 
		else if(st.find(g[u][i])!=st.end()) po=0;
	} 
	temp.pb(u);
	st.erase(u);	
	return ;
}

int solve()
{
	ll n,m;cin>>n>>m;
	vis.clear();
	g.clear();
	topo.clear();
	lvl.clear();
	po=1;

	vis.assign(n,0);
	lvl.assign(n,-1);
	g.assign(n,vi ());

	vpii  ans,a;
	vi deg(n,0);
	rep(i,0,m)
	{
		ll t,x,y;cin>>t>>x>>y;
		x--,y--;
		if(t==0) a.pb(mp(x,y));
		else g[x].pb(y),ans.pb(mp(x,y)),deg[y]++;  
	}


	vi temp;
	rep(i,0,n)
	{
		if(vis[i]==0 && deg[i]==0)
		{
			st.clear();
			dfs(i,temp);
		} 
	}
	
	reverse(temp.begin(), temp.end());
	rep(j,0,sz(temp)) topo.pb(temp[j]);

	rep(i,0,n) if(vis[i]==0) po=0;

	// debug_v(topo);;

	vi pos(n,0);
	rep(i,0,sz(topo)) pos[topo[i]]=i;	
	
	rep(i,0,sz(a))
	{
		if(pos[a[i].F]>pos[a[i].S]) swap(a[i].F,a[i].S);
		ans.pb(a[i]); 
	}

	if(po==0) cout<<"NO\n";
	else
	{
		cout<<"YES\n";
		rep(i,0,sz(ans)) cout<<ans[i].F+1<<" "<<ans[i].S+1<<"\n";
	}


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