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
const ll N = 101;
ll n,m;
vvi mat(N,vi(N,0));
vvi dp(N,vi(N,0));
vvi ch(N,vi(N,0));


int solve()
{
	cin>>n>>m;
	rep(i,0,n) 
	{
		string s;cin>>s;
		rep(j,0,m) mat[i][j]=(s[j]=='.');
	}



	rep(i,0,n)
	{
		rep(j,0,m)
		{
			if(i==0 && j==0) 
			{
				dp[0][0] = (mat[i][j]==0?1:0);
				ch[0][0] = (mat[i][j]==0?1:0);
			}
			else
			{
				ll ans1 =(i-1>=0?dp[i-1][j] + (mat[i][j]==0 && ch[i-1][j]==0?1:0) : inf);
				ll ans2 = (j-1>=0?dp[i][j-1] + (mat[i][j]==0 && ch[i][j-1]==0?1:0) : inf);
				dp[i][j] = min(ans1,ans2);
				ch[i][j] = (mat[i][j]==0?1:0);
			}
		}
	}

	cout<<dp[n-1][m-1]<<"\n";



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