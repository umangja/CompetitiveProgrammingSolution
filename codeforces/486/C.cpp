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
const ll mod = 1e9+7;
const ll N = 1e6+5;

int solve()
{
	ll n,st;cin>>n>>st;
	st--;
	string s;cin>>s;
	ll l=n/2;

	if(st>=l) st = n-1-st;

	ll ans=0;
	rep(i,0,l) ans+=min(abs(s[i]-s[n-i-1]),abs(-1*abs(s[i]-s[n-i-1])+26));

	ll i=l-1;
	while(i>=0 && s[i]==s[n-i-1]) i--;
	ll j=0;
	while(j<l && s[j]==s[n-j-1]) j++;

	if(j>i) ans+=0;
	else if(st<=j) ans+=i-st;
	else if(st>=i) ans+=st-j;
	else ans+=min(i-st,st-j)+i-j; 	
	cout<<ans<<"\n";

	return 0;
}
 
int main()
{
	auto start = chrono::high_resolution_clock::now();
 
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);
 
	ll test_cases=1;
	// cin>>test_cases;
	while(test_cases--)
		solve();
 
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}