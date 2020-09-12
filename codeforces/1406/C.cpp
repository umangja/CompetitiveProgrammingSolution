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

const ll N = 1e5+5;
vvi adj;
vi siz;
set<ll> st;
ll n;
void dfs(ll u,ll p=-1)
{
	siz[u]=1;
	ll pos=1;
	rep(i,0,sz(adj[u]))
	{
		ll ch = adj[u][i];
		if(ch==p) continue;
		dfs(ch,u);
		siz[u]+=siz[ch];
		if(siz[ch]>n/2)	pos=0;
	}

	if(n-siz[u]>n/2)pos=0;
	if(pos) st.insert(u);
	return ;
}


int solve()
{
	cin>>n;

	adj.clear();siz.clear();st.clear();
	adj.assign(n,vi ()); siz.assign(n,0);

	map<ll,pii> edge;
	rep(i,0,n-1)
	{
		ll x,y;cin>>x>>y;
		x--,y--;
		edge[i]=mp(x,y);
		adj[x].pb(y);
		adj[y].pb(x);
	}	

	dfs(0);

	assert(sz(st)!=0);

	if(sz(st)==1)
	{
		cout<<edge[0].F+1<<" "<<edge[0].S+1<<"\n";
		cout<<edge[0].F+1<<" "<<edge[0].S+1<<"\n";
		return 0;
	}

	// assert(sz(st)==2);
	// whatis(sz(st));

	auto it = st.begin();
	ll c1 = *it; it++;
	ll c2 = *it; 
	
	pii del = mp(-1ll,-1ll);
	rep(i,0,sz(adj[c1]))
	{
		ll ch = adj[c1][i];
		if(ch!=c2)
		{
			del = mp(c1,ch);
			break;
		}
	}

	assert(del.F!=-1);
	cout<<del.F+1<<" "<<del.S+1<<"\n";
	cout<<del.S+1<<" "<<c2+1<<"\n";
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