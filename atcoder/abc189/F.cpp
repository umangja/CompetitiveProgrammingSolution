/*input
100000 2 2
2997 92458

*/


// assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll          double
#define pb          push_back
#define pii         pair<ll ,ll >
#define vpii        vector< pii >
#define vi          vector<ll >
#define vs			vector< string >
#define vvi         vector< vector< ll > >
#define inf			(ll)1e18
#define all(it,a)   for(auto it=(a).begin();it!=(a).end();it++) 
#define F           first
#define S           second
#define sz(x)       (ll )x.size()
#define rep(i,a,b)	for(ll  i=a;i<b;i++)
#define repr(i,a,b) for(ll  i=a;i>b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define whatis(x)   cout << #x << " is " << x << "\n";
#define graph(n)    adj(n,vector< ll > () )
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define debug(x)     cout << #x << " " << x << endl;
#define debug_p(x)   cout << #x << " " << x.F << " " << x.S << endl;
#define debug_v(x)   {cout << #x << " "; for (auto ioi : x) cout << ioi << " "; cout << endl;}
#define debug_vp(x)  {cout << #x << " "; for (auto ioi : x) cout << '[' << ioi.F << " " << ioi.S << ']'; cout << endl;}
#define debug_v_v(x) {cout << #x << "/*\n"; for (auto ioi : x) { for (auto ioi2 : ioi) cout << ioi2 << " "; cout << '\n';} cout << "*/" << #x << endl;}

int solve()
{
	ll n,m,k;
	cin>>n>>m>>k;

	vi A(n+1,0);
	for(int i=0;i<k;i++){
		int x;cin>>x;
		A[x]=1;
	}

	int pos=1;
	for(int i=0;i<=n && pos==1 && m<=k;i++){
		
		int j = i;
		int cnt=0;
		while(j<n && A[j]==1 && cnt<m) j++,cnt++;

		if(cnt>=m) pos=0; 
	}

	if(pos==0){
		cout<<"-1\n";
		return 0;
	}

	vpii dp(n+1); 

	dp[n] = mp(0,0);

	ll sum = 0, nA = 0, sumA=0;
	for(ll i=n-1;i>=0;i--)
	{
		// dp[i] = 1+ (nA*X + sum) /M;
		if(A[i] == 1) nA++;
		else{
			dp[i].F = 1 + sum/m;
			dp[i].S = (nA + sumA)/m;
		
			sum+=dp[i].F;
			sumA+=dp[i].S;
		}

		if(i+m<=n) {
			if(A[i+m]==1) nA--;
			else sum -= dp[i+m].F,sumA-=dp[i+m].S;
		}

		// cout<<dp[i].F<<" "<<dp[i].S<<"\n";
	}
	double ans = (dp[0].F)/(1ll-(dp[0].S));
	cout<<setprecision(15)<<ans<<"\n";

	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll test_cases=1;
	//cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	//cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}