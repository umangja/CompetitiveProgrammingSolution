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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define debug(x)     cout << #x << " " << x << endl;
#define debug_p(x)   cout << #x << " " << x.F << " " << x.S << endl;
#define debug_v(x)   {cout << #x << " "; for (auto ioi : x) cout << ioi << " "; cout << endl;}
#define debug_vp(x)  {cout << #x << " "; for (auto ioi : x) cout << '[' << ioi.F << " " << ioi.S << ']'; cout << endl;}
#define debug_v_v(x) {cout << #x << "/*\n"; for (auto ioi : x) { for (auto ioi2 : ioi) cout << ioi2 << " "; cout << '\n';} cout << "*/" << #x << endl;}
const ll N = 11,M = 3e5;
ll n,m,k;
vvi mat;
map<pair<pii,ll>,ll> cnt;
map<ll,ll> hv;
// ll dp[N][N][M];
ll idx=0;

void dfs(ll x,ll y,ll ans)
{
	cnt[mp(mp(x,y),ans)]++;
	if(x+1<n && x+1+y<=20) dfs(x+1,y,ans^mat[x+1][y]);
	if(y+1<m && x+y+1<=20) dfs(x,y+1,ans^mat[x][y+1]);
	return ;
}

ll fun(ll x,ll y,ll val)
{
	// if(hv.find(val)==hv.end()) hv[val]=idx++;
	// if(dp[x][y][hv[val]]!=-1) return dp[x][y][hv[val]];

	pair<pii,ll> key =  mp(mp(x,y),val);
	if(cnt.find(key)!=cnt.end()) return cnt[key];

	ll ans = 0;
	if(x-1>=0 && x-1+y>20) ans+=fun(x-1,y,mat[x][y]^val);
	if(x-1>=0 && x-1+y<=20) ans+=cnt[mp(mp(x-1,y),mat[x][y]^val)];
	if(y-1>=0 && x-1+y>20) ans+=fun(x,y-1,mat[x][y]^val);
	if(y-1>=0 && x-1+y<=20) ans+=cnt[mp(mp(x,y-1),mat[x][y]^val)];
	// return ans;
	return cnt[key]=ans;
}

int solve()
{
	cin>>n>>m>>k;
// 	n=20;m=20;
	mat.assign(n,vi (m,0));
	rep(i,0,n) rep(j,0,m) 
// 	mat[i][j]=rng();
	cin>>mat[i][j];

	dfs(0,0,mat[0][0]);
// 	memset(dp,-1,sizeof dp);
	cout<<fun(n-1,m-1,k)<<"\n";
	// whatis(sz(cnt));

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