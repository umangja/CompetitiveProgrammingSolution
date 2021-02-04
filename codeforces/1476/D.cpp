/*input
2
6
LRRRLL
3
LRL

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

const ll N = 3e5+5;

int solve()
{
	ll n;cin>>n;
	string s;cin>>s;

	vvi Left(n+1,vi (2,1)), Right(n+1,vi(2,1));

	// c ---- c ---- c ----- c ---- c    , n=4

	repr(i,n-1,-1) {
		Right[i][0] = 1 + ( s[i]=='R'?Right[i+1][1]:0);
		Right[i][1] = 1 + ( s[i]=='L'?Right[i+1][0]:0);
	}

	rep(i,1,n+1){
		Left[i][0] = 1 + (s[i-1]=='L'?Left[i-1][1]:0);
		Left[i][1] = 1 + (s[i-1]=='R'?Left[i-1][0]:0);
	}

	for(int i=0;i<n+1;i++){

		int ans = 1;

		if(i<n && s[i]=='R') ans += Right[i+1][1];
		if(i>0 && s[i-1]=='L') ans += Left[i-1][1];

		cout<<ans<<" ";
	}

	cout<<"\n";


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