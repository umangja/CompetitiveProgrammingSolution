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
	ll n,m,k;cin>>n>>m>>k;
	k=min(k,m-1);
	vi a(n);
	rep(i,0,n) cin>>a[i];
	ll mx=-1;
	rep(x,0,k+1)
	{
		ll y = k-x;
		ll left = m-1-k;

		ll mn = inf;
		ll l = x;
		ll r = n-1-y;

		rep(xx,0,left+1)
		{
			ll yy = left-xx;
			ll lt = l+xx;
			ll rt = r-yy;

			mn = min(max(a[lt],a[rt]),mn);
		}

		// if(left==0) mn=max(a[l],a[r]);
		// rep(i,0,left) {if(i+l<n) mn=min(mn,a[i+l]); if(r-i>=0) mn=min(mn,a[r-i]);}	
		mx=max(mx,mn);
	}
	if(mx==-1) mx=max(a[0],a[n-1]);
	cout<<mx<<"\n";
	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll test_cases=1;
	cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}