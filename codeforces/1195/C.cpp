/*input
5
9 3 5 7 3
5 8 1 4 5
3
1 2 9
10 1 1
1
7
4

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
#define inf			1e18
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


ll dp[2][100005];
ll h[2][100005];
int solve()
{
	ll n;cin>>n;
	rep(i,0,n) cin>>h[0][i];
	rep(i,0,n) cin>>h[1][i];

	// ll ans=0;
	// ll j=0;
	// rep(i,0,n) 
	// {
	// 	if(i+1<n && h[j][i]<h[j][i+1]) i++;	
	// 	ans+=h[j][i],j=1-j;
	// }
	
	// ll ans2=0;
	// j=1;
	// rep(i,0,n)
	// {
	// 	if(i+1<n && h[j][i]<h[j][i+1]) i++;	
	// 	ans2+=h[j][i],j=1-j;
	// } 

	dp[0][0]=h[0][0];
	dp[1][0]=h[1][0];

	ll maxi[2];
	maxi[0]=dp[0][0];
	maxi[1]=dp[1][0];

	rep(i,1,n)
	{
		dp[0][i]=maxi[1]+h[0][i];
		dp[1][i]=maxi[0]+h[1][i];

		maxi[0]=max(maxi[0],dp[0][i]);
		maxi[1]=max(maxi[1],dp[1][i]);
	}

	cout<<max(maxi[0],maxi[1]);
	// cout<<"\n";
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