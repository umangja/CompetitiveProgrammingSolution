/*input
5 4 4
3 2
3 4
4 2
5 2


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

const ll N = 2e5+5;
vi bit(N,0);
void add(ll idx,ll val)
{
	for(ll i = idx+1;i<N;i+=i&-i) bit[i]+=val;
}

ll prefixSum(ll idx)
{
	ll sum=0;
	for(ll i = idx+1;i>0;i-=i&-i) sum+=bit[i];
	return sum;
}

int solve()
{
	ll h,w,m,ans=0;
	cin>>h>>w>>m;
	vector<ll> row(h,w),col(w,h);
	rep(i,0,m)
	{
		ll x,y;cin>>x>>y;
		x--,y--;
		row[x] = min(row[x],y);
		col[y] = min(col[y],x);
	}


	/* 
		0 0 0 0 1 5
		0 0 1 0 0 3
		0 1 0 0 0 2
		0 0 0 0 0 6
		0 0 0 1 0 4
		1 0 0 0 0 
		0 1 0 0 0
 	*/
	rep(i,0,col[0]) ans+=row[i];

	vpii b;
	rep(j,0,row[0]) b.pb(mp(col[j],j));
	sort(b.begin(), b.end());

	ll L = 0;
	ll cnt=0;
	rep(i,0,sz(b))
	{
		pii p = b[i];
		while(L<p.F && L<col[0]) 
		{
			add(row[L],1);
			cnt++;
			L++;
		}

		ans+=col[p.S] - ( cnt - prefixSum(p.S-1));
	}

	cout<<ans<<"\n";
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