/*input
8
2
1 7
3
1 2 4
4
5 5 5 5
5
6 2 2 1 0
1
0
1
1
6
1 12 123 1234 12345 123456
5
536870912 536870911 1152921504606846975 1152921504606846974 1152921504606846973

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

const ll mod = 1e9+7,M = 61;
vi power2(M);
ll findBit(ll x,ll b)
{
	return (x>>b)&1;
}

int solve()
{
	ll n;cin>>n;
	vi a(n);
	rep(i,0,n) cin>>a[i];

	ll ans=0;
	vvi cnt(2,vi (M,0));
	rep(i,0,n) rep(j,0,M) cnt[findBit(a[i],j)][j]++;

	rep(i,0,n)
	{
		ll temp1 = 0;
		ll temp2 = 0;
		rep(j,0,M)
		{
			ll b = findBit(a[i],j);
			if(b==1)
			{
				temp1+=(power2[j]*cnt[1][j])%mod;
				if(temp1>=mod) temp1-=mod;
			
				temp2+=(power2[j]*n)%mod;
				if(temp2>=mod) temp2-=mod;
			}
			else
			{
				temp2+=(power2[j]*cnt[1][j])%mod;
				if(temp2>=mod) temp2-=mod;
			}
		}
		ans+=(temp1*temp2)%mod;
		ans%=mod;
	}

	cout<<ans<<"\n";


	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	power2[0]=1;
	rep(i,1,M) power2[i]=(power2[i-1]*2)%mod;

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