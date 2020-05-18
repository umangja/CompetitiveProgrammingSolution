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

const ll N = 5005;
ll n,m;
vi num(3);
vi vis,vis2;
vvi el0,el1;
vi temp0,temp1;
ll is_cycle=0,cnt=0;
vvi g(N,vi());
pii cur;
	
void dfs(ll u,ll c,ll p=-1)
{
	// whatis(u+1);
	vis[u]=1;
	vis2[u]=1;
	cnt++;

	if(c) cur.F++,temp0.pb(u);
	else cur.S++,temp1.pb(u);


	rep(i,0,sz(g[u]))
	{
		ll ch = g[u][i];
		if(ch==p) continue;
		if(vis2[ch]==1 && (cnt&1)) is_cycle=1; 
		if(vis[ch]==0) dfs(ch,c^1,u);
	}

	vis2[u]=0;
	return ;
}


int solve()
{
	cin>>n>>m;
	vis.resize(n);
	vis2.resize(n);


	rep(i,0,3) cin>>num[i];
	rep(i,0,m)
	{
		ll x,y;
		cin>>x>>y;
		x--,y--;
		g[x].pb(y);
		g[y].pb(x);
	}

	if(n==1)
	{
		if(num[0]!=0)      cout<<"YES\n"<<1<<"\n";
		else if(num[1]!=0) cout<<"YES\n"<<2<<"\n";
		else if(num[2]!=0) cout<<"YES\n"<<3<<"\n";
		return 0;
	}

	rep(i,0,n)
	{
		vis[i]=0;
		vis2[i]=0;
	}

	vpii st;

	rep(i,0,n)
	{
		if(vis[i]==0)
		{
			cnt=0;
			cur=mp(0ll,0ll);
			temp0.clear();
			temp1.clear();

			dfs(i,1);

			// whatis(is_cycle);
			st.pb(cur);	
			el0.pb(temp0);
			el1.pb(temp1);
		} 
	}
	


	ll k = sz(st);
	vvi dp1(k,vi (n+1,0));
	vvi dp2(k,vi (n+1,0));
	// vector<vvi> dp(2,vvi (k,vi (n+1,0)));

	rep(i,0,k) rep(j,0,n+1) 
	{
		if(i==0) dp1[i][j] = (st[i].F==j),dp2[i][j] = (st[i].S==j);
		else
		{
			if(j-st[i].F>=0) dp1[i][j] = max(dp1[i-1][j-st[i].F],dp2[i-1][j-st[i].F]);
			if(j-st[i].S>=0) dp2[i][j] = max(dp1[i-1][j-st[i].S],dp2[i-1][j-st[i].S]);
		}		
	}
	if(is_cycle==0 && (dp1[k-1][num[1]]==1 || dp2[k-1][num[1]]==1))
	{
		vi ans(n,0);
		cout<<"YES\n";

		ll s = num[1];
		for(ll i = k-1;i>=0;i--)
		{
			if(dp1[i][s]==1)
			{
				// cout<<0<<"\n";
				rep(j,0,sz(el0[i])) ans[el0[i][j]]=2;
				rep(j,0,sz(el1[i]))
				{
					if(num[0]) ans[el1[i][j]] = 1,num[0]--;
					else ans[el1[i][j]] = 3,num[2]--;
				} 
				s-=st[i].F;
			}
			else
			{
				// cout<<1<<"\n";
				rep(j,0,sz(el1[i])) ans[el1[i][j]]=2;
				rep(j,0,sz(el0[i]))
				{
					if(num[0]) ans[el0[i][j]] = 1,num[0]--;
					else ans[el0[i][j]] = 3,num[2]--;
				} 
				s-=st[i].S;
			}
		}

		rep(i,0,n) cout<<ans[i];

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