/*input
5
3 0 1
4 3 5
3 1 2
1 4 7
4 10 0
10 20 10 20
2 5 5
0 11
1 9 9
99


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
	ll n,m,k;cin>>n>>m>>k;
	vi h(n);
	rep(i,0,n) cin>>h[i];

	rep(i,0,n-1)
	{
		if(h[i+1]>=h[i])
		{

			m-=max(h[i+1]-k,(ll)0)-h[i];
		}
		else
		{
			m+=h[i]-max(h[i+1]-k,(ll)0);
		}

		if(m<0){
			cout<<"NO\n";
			return 0;
		} 
	}

	if(m<0){
		cout<<"NO\n";
	}
	else
	{
		cout<<"YES\n";
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
	cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}