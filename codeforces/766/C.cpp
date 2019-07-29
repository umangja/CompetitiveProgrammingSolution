/*input
1
a
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
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

const ll N = 1005;
vi a(26);
ll dp[N];
ll dp1[N];
ll maxi=-inf;
ll mini=0;
const ll mod = 1e9+7;

int solve()
{
	rep(i,0,N) dp1[i]=inf;
	ll n;cin>>n;
	string s;cin>>s;
	rep(i,0,26) cin>>a[i];

	dp[0]=1;
	dp1[0]=1;
	rep(i,1,n)
	{
		ll j=i-1;
		ll l = i-a[s[i]-'a'];
		while(j>=-1 && j>=l)
		{
			if(j==-1)
			{
				dp[i]=(dp[i]+1)%mod;
				dp1[i]=1;
				maxi=max(maxi,i-j);
				break;
			}
			dp[i]=(dp[i]+dp[j])%mod;
			dp1[i]=min(dp1[i],dp1[j]+1);
			maxi=max(maxi,i-j);
			l = max(l,i-a[s[j]-'a']);
			j--;
		}
	}

	cout<<dp[n-1]<<"\n"<<(maxi==(ll)-inf?1:maxi)<<"\n"<<dp1[n-1]<<"\n";

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