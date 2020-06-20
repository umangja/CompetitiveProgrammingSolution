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
	ll n,t,k;
	cin>>n>>t>>k;
	ll dup=k;
	vi a(t+1,1);
	a[0]=1;
	rep(i,1,t+1) cin>>a[i];
	
	if(accumulate(a.begin(), a.end(),0ll)!=n){
		cout<<-1<<"\n"; return 0;
	}

	vvi adj(n,vi ());

	vi sf(t+1,0);
	sf[t]=a[t];
	repr(i,t-1,-1) sf[i] = sf[i+1]+a[i]-1;
	// debug_v(sf);
	vi prev;
	prev.pb(0);

	ll cur = 1;
	rep(lvl,1,t+1)
	{
		vi q;
		// cout<<"ok";
		// tot a[lvl] // leaf = a[i] -1 - (sf[lvl]-k); non leaf = 1+sf[lvl]-k
		ll nl = min(min(1+sf[lvl-1]-k,a[lvl-1]),a[lvl]);
		ll cur_par = 0;

		if(sz(prev)<nl || nl==0)
		{
			cout<<"-1\n";
			return 0;
		}


		rep(i,0,a[lvl])
		{
			adj[prev[cur_par]].pb(cur);
			q.pb(cur);
			cur++;
			cur_par=(cur_par+1)%nl;
		}

		ll leaf = a[lvl-1]-nl;
		k-=leaf;
		
		// cout<<lvl-1<<" "<<leaf<<" "<<"\n";

		prev=q;
	}

	// whatis(k);
	k-=a[t];

	if(k!=0) 
	{
		cout<<"-1\n";
		return 0;
	}

	ll cnt=0;
	vi deg(n);
	rep(i,0,n) rep(j,0,sz(adj[i])) deg[i]++,deg[adj[i][j]]++;
	rep(i,0,n) if(deg[i]==1 && i!=0) cnt++; 
	// whatis(cnt);
	if(cnt==dup)
	{
		cout<<n<<"\n";
		rep(i,0,n) rep(j,0,sz(adj[i])) cout<<adj[i][j]+1<<" "<<i+1<<"\n";
	}
	else cout<<-1;
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