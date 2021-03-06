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

int solve()
{
	ll n,m;cin>>n>>m;
	vector< pair< pii,ll > > query(m);
	vi a(n,0);
	rep(i,0,m)
	{
		cin>>query[i].F.F>>query[i].F.S>>query[i].S;
		query[i].F.F--;
		query[i].F.S--;
	} 
	ll pos=1;
	repr(bit,30,-1)
	{
		vi b(n+1,0);
		rep(i,0,m)
		{
			if(((query[i].S>>bit)&1))
			{
				b[query[i].F.F]++;
				b[query[i].F.S+1]--;
			} 
		} 

		vi pf(n,0);
		rep(i,0,n) pf[i]+=(i-1>=0?pf[i-1]:0)+b[i];
		rep(i,0,n) if(pf[i]>=1) a[i]|=(1ll<<bit);
	}

	repr(bit,30,-1)
	{
		vi b(n,0);
		vi pf(n,0);
		rep(i,0,n) if(((a[i]>>bit)&1)) b[i]=1;
		rep(i,0,n) pf[i]=(i-1>=0?pf[i-1]:0)+b[i];
		rep(i,0,m)
		{
			ll k = pf[query[i].F.S] - (query[i].F.F-1>=0?pf[query[i].F.F-1]:0);
			if(((query[i].S>>bit)&1)) { if(k!=query[i].F.S - query[i].F.F+1) pos=0; }
			else { if(k==query[i].F.S - query[i].F.F+1) pos=0;}
		}

	}



	if(pos)
	{
		cout<<"YES\n";
		rep(i,0,n) cout<<a[i]<<" ";
	}
	else cout<<"NO\n";

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