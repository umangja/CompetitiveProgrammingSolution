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

ll dp[102][2][102];
ll k;
vi num;
ll fun(ll pos,ll f,ll cnt)
{
	if(pos==sz(num))
	{
		if(cnt==k) return 1;
		else return 0;
	}

	if(dp[pos][f][cnt]!=-1) return dp[pos][f][cnt];
	ll lim=9;
	if(f) lim=num[pos];
	ll ans=0;
	rep(i,0,lim+1)
	{
		ll nf = 0;
		if(f==1 && i==lim) nf=1;
		ans+=fun(pos+1,nf,cnt+(i!=0));
	}

	return dp[pos][f][cnt]=ans;
}

int solve()
{
	memset(dp,-1,sizeof dp);
	string n;cin>>n>>k;
	rep(i,0,sz(n)) num.pb(n[i]-'0');
	cout<<fun(0,1,0)<<"\n";
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