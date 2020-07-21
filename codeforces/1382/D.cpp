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

ll n;
vi a,nge;
vvi dp;

ll fun(ll pos,ll len1)
{
	// cout<<pos<<"\n";
	if(pos>=n) return (len1==0);
	if(len1<0) return 0;
	assert(pos<n);
	assert(len1<n);
	if(dp[pos][len1]!=-1) return dp[pos][len1];
	
	// ll cur1 = n/2-len1;
	// ll cur2 = pos-cur1;

	ll ans = 0;
	assert(pos<sz(nge));
	ll j = nge[pos];
	ll l1 = j-pos;

	// in array 1
	ans|=fun(j,len1-l1);

	//in array 2
	ans|=fun(j,len1);

	return dp[pos][len1]=ans;
}


int solve()
{
	cin>>n;n*=2;

	a.clear();
	dp.clear();
	nge.clear();

	a.resize(n);
	nge.resize(n);
	dp.resize(n,vi (n,-1));

	rep(i,0,n) cin>>a[i];

	stack<ll> st;
	repr(i,n-1,-1)
	{
		while(!st.empty() && a[st.top()]<a[i]) st.pop();
		if(!st.empty()) nge[i]=st.top();
		else nge[i]=n;
		st.push(i);
	}

	// if(n==1)
	// {
	// 	// solve
	// 	return 0;
	// }

	// O(n^2)

	// cout<<n<<"\n";
	cout<<(fun(0,n/2)?"YES\n":"NO\n");


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
	cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	//cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}