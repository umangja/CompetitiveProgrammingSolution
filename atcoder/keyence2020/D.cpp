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


const ll tot_mask = (1<<18);
ll dp[tot_mask][51];
int solve()
{
	ll n;cin>>n;
	vi a(n),b(n);
	ll big = -1;
	rep(i,0,n) cin>>a[i],big=max(big,a[i]);
	rep(i,0,n) cin>>b[i],big=max(big,b[i]);
	rep(i,0,tot_mask) rep(j,0,51) dp[i][j]=inf;
	dp[0][0]=0;
	ll mask = 1<<n;
	rep(w,0,mask)
	{
		ll pos = __builtin_popcount((unsigned int)w);
		rep(last_el,0,big+1)
		{
			// whatis(dp[w][last_el]);
			ll d=0;
			rep(i,0,n)
			{
				if(((w>>i)&1)==0)
				{
					ll val = b[i];
					if((abs(i-pos))%2==0) val=a[i];
					// cout<<val<<" "<<i<<"\n";
					if(val>=last_el)
					{
						dp[w|(1<<i)][val] = min(dp[w|(1<<i)][val],dp[w][last_el]+d); 
						// whatis(dp[w|(1<<i)][val]);
					}
					d++;
				}
			}
		}
	}
	ll ans = inf;
	rep(i,0,big+1) ans=min(ans,dp[mask-1][i]);
	if(ans==inf) ans=-1;
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