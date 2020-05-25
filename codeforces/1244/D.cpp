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
vvi col(3,vi(N));
vvi adj(N,vi ());
vi child;

void dfs(ll u,ll p=-1)
{
	rep(i,0,sz(adj[u]))
	{
		ll ch = adj[u][i];
		if(ch!=p)
		{
			child[u]=ch;
			dfs(ch,u);
		}
	}
}

int solve()
{
	ll n;cin>>n;
	vi deg(n,0);
	child.assign(n,-1);
	rep(i,0,3) rep(j,0,n) cin>>col[i][j];
	rep(i,0,n-1)
	{
		ll x,y;cin>>x>>y;
		x--,y--;
		adj[x].pb(y);
		adj[y].pb(x);
		// cout<<x<<" "<<y<<"\n";
		deg[x]++;
		deg[y]++;
	}

	// debug_v(deg);

	rep(i,0,n) if(deg[i]>=3) { cout<<"-1"; exit(0); }

	ll st=0;
	rep(i,0,n) if(deg[i]==1) st=i;
	// whatis(st);


	dfs(st);
	// debug_v(child);

	ll ans=inf;
	vi ans_v;
	rep(i,0,3)
	{
		rep(j,1,3)
		{
			ll temp_ans=0;
			temp_ans+=col[i][st];
			temp_ans+=col[(i+j)%3][child[st]];

			ll last = child[st];
			ll col1 = i;
			ll col2 = (i+j)%3;
			vi temp_col(n);
			temp_col[st]=col1;
			temp_col[last]=col2;
			while(child[last]!=-1)
			{
				last = child[last];
				ll cur_col=-1;
				if((col1==0 && col2==1) || (col1==1 && col2==0) ) cur_col=2;
				if((col1==0 && col2==2) || (col1==2 && col2==0) ) cur_col=1;
				if((col1==2 && col2==1) || (col1==1 && col2==2) ) cur_col=0;
				assert(cur_col!=-1);
				temp_ans+=col[cur_col][last];
				temp_col[last]=cur_col;
				col1=col2;
				col2=cur_col;
			}

			if(ans>temp_ans)
			{
				ans=temp_ans;
				ans_v = temp_col;
			}

		}
	}

	cout<<ans<<"\n";
	rep(i,0,n) cout<<ans_v[i]+1<<" ";
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