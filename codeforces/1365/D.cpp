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
vector<vector<char>> mat;
vector<vector<ll>> vis;
ll n,m;
ll test_cases=1;

ll dx[] = {0,1,0,-1};
ll dy[] = {1,0,-1,0};

ll check(ll x,ll y)
{
	if(x>=0 && y>=0 && x<n && y<m && mat[x][y]!='#') return 1;
	return 0;
}

void dfs(ll i,ll j)
{
	if(vis[i][j]==1) return ;
	vis[i][j]=1;
	rep(k,0,4) 
	{
		ll x = i+dx[k];
		ll y = j+dy[k];
	
	 	if(check(x,y)) dfs(x,y);
	 }
	 return ;
}
ll cnt=0;
int solve()
{
	cnt++;
	cin>>n>>m;
	mat.assign(n,vector<char> (m,'.'));
	vis.assign(n,vector<ll> (m,0));

	rep(i,0,n) rep(j,0,m) cin>>mat[i][j];

	ll win=1;
	rep(i,0,n) rep(j,0,m) if(mat[i][j]=='B') rep(k,0,4) {
		ll x = i+dx[k];
		ll y = j+dy[k];
	 	if(check(x,y))
	 	{
	 		if(mat[x][y]=='G') win=0;
	 		if(mat[x][y]=='.') mat[x][y] = '#';
	 	}
	 }

	if(win==0) { cout<<"No\n"; return 0; }
	if(mat[n-1][m-1]=='B') win=0;
	else
	{
		if(mat[n-1][m-1]!='#') dfs(n-1,m-1);
		rep(i,0,n) rep(j,0,m) if(mat[i][j]=='G') win&=vis[i][j];
	}
	cout<<(win==1?"Yes\n":"No\n"); 
	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin>>test_cases;
	while(test_cases--)
	{
		solve();
	}

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	//cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}