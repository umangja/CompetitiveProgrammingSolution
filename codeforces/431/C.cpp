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
const ll mod = 1e9+7;
ll dp[101][101];
 
int solve()
{
	ll s,m,d;cin>>s>>m>>d;
	dp[0][0]=1;
	rep(i,1,s+1) rep(j,0,d+1) rep(k,1,min(m+1,i+1)) 
	if(k<d) dp[i][j]=(dp[i][j]+dp[i-k][j])%mod;
	else if(k>=d) dp[i][j]=(dp[i][j]+dp[i-k][0])%mod;
	cout<<dp[s][d]<<"\n";
	return 0;
}
 
int main()
{
	auto start = chrono::high_resolution_clock::now();
 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	ll test_cases=1;
	// cin>>test_cases;
	while(test_cases--)
		solve();
 
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}