/*input
 3
4 5 6

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
const ll mod = 1e9+7;
const ll N = 1e6+5;
int solve()
{
	string s;cin>>s;
	ll n=sz(s);
	ll k;cin>>k;
	vi w(26);
	rep(i,0,26) cin>>w[i];
	ll mx = *max_element(w.begin(), w.end());
	ll ans=0;
	rep(i,0,n) ans+=w[s[i]-'a']*(i+1);
	rep(i,0,k) ans+=mx*(n+i+1);
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
	// cin>>test_cases;
	while(test_cases--)
		solve();
 
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}