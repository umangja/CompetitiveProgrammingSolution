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

ll n,m,q;
int solve()
{
	cin>>n>>m>>q;
	vi w(n);
	rep(i,0,n) cin>>w[i];

	vi p10(n,1);
	rep(i,1,n) p10[i]=p10[i-1]*2;

	ll max_num = (1<<n);
	vector<ll> cnt(max_num,0);
	rep(i,0,m)
	{
		string s;cin>>s;
		ll no = 0;
		rep(j,0,n) no+=(s[j]-'0')*p10[n-1-j];
		cnt[no]++;
	} 

	vvi score(max_num, vi(101,0));
	vi f(max_num,0);

	rep(num,0,max_num) rep(b,0,n) if(((num>>b)&1)==0) f[num]+=w[n-1-b];


	rep(num,0,max_num)
	{
		rep(num2,0,max_num)
		{
			ll ans = f[num^num2];
			if(ans<101) score[num][ans]+=cnt[num2];
		}
	}

	vvi prefix_sum(max_num,vi (101,0));
	rep(num,0,max_num) rep(j,0,101) prefix_sum[num][j] = (j-1>=0?prefix_sum[num][j-1]:0) + score[num][j];

	while(q--)
	{
		string s;cin>>s;
		ll no = 0;
		rep(i,0,n) no+=(s[i]-'0')*p10[n-1-i];
		cnt[no]++;

		ll k;cin>>k;
		// whatis(no);
		cout<<prefix_sum[no][k]<<"\n";

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
	//cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}