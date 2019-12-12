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
	vi a(n+1);
	rep(i,0,n) cin>>a[i];
	a[n]=-1;
	n++;

	ll ans=0;
	rep(i,0,n)
	{
		ll j=i+1;
		while(j<n && a[j]>a[j-1]) j++;
		ans=max(ans,j-i);
		ll dup = j;

		if(j-2>=0 && j<n && a[j-2]<a[j]) 
		{
			j++;
			while(j<n && a[j]>a[j-1]) j++;
			ans=max(ans,j-i-1);
		}
		j=dup;
		if(j+1<n && j-1>=0 && a[j+1]>a[j-1]) 
		{
			j++;
			while(j<n && a[j]>a[j-1]) j++;
			ans=max(ans,j-i-1);
		}

		i=dup-1;
	}
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