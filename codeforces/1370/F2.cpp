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

vvi adj;
vi dist;
ll n;
ll cnt;
ll root;
void init()
{
	adj.clear();
	dist.clear();
	adj.assign(n,vi ());
	dist.assign(n,0);
	cnt=0;
	root=-1;
}

pii query(vi nodes)
{

	if(sz(nodes)==0)
	{
		return mp(-1,inf);
	}

	assert(cnt+1<=11);
	cout<<"? "<<sz(nodes)<<" ";
	rep(i,0,sz(nodes)) cout<<nodes[i]+1<<" ";
	cout<<"\n"<<flush;

	ll x,d;cin>>x>>d;
	x--;
	if(x==-1 || d==-1) exit(0);
	assert(x!=-1 && d!=-1);
	return mp(x,d);
}

void print_ans(ll x,ll y)
{
	cout<<"! "<<x+1<<" "<<y+1<<"\n"<<flush;
	string ans;
	cin>>ans;
	if(ans!="Correct") exit(0);
	assert(ans=="Correct");
	return ;
}

pii check(ll x,ll del)
{
	vi nodes;
	rep(i,0,n) if(dist[i]==x && i!=del) nodes.pb(i);
	return query(nodes);
}

void dfs(ll u,ll p=-1)
{
	rep(i,0,sz(adj[u]))
	{
		ll ch = adj[u][i];
		if(ch==p) continue;
		else 
		{
			dist[ch] = dist[u]+1;
			dfs(ch,u);
		}
	}
	return ;
}



int solve()
{
	cin>>n;
	init();

	rep(i,0,n-1)
	{
		ll x,y;cin>>x>>y;
		x--,y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	vi nodes;
	rep(i,0,n) nodes.pb(i);
	pii pt = query(nodes);
	root = pt.F;
	ll td = pt.S;

	// whatis(root);
	// whatis(td);

	dist[root]=0;
	dfs(root);

	ll low = (td-1)/2,high = td;
	pii xp = mp(-1,-1);
	while(low<high)
	{
		ll mid=low+(high-low+1)/2;
		pii p = check(mid,-1);  
		if(p.S>td) high = mid-1;
		else
		{
			low = mid;
			xp = p;
		} 
	}

	// whatis(xp.F);
	// whatis(xp.S);

	// whatis(xp.F);
	
	assert(xp.F!=-1);
	assert(td>=dist[xp.F]);

	root = xp.F;
	dist[root]=0;
	dfs(root);

	ll y = check(td,xp.F).F;
	if(y==-1) y=xp.F;
	assert(y!=-1);
	print_ans(xp.F,y);

	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

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