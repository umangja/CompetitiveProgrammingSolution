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

void dfs(ll u,ll col,ll &cnt1,vi &vis, vi &nodes,vector<vpii> &g,vector<ll> &c)
{
	vis[u]=1;
	cnt1+=col;
	c[u]=col;
	nodes.pb(u);

	rep(i,0,sz(g[u]))
	{
		ll ch = g[u][i].F;
		if(vis[ch]==1) continue;
		else dfs(ch,col^g[u][i].S,cnt1,vis,nodes,g,c);
	}
	return ;
}


int solve()
{
	ll n;cin>>n;
	vvi mat(2,vi (n));
	map<ll,ll> fq;
	rep(i,0,2) rep(j,0,n) cin>>mat[i][j],fq[--mat[i][j]]++;

	//check frequency;
	rep(i,0,n) if(fq[i]!=2) {cout<<"-1\n"; return 0;}

	vector< vector<pii> > pos(n,vpii ()); // row, col
	rep(i,0,2) rep(j,0,n) pos[mat[i][j]].pb(mp(i,j));


	vector<vpii> g(n,vpii ());
	rep(i,0,n)
	{
		if(pos[i][0].S==pos[i][1].S) continue;

		if(pos[i][0].F==pos[i][1].F)
		{
			g[pos[i][0].S].pb(mp(pos[i][1].S,1));
			g[pos[i][1].S].pb(mp(pos[i][0].S,1));
		} 
		else
		{
			g[pos[i][0].S].pb(mp(pos[i][1].S,0));
			g[pos[i][1].S].pb(mp(pos[i][0].S,0));
		}
	}

	ll ans=0;
	vi ansv;
	vi vis(n,0);
	vi color1(n,0);
	vi color2(n,0);

	rep(i,0,n)
	{
		if(vis[i]==0)
		{
			vi nodes;
			ll cnt1 = 0,cnt2=0;
			dfs(i,0,cnt1,vis,nodes,g,color1);
			
			rep(j,0,sz(nodes)) vis[nodes[j]]=0;
			nodes.clear();
			
			dfs(i,1,cnt2,vis,nodes,g,color2);
			if(cnt1<=cnt2) 
			{
				ans+=cnt1;
				rep(j,0,sz(nodes)) if(color1[nodes[j]]==1) ansv.pb(nodes[j]); 
			}
			else
			{
				ans+=cnt2;
				rep(j,0,sz(nodes)) if(color2[nodes[j]]) ansv.pb(nodes[j]); 				
			}

		}
	}


	assert(ans==sz(ansv));
	cout<<ans<<"\n";
	rep(i,0,sz(ansv)) cout<<ansv[i]+1<<" ";
	cout<<"\n";

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