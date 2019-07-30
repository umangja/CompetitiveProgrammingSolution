/*input
4
1 2 3 4
3
2 3
1 2 2
2 1
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

const ll N = 2e5+5;
int solve()
{
	ll n;cin>>n;
	vi a(n);
	rep(i,0,n) cin>>a[i];
	ll q;cin>>q;
	vector< pair<ll,ll> > last_assign(n);
	rep(i,0,n) last_assign[i]=mp(a[i],0);
	
	vector<ll> last_payoff(N,0);
	ll timer=1;
	for(;timer<=q;timer++)
	{
		ll qt;cin>>qt;
		if(qt==1)
		{
			ll p,x;cin>>p>>x;p--;
			last_assign[p]=mp(x,timer);
		}
		else
		{
			ll x;cin>>x;
			last_payoff[timer]=x;
		}
	}

	ll maxi=-inf;
	for(ll i=N-1;i>=0;i--) maxi=max(maxi,last_payoff[i]),last_payoff[i]=maxi;

	vi ans(n);
	rep(i,0,n) cout<<max(last_payoff[last_assign[i].S+1],last_assign[i].F)<<" ";
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