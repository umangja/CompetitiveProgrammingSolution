/*input
5
0 1 1 1 1
0 0 0.5 0.5 0.5
0 0.5 0 0.5 0.5
0 0.5 0.5 0 0.5
0 0.5 0.5 0.5 0
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

double a[18][18];
double dp[1<<18];
ll n;
int solve()
{
	cin>>n;
	rep(i,0,n) rep(j,0,n) cin>>a[i][j];
// 	n=18;
// 	rep(i,0,n) rep(j,0,n) a[i][j]=(i==j?0.0:0.5);
	dp[0]=1;

	rep(mask,0,(1<<n)-1)
	rep(i,0,n) if(!(mask&(1<<i)))
	rep(j,0,n) if(!(mask&(1<<j)) && i!=j)
	{
		ll nm = mask|(1<<j);
		ll n0 = n-__builtin_popcount((unsigned int)mask);
		ll np = (n0*(n0-1))/2;
		dp[nm]+=dp[mask]*a[i][j]/(double)np;
		// dp[nm]+=(a[i][j]/(double)np)*fun(nm,left);
	}
	rep(i,0,n) printf("%.7f ",dp[((1<<n)-1)^(1<<i)]);
	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	// ios_base::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);

	ll test_cases=1;
	//cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}