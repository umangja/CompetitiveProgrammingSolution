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
const ll N = 1e5+5;
ll x,y;
vi s(3);
vvi d(3,vi ());
int solve()
{	
	cin>>x>>y;

	rep(i,0,3) cin>>s[i];
	vi ans;
	rep(i,0,3) 
	{
		d[i].assign(s[i],-1);
		rep(j,0,s[i]) cin>>d[i][j];
		sort(d[i].begin(), d[i].end(),greater<ll> ());
		if(i==0) rep(j,0,x) ans.pb(d[i][j]);
		if(i==1) rep(j,0,y) ans.pb(d[i][j]);
		if(i==2) rep(j,0,min(x+y,s[i])) ans.pb(d[i][j]);
	}

	sort(ans.begin(), ans.end(),greater<ll> ());
	ll sum=0;
	rep(i,0,x+y) sum+=ans[i];
	cout<<sum<<"\n";



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