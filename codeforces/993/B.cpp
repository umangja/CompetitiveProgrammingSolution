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
	ll n,m;
	cin>>n>>m;
	vpii a(n),b(m);
	rep(i,0,n) 
	{
		ll x,y;cin>>x>>y;
		if(x>y) swap(x,y);
		a[i] = mp(x,y);
	}

	rep(i,0,m)
	{
		ll x,y;cin>>x>>y;
		if(x>y) swap(x,y);
		b[i] = mp(x,y);
	}

	set<ll> pos;
	rep(i,0,n)
	{
		rep(j,0,m)
		{
			if(a[i].F==b[j].F && a[i].S!=b[j].S) pos.insert(a[i].F);
			else if(a[i].F==b[j].S && a[i].S!=b[j].F) pos.insert(a[i].F);
			else if(a[i].S==b[j].F && a[i].F!=b[j].S) pos.insert(a[i].S);
			else if(a[i].S==b[j].S && a[i].F!=b[j].F) pos.insert(a[i].S);
		}
	}

	// all(it,pos) cout<<*it<<"\n";

	if(sz(pos)==1)
	{
		cout<<*pos.begin();
		return 0;
	}

	ll w1=1;
	rep(i,0,n)
	{
		pos.clear();
		rep(j,0,m)
		{
			if(a[i].F==b[j].F && a[i].S!=b[j].S) pos.insert(a[i].F);
			else if(a[i].F==b[j].S && a[i].S!=b[j].F) pos.insert(a[i].F);
			else if(a[i].S==b[j].F && a[i].F!=b[j].S) pos.insert(a[i].S);
			else if(a[i].S==b[j].S && a[i].F!=b[j].F) pos.insert(a[i].S);

		}
		// whatis(sz(pos));
		if(sz(pos)>=2) w1=0;
	}


	ll w2=1;
	rep(j,0,m)
	{
		pos.clear();
		rep(i,0,n)
		{
			if(a[i].F==b[j].F && a[i].S!=b[j].S) pos.insert(a[i].F);
			else if(a[i].F==b[j].S && a[i].S!=b[j].F) pos.insert(a[i].F);
			else if(a[i].S==b[j].F && a[i].F!=b[j].S) pos.insert(a[i].S);
			else if(a[i].S==b[j].S && a[i].F!=b[j].F) pos.insert(a[i].S);
			
		}
		// whatis(sz(pos));
		if(sz(pos)>=2) w2=0;
	}

	if(w1==0 || w2==0) cout<<-1;
	else cout<<0;

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