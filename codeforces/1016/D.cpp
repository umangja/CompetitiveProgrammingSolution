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
	vi a(n),b(m);
	rep(i,0,n) cin>>a[i];
	rep(j,0,m) cin>>b[j];

	vvi mat(n,vi(m,0));


	ll T = 0;
	rep(i,0,n) T^=a[i];
	ll temp=0;
	rep(j,0,m) temp^=b[j];

	if(T!=temp) {cout<<"NO\n"; return 0;}
	cout<<"YES\n";

	rep(i,0,n)
	{
		rep(j,0,m)
		{
			if(i==0 && j==0) mat[i][j]=a[0]^b[0]^T;
			else if(i==0) mat[i][j] = b[j];
			else if(j==0) mat[i][j] = a[i];
			else mat[i][j]=0;
		}
	}

	rep(i,0,n)
	{
		ll t=0;
		rep(j,0,m) t^=mat[i][j];
		assert(t==a[i]);
	}

	rep(j,0,m)
	{
		ll t=0;
		rep(i,0,n) t^=mat[i][j];
		assert(t==b[j]);
	}

	rep(i,0,n) { rep(j,0,m) cout<<mat[i][j]<<" "; cout<<"\n"; }
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