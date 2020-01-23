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
#define inf			(ll)1e10
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
const ll N = 13,M=1005;
ll n,m;
vi a(M);
vi dp(1<<N,-1);
vvi b(M,vi ());
ll tot_mask;
ll fun(ll mask)
{
	if(mask == tot_mask) return  dp[mask] = 0;

	if(dp[mask]!=-1) return dp[mask];

	ll ans = inf;
	rep(i,0,m)
	{
		ll new_mask  = mask;
		rep(j,0,sz(b[i])) new_mask|=(1<<b[i][j]);
		if(mask!=new_mask)	ans=min(ans,fun(new_mask)+a[i]);
		// cout<<new_mask<<"\n";
	}
	return dp[mask] = ans;
}


int solve()
{
	cin>>n>>m;
	tot_mask = (1<<n)-1;
	rep(i,0,m)
	{
		ll k;
		cin>>a[i]>>k;
		b[i].assign(k,0);
		rep(j,0,k) cin>>b[i][j];
		rep(j,0,k) b[i][j]--;
		// ,open[b[i][j]]=1;
		// rep(j,0,k) cout<<b[i][j]<<" ";
		// cout<<"\n";
	}
	// rep(i,0,n) if(open[i]==0) {cout<<"-1\n"; return 0;}
	ll ans = fun(0);
	if(ans>=inf) ans=-1;
	cout<<ans<<"\n";
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