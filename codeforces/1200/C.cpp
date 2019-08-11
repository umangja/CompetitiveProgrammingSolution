/*input
4 6 3
1 1 2 3
2 6 1 2
2 6 2 4
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
const double eps = 1e-9;
 
int solve()
{
	ll n,m,q;cin>>n>>m>>q;
	ll g = __gcd(n,m);
	n/=g;m/=g;
	// cout<<n<<" "<<m<<"\n";
	while(q--)
	{
		ll sx,sy,ex,ey;
		cin>>sx>>sy>>ex>>ey;
		ll g1=1,g2=-1;
		if(sx==1) {
			if(sy%n==0) g1=sy/n;
			else g1=sy/n+1;
		}
		else if(sx==2) {
			if(sy%m==0) g1=sy/m;
			else g1=sy/m+1;
		}
		if(ex==1) {
			if(ey%n==0) g2=ey/n;
			else g2=ey/n+1;
		}
		if(ex==2) {
			if(ey%m==0) g2=ey/m;
			else g2=ey/m+1;
		} 
		// whatis(g1);
		// whatis(g2);
		if(g1==g2) cout<<"YES\n";
		else cout<<"NO\n";
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