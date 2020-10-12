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

const ll N = 2e5+5;
vi bit(N,0);

void add(ll idx,ll val)
{
	for(ll i = idx+1;i<N;i+=i&-i) bit[i]+=val;
	return ;
}

ll sum(ll idx)
{
	ll ans = 0;
	for(ll i = idx+1;i>0;i-=i&-i) ans+=bit[i];
	return ans;
}

void rangeAdd(ll L,ll R,ll val)
{
	add(L,val);
	add(R+1,-val);
	return ;
}

ll actualPos(ll idx)
{
	return idx+sum(idx);
}

vvi pos(26,vi ());
vi idx(26,0);
set<ll> del;
ll ans=0;

int solve()
{
	ll n;cin>>n;
	string s;cin>>s;

	string r=s;
	reverse(r.begin(),r.end());

	rep(i,0,n) pos[s[i]-'a'].pb(i);

	rep(i,0,n)
	{
		ll ch = r[i] - 'a';
		ll  p = idx[ch]++;

		assert(p<sz(pos[ch]));

		ll j=actualPos(pos[ch][p]);
		ans+=(j-i);

		rangeAdd(0,pos[ch][p]-1,1);
	
		// cout<<ans<<"\n";
		// rep(k,0,n+1) cout<<sum(k)<<" ";
		// cout<<"\n";

	}

	// rangeAdd(0,10,2);
	// rangeAdd(0,15,3);
	// cout<<sum(0)<<" "<<sum(10)<<" "<<sum(15)<<"\n";

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