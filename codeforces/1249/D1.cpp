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
const ll N = 205;
vi bit(N,0);
void add(ll idx,ll val)
{
	for(ll i = idx+1;i<N;i+=(i&-i)) bit[i]+=val;
	return ;
}

ll prefix_sum(ll l)
{
	ll ans=0;
	for(ll i = l+1;i>0;i-=(i&-i)) ans+=bit[i];
	return ans;
}

bool cmp(pair< pii,ll> a,pair< pii,ll> b)
{
	if(a.F.S==b.F.S) return  a.F.F<b.F.F;
	return a.F.S>b.F.S;
}

int solve()
{
	ll n,k;cin>>n>>k;
	vpii a(n);
	rep(i,0,n)
	{
		cin>>a[i].F>>a[i].S;
		add(a[i].F,1);
		add(a[i].S+1,-1);
	} 

	ll ans=0;
	vi vis(n,0);
	vi ansv;
		
	// whatis(prefix_sum(11));

	rep(i,0,N-1)
	{
		ll p = prefix_sum(i);
		if(p>k)
		{
			vector< pair< pii,ll> > temp;
			rep(j,0,n) if(a[j].F<=i && vis[j]==0) temp.pb(mp(a[j],j));
			sort(temp.begin(), temp.end(),cmp);
			ll del = p-k;
			rep(j,0,del)
			{
				ans++;
				vis[temp[j].S]=1;
				// whatis(temp[j].S);
				ansv.pb(temp[j].S);
				add(temp[j].F.F,-1);
				add(temp[j].F.S+1,+1);
			}
		}
	}

	cout<<ans<<"\n";
	rep(i,0,ans) cout<<ansv[i]+1<<" ";


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