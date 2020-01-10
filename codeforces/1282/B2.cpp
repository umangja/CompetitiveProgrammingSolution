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


int solve()
{
	ll n,t,k;cin>>n>>t>>k;
	vi a(n);vpii dp(n,mp(0,0));
	rep(i,0,n) cin>>a[i];
	sort(a.begin(), a.end());
	dp[0] = (a[0]<=t?mp(1,t-a[0]):mp(0,t));
	rep(i,1,n)
	{
		if(a[i]>t)
		{
			dp[i]=dp[i-1];
			continue;
		} 

		if(i-k>=0 && dp[i-k].S>=a[i]) dp[i] = max(dp[i],mp(dp[i-k].F+k,dp[i-k].S-a[i]));
		if(i-k==-1 && a[i]<=t) dp[i] = mp(k,t-a[i]);
		if(dp[i-1].S>=a[i]) dp[i] = max(dp[i],mp(dp[i-1].F+1,dp[i-1].S-a[i]));
		dp[i]=max(dp[i],dp[i-1]);
	}
	// rep(i,0,n) cout<<dp[i].F<<" ";
	// cout<<"\n";
	cout<<dp[n-1].F<<"\n";
	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll test_cases=1;
	cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}