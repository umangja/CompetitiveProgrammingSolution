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
	ll A,B,n;cin>>A>>B>>n;
	vpii a(n);
	rep(i,0,n) cin>>a[i].F;
	rep(i,0,n) cin>>a[i].S;
	ll tot=B;

	sort(a.begin(), a.end(),greater<pii> ());

	rep(i,0,n){
		ll times = (a[i].S+A-1)/A;
		ll dam = times * a[i].F;
		tot -= dam;
	}



	ll pos = 0;

	if(a[0].F+tot > 0) pos=1;

	// rep(i,0,n){

	// 	ll times = (a[n-1].S+A-1)/A;
	// 	ll dam   = times * a[n-1].F;
	// 	ll temp = tot + dam;

	// 	ll dam1   = (times -1) * a[n-1].F;
	// 	temp -= dam1;

	// 	if(temp>0) pos=1;

	// }


	cout<<(pos?"YES":"NO")<<"\n";
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