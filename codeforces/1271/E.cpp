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

// ll power_2[64];
ll n,k;
ll check(ll x)
{

	if(x>n) return 0;
	else if(x==n) return 1>=k;

	ll ans=2;
	
	ll mx = x+1,mn = x;
	if(x%2==1) mx=x,ans--;

	while(mx<n)
	{
		if(2*mn>n) break;
		mn = 2*mn;
		mx = min(2*mx+1,n);
		ans+=(mx-mn+1);
	}

	// cout<<x<<" "<<ans<<"\n";
	return ans>=k;

}

int solve()
{
	cin>>n>>k;
	ll low=1;
	ll high=n;
	while(low<high)
	{
		ll mid = low+(high-low+1)/2;
		if(check(mid+1)) low=mid+1;
		else if(check(mid)) low=mid;
		else high=mid-1;
	}
	cout<<min(low,n)<<"\n";
	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// power_2[0]=1;
	// rep(i,1,65) power_2[i]=power_2[i-1]*2;

	ll test_cases=1;
	//cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}