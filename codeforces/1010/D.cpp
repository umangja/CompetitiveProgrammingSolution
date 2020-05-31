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

#define ll          int
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
const ll N = 1e6+5;
vi val(N,-1);
vi is_input(N,0);
vi op(N,-1);
vvi adj(N,vi ());
vi ch;

void dfs(ll u,ll p=-1)
{
	ll ch1=-1,ch2=-1;
	rep(i,0,sz(adj[u]))
	{
		ll c = adj[u][i];
		if(c!=p)
		{
			dfs(c,u);
			if(ch1==-1) ch1=c;
			else ch2=c;
		} 
	}

	if(!is_input[u])
	{
		if(op[u]==0) val[u]=val[ch1]^1;
		if(op[u]==1) val[u]=val[ch1]&val[ch2];
		if(op[u]==2) val[u]=val[ch1]|val[ch2];
		if(op[u]==3) val[u]=val[ch1]^val[ch2];
	}
	return ;
}

void dfs1(ll u,ll p=-1)
{
	ll ch1=-1,ch2=-1;
	rep(i,0,sz(adj[u]))
	{
		ll c = adj[u][i];
		if(c!=p)
		{
			if(ch1==-1) ch1=c;
			else ch2=c;
		} 
	}

	if(is_input[u]) ch.pb(u);
	else
	{
		if(op[u]==0) dfs1(ch1,u);
		if(op[u]==1)
		{
			if(val[u]==1)
			{
				dfs1(ch1,u);
				dfs1(ch2,u);
			}
			else
			{
				if(val[ch1]!=val[ch2])
				{
					if(val[ch1]==0) dfs1(ch1,u);
					else dfs1(ch2,u);
				}
			}
		}
		if(op[u]==2)
		{
			if(val[u]==0)
			{
				dfs1(ch1,u);
				dfs1(ch2,u);
			}
			else
			{
				if(val[ch1]!=val[ch2])
				{
					if(val[ch1]==1) dfs1(ch1,u);
					else dfs1(ch2,u);
				}
			}
		}
		if(op[u]==3)
		{
			dfs1(ch1,u);
			dfs1(ch2,u);
		}
	}

	return;
}



int solve()
{
	ll n;cin>>n;
	rep(i,0,n)
	{
		string s;cin>>s;
		if(s=="IN")
		{
			ll x;cin>>x;
			val[i]=x;
			is_input[i]=1;
		}
		else if(s=="NOT")
		{
			ll x;cin>>x;
			x--;
			adj[x].pb(i);
			adj[i].pb(x);
			op[i]=0;
		}
		else
		{
			ll x,y;cin>>x>>y;
			x--,y--;

			adj[x].pb(i);
			adj[i].pb(x);
			
			adj[y].pb(i);
			adj[i].pb(y);

			if(s=="AND") op[i]=1;
			else if(s=="OR") op[i]=2;
			else op[i]=3;

		}
	}

	dfs(0);
	ll actual_ans = val[0];

	// whatis(actual_ans);

	dfs1(0);
	vi ans(n,actual_ans);
	rep(i,0,sz(ch)) ans[ch[i]]^=1;

	rep(i,0,n) if(is_input[i]) cout<<ans[i];

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
