/*input
2
3 1
6 3

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

const ll N =5e6+5;
ll f[N];
ll lpf[N],npf[N];
void fun()
{
	for(ll i=2;i<N;i++) 
		if (!lpf[i]) {
			lpf[i]=i;
			for(ll j=i*i;j<N;j+=i) if(!lpf[j]) lpf[j]=i;
		}

	f[1]=npf[1]=0;
	for(ll i=2;i<N;i++)
		npf[i]=1+npf[i/lpf[i]];

	for(ll i=2;i<N;i++)
		f[i]=npf[i]+f[i-1];
}


int solve()
{
	ll t;cin>>t;
	fun();
	while(t--)
	{
		ll a,b;cin>>a>>b;
		cout<<f[a]-f[b]<<"\n";
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