/*input
1 4000000000
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


int solve()
{
	ll n,k;cin>>n>>k;

	if(k>200000)
	{
		cout<<"-1";
		return 0;
	}

	vi div;
	for(ll i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			if(i*i==n) div.pb(i);
			else div.pb(i),div.pb(n/i);
		} 
	}

	sort(div.begin(), div.end(),greater< ll > ());
	rep(i,0,sz(div))
	{
		ll dup = n/div[i];
		if((k*(k+1))/2<=dup)
		{
			rep(j,0,k-1) cout<<div[i]*(j+1)<<" ";
			cout<<div[i]*(dup-(k*(k-1))/2);
			return 0;
		}
	}
	cout<<"-1";
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