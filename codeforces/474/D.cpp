/*input
10 48096
75634 80941
27808 89615
58867 93494
95515 99613
68307 69216
87597 99003
64525 89488
56469 61318
50786 67032
95957 95991


*/


//assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define is_empty(v) v.empty()
#define vs			vector< string >
#define vvi			vector< vector< ll,ll > >
#define all(it,a)   for(auto it=(a).begin();it!=(a).end();it++) 
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define inf         1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define repr(i,a,b) for(ll int i=a;i>b;i--)
#define reprr(i,a,b) for(ll int i=a;i>=b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define sum(v)      accumulate(v.begin(),v.end(),(ll)0)
//map <long long int,long long int> ma;
//set <long long int, greater <long long int> > s;
ll k;
const ll N = 1e5+5;
ll dp[N];
ll mod = 1e9+7;

void  f()
{
	rep(i,k+1,N)
	{
		dp[i] = (dp[i-1]+dp[i-k])%mod;
	}

	rep(i,1,N)
		dp[i] = (dp[i-1]+dp[i])%mod;

	// rep(i,1,5)
	// {
	// 	cout<<dp[i]<<" ";
	// }
}

int solve()
{
	ll a,b;cin>>a>>b;
	cout<<(dp[b]-dp[a-1]+mod)%mod<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	ll t=1;
	cin>>t;
	cin>>k;

	dp[0]=0;
	rep(i,1,k)
		dp[i]=1;
	dp[k]=2;
	f();
	while(t--)
		solve();
}