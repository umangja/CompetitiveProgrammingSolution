/*input
3 2 3
2 1 2
1 3
2 4
3 5



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

const ll N = 105;
ll a[N],p[N][N];
ll dp[N][N][N];
int solve()
{
	ll n,m,k;cin>>n>>m>>k;
	rep(i,0,n) cin>>a[i];
	rep(i,0,n) rep(j,1,m+1) cin>>p[i][j];

	rep(i,0,N) rep(j,0,N) rep(k1,0,N) dp[i][j][k1]=inf;

	if(a[0]!=0) dp[0][a[0]][1]=0;
	else rep(c,1,m+1) dp[0][c][1]=p[0][c];

	rep(i,1,n)
	{
		if(a[i]!=0) rep(lc,1,m+1) rep(b,1,k+1) dp[i][a[i]][b]=min(dp[i][a[i]][b],dp[i-1][lc][b-(lc!=a[i])]);
		else
		{
			rep(b,1,k+1)
				rep(cc,1,m+1)
					rep(lc,1,m+1)
						dp[i][cc][b]=min(dp[i][cc][b],dp[i-1][lc][b-(lc!=cc)]+p[i][cc]);					
		}
	}

	ll ans=inf;
	rep(cc,1,m+1) ans=min(ans,dp[n-1][cc][k]);
	ans=(ans==inf?-1:ans);
	cout<<ans;
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