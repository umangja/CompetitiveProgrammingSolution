/*input
5 2
1
2
3
5
4

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

const ll N = 1e5+5;
ll dp[12][N];
void add(ll tn,ll idx,ll val)
{
	for(idx++;idx<N;idx+=idx&-idx)
		dp[tn][idx]+=val;
}
ll prefix_sum(ll tn,ll idx)
{
	ll s=0;
	for(idx++;idx>0;idx-=idx&-idx)
		s+=dp[tn][idx];
	return s;
}
int solve()
{
	ll n,k;cin>>n>>k;k++;
	vi a(n);
	rep(i,0,n)
		cin>>a[i];
	
	add(0,0,1);
	rep(i,0,n)
		rep(j,1,k+1)
			add(j,a[i],prefix_sum(j-1,a[i]-1));
	cout<<prefix_sum(k,n);
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