/*input

*/


//assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define pii         pair<ll int,ll int>
#define vpii        vector< pii >
#define vi          vector<ll int>
#define vs			vector< string >
#define vvi         vector< vector< ll > >
#define inf			(ll)1e18
#define all(it,a)   for(auto it=(a).begin();it!=(a).end();it++) 
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define repr(i,a,b) for(ll int i=a;i>b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define whatis(x)   cout << #x << " is " << x << "\n";
#define graph(n)    adj(n,vector< ll > () )
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll N=50;
vector< vector< char > > mat(N,vector<char> (N,'.'));
ll n,m;
vvi vis(N,vi (N,0));
ll dx[] = {0,1,0,-1};
ll dy[] = {1,0,-1,0};
void dfs(ll i,ll j)
{
	vis[i][j]=1;
	rep(k,0,4)
	{
		ll x = i+dx[k];
		ll y = j+dy[k];
		if(x>=0 && x<n && y>=0 && y<m && mat[x][y]=='#' && vis[x][y]==0) dfs(x,y);
	}
	return ;
}

int solve()
{

	cin>>n>>m;
	rep(i,0,n)
	{
		string s;cin>>s;
		rep(j,0,m) mat[i][j]=s[j];
	}

	ll cnt=0;
	rep(i,0,n) rep(j,0,m) if(mat[i][j]=='#') {
		mat[i][j]='.';
		cnt++;
		rep(i1,0,N) rep(j1,0,N) vis[i1][j1]=0;
		rep(i1,0,n) { ll f=0; rep(j1,0,m) if(mat[i1][j1]=='#') { dfs(i1,j1); f=1; break; } if(f) break;}
		rep(i1,0,n) rep(j1,0,m) if(mat[i1][j1]=='#') { if(vis[i1][j1]==0) {cout<<"1\n"; exit(0);}  }
		mat[i][j]='#';
	}

	if(cnt<=3) cout<<"-1\n";
	else cout<<"2\n";

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
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}