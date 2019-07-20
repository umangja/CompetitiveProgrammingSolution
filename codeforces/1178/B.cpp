/*input
vvvovvv


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
	string s;cin>>s;
	vpii a;
	ll ii=0;
	while(ii<sz(s))
	{

		if(s[ii]=='o')
		{
			ll j=ii;
			ll cnt=0;
			while(j<sz(s) && s[j]=='o')
				cnt++,j++;
			a.pb(mp(cnt,0));
			ii=j;
			continue;
		}

		ll j=ii;
		ll cnt=0;
		while(j<sz(s) && s[j]=='v')
			cnt++,j++;
		a.pb(mp(cnt,1));
		ii=j;
	}

	ll n = sz(a);
	ll ans=0;
	vi prefix_sum(n);
	prefix_sum[0] = (a[0].S==1?a[0].F-1:0);
	rep(i,1,n) prefix_sum[i]=prefix_sum[i-1]+(a[i].S==1)*(a[i].F-1);
	// rep(i,0,n) cout<<prefix_sum[i]<<" ";
	rep(i,0,sz(a))
	{
		if(a[i].S==0 && i!=0 && i!=n-1)
		{
			ans+=a[i].F*prefix_sum[i-1]*(prefix_sum[n-1]-prefix_sum[i]);
		}
	}

	cout<<ans;
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
// 	cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}	