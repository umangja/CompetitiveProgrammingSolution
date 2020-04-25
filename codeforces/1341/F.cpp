/*input

*/


// assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
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
vvi adj(N,vi ());
vi deg(N,0);
vector<pair<ll,ll>> ans;
ll T = 0;
ll n;

void dfs(ll u,ll p,ll cur,ll end)
{

	ans.pb(mp(u,cur));
	
	set<ll> st;
	st.insert(cur);

	ll child_left = sz(adj[u]) - (p!=-1);
	
	rep(i,0,sz(adj[u]))
	{
		ll ch = adj[u][i];
		if(ch==p) continue;
		else
		{
			if((cur+1)%T<cur)
			{
				cur = end-child_left; 
				ans.pb(mp(u,cur));
			} 

			dfs(ch,u,(cur+1)%T,cur);
			cur = (cur+1)%T;
			ans.pb(mp(u,cur));
			st.insert(ch);
			child_left--;
		}
	}

	if(end!=-1)
	{
		if(end<cur) ans.pb(mp(u,end));
		else
		{

		}
	}	
	return ;
}



int solve()
{
	cin>>n;
	rep(i,0,n-1)
	{
		ll x,y;cin>>x>>y;
		x--,y--;
		adj[x].pb(y);
		adj[y].pb(x);
		deg[x]++;
		deg[y]++;
	}

	T = *max_element(deg.begin(), deg.end());
	T++;

	dfs(0,-1,0,-1);

	// vpii temp = ans;
	// sort(temp.begin(), temp.end());
	// temp.erase(unique(temp.begin(), temp.end()),temp.end());
	// assert(sz(temp)==sz(ans));

	cout<<sz(ans)<<"\n";
	rep(i,0,sz(ans)) cout<<ans[i].F+1<<" "<<ans[i].S<<"\n";



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
