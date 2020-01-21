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
	ll n,m;cin>>n>>m;
	vvi adj(n,vi ());
	vvi can_be_reached(n,vi ());
	rep(i,0,m)
	{
		ll x,y;cin>>x>>y;
		x--,y--;
		adj[x].pb(y);
		can_be_reached[x].pb(y);
	}

	double ans=inf;
	rep(del,0,n)
	{
		vector<double> dp(n,0);
		repr(i,n-2,-1)
		{
			double k = (double)sz(can_be_reached[i]);
			if(i!=del)
			{
				for(double j=0;j<k;j++) dp[i]+=dp[can_be_reached[i][(ll)j]];
				dp[i]/=k;
				dp[i]+=1;
			}
			else
			{
				double mx=0;
				for(double j=0;j<k;j++) mx=max(mx,dp[can_be_reached[i][(ll)j]]);
				dp[i]-=mx;
				for(double j=0;j<k;j++) dp[i]+=dp[can_be_reached[i][(ll)j]];
				dp[i]/=(k-1);
				dp[i]+=1;
			}
		}
		ans=min(ans,dp[0]);
	}

	cout<<setprecision(15)<<ans<<"\n";	
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
