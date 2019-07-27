/*input
3
1 1 1
3
1 1
2 1
3 1

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


const ll con = (ll)ceil(sqrt(1e5+5)),N=1e5+5;
ll dp[N][con];
int solve()
{
	ll n;cin>>n;
	
	vi arr;
	arr.pb(0);
	rep(i,0,n){ll x;cin>>x;arr.pb(x);}
	
	rep(k,1,con)
	{
		for(ll i=n;i>=1;i--)
		{
			if(i+arr[i]+k>n) dp[i][k]=1;
			else dp[i][k]=1+dp[i+arr[i]+k][k];
		}
	}

	ll q;cin>>q;
	while(q--)
	{
		ll p,k;cin>>p>>k;
		if(k<con) cout<<dp[p][k]<<"\n";
		else
		{
			ll ans=0;
			while(p<=n) ans++,p=p+arr[p]+k;
			cout<<ans<<"\n";
		}
	}

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