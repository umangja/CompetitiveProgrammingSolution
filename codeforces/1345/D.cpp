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
// # =0 iss ka 1 segment  hona chaiye exactly
const ll N = 1005;
ll n,m;
vvi mat(N,vi (N,0));
vvi vis(N,vi (N,0));

ll dx[] = {1,0,-1,0};
ll dy[] = {0,-1,0,1};


void dfs(ll row,ll col)
{
	vis[row][col]=1;
	rep(i,0,4)
	{
		ll x = row+dx[i];
		ll y = col+dy[i];
		if(x<n && x>=0 && y<m && y>=0 && mat[x][y]==0 && vis[x][y]==0) dfs(x,y);
	}
	return ;
}

int solve()
{
	cin>>n>>m;
	mat.assign(n,vi (m,0));
	ll al1=1;
	rep(i,0,n)
	{
		string s;cin>>s;
		rep(j,0,m)
		{
			char x = s[j];
			mat[i][j] = (x=='.'?1:0);
			if(mat[i][j]==0) al1=0;
		}
	}

	if(al1==1)
	{
		cout<<"0";
		return 0;
	}

	ll w=1;
	ll alw1=0;
	rep(i,0,n)
	{
		ll no=0;
		rep(j,0,m)
		{
			ll k = j;
			while(k<m && mat[i][k]==mat[i][j]) k++;
			if(mat[i][j]==0) no++;
			j = k-1;
		}
		if(no>1) w=0;
		if(no==0) alw1=1;
	}

	ll alw2=0;

	rep(j,0,m)
	{
		ll no=0;
		rep(i,0,n)
		{
			ll k = i;
			while(k<n && mat[k][j]==mat[i][j]) k++;
			if(mat[i][j]==0) no++;
			i = k-1;
		}
		if(no>1) w=0;
		if(no==0) alw2=1;
	}

	if(alw1+alw2==1) w=0;

	if(w==0) cout<<"-1";
	else
	{
		ll ans=0;
		rep(i,0,n) rep(j,0,m) if(mat[i][j]==1) vis[i][j]=1; else if(vis[i][j]==0 && mat[i][j]==0) {ans++; dfs(i,j); }
		cout<<ans<<"\n";
	}

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