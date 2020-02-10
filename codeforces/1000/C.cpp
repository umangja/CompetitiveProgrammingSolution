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
	ll n;cin>>n;
	vpii seg(n);
	rep(i,0,n) cin>>seg[i].F>>seg[i].S;

	vi a(2*n);
	rep(i,0,n) a.pb(seg[i].F),a.pb(seg[i].S+1);

	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()),a.end());

	map<ll,ll> hash,hash2;
	rep(i,0,sz(a))  hash[a[i]] = i,hash2[i]=a[i];

	// rep(i,0,sz(a)) cout<<a[i]<<" ";

	vi sum(sz(a),0);
	vi ans(n,0);
	rep(i,0,n)
	{
		sum[hash[seg[i].F]]   += 1;
		sum[hash[seg[i].S+1]] += -1;
	}

	// rep(i,0,sz(a)) cout<<sum[i]<<" ";

	rep(i,0,sz(a)) sum[i] = (i-1>=0?sum[i-1]:0) +sum[i];

	rep(i,0,sz(a)-1)
	{
		ll l = hash2[i];
		ll r = hash2[i+1];
		if(sum[i]!=0) ans[sum[i]-1]+=r-l;
		// whatis(sum[i]);
	}

	rep(i,0,n) cout<<ans[i]<<" ";


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