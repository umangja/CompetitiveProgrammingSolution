/*input

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

#define ll          long long int
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


vvi dp1;
vvi dp2,dp3;

vi a;
ll fun(ll l,ll r,ll s)
{
	if(s==0)
	{
		if(dp2[l][r]!=-1) return dp2[l][r];
		if(l==r) return dp2[l][r]=1;
		else
		{
			rep(k,l+1,r+1) if(dp1[l][k]!=1 && fun(l+1,k,1) && fun(k,r,0)) return dp2[l][r]=1;
			return dp2[l][r]=0;
		}
	}
	else
	{
		if(dp3[l][r]!=-1) return dp3[l][r];
		if(l==r) return dp3[l][r]=1;
		else
		{
			rep(k,l,r) if(dp1[r][k]!=1 && fun(l,k,1) && fun(k,r-1,0)) return dp3[l][r]=1;
			return dp3[l][r]=0;
		}
	}
}

int solve()
{
	ll n;cin>>n;
	a.assign(n,0);
	rep(i,0,n) cin>>a[i];

	dp3.assign(n,vi (n,-1));
	dp2.assign(n,vi (n,-1));
	dp1.assign(n,vi (n,0));


	rep(i,0,n) rep(j,0,n) dp1[i][j]=__gcd(a[i],a[j]);

	ll ans = 0;
	rep(i,0,n) if(fun(0,i,1) && fun(i,n-1,0)) {ans=1; break;}
	cout<<(ans==1?"Yes":"No");
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
	//cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}