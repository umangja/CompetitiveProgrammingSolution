/*input
10
13
45
46
60
103
115
126
150
256
516

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
const ll N = 1e5+5;
ll dp[N];
ll ans[N];
vi a(N,0);


int solve()
{
	ll n;cin>>n;
	rep(i,1,n+1) cin>>a[i];
	ans[0]=dp[0]=0;

	rep(i,1,n+1)
	{
		ll tc = inf;
		if(i-1>=0) tc = min(dp[i-1]+20,tc);
		ll idx1 = (lbnd(a.begin()+1, a.begin()+i+1,(a[i]-90+1))-a.begin());idx1--;
		if(idx1>=0) tc=min(dp[idx1]+50,tc);
		ll idx2 = (lbnd(a.begin()+1, a.begin()+i+1,(a[i]-1440+1))-a.begin());idx2--;
		if(idx2>=0) tc=min(tc,dp[idx2]+120);
		ans[i]=tc-dp[i-1];
		dp[i]=tc;
	}

	rep(i,1,n+1) cout<<ans[i]<<"\n";

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