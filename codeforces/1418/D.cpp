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
map<ll,ll> cnt1,cnt2;
set<ll> st1,st2;

void rem(ll w,ll val)
{
	if(w==0) 
	{
		if(--cnt1[val]==0) st1.erase(val);
	}
	else
	{
		if(--cnt2[val]==0) st2.erase(val);
	}

	return ;
}

void add(ll w,ll val)
{
	if(w==0) st1.insert(val),cnt1[val]++;
	else 	 st2.insert(val),cnt2[val]++;
	return ;
}

int solve()
{
	ll n,q;cin>>n>>q;
	vi a(n);
	rep(i,0,n) cin>>a[i];
	sort(a.begin(), a.end());
	// ans = mx - mn  - max(dist);


	vi ansf;

	rep(i,0,n) cnt1[a[i]]++,st1.insert(a[i]);
	rep(i,1,n) 
	{
		ll d = a[i]-a[i-1];
		cnt2[d]++;
		st2.insert(d);
	}

	ll ans = -1;		
	if(sz(st1)!=0 && sz(st2)!=0) ans = *st1.rbegin() - *st1.begin() - *st2.rbegin();
	else ans=0;
	ansf.pb(ans);

	rep(i,0,q)
	{
		ll t,x;
		cin>>t>>x;

		if(t==0)
		{
			// rem
			auto it = st1.upper_bound(x);
			
			ll nxval = inf;
			if(it!=st1.end()) nxval = *it;

			it = st1.lower_bound(x);
			ll pvval = -1;
			if(it!=st1.begin())
			{
				it--;
				pvval = *it;
			}

			if(nxval!=inf) rem(1,nxval-x);
			if(pvval!=-1)  rem(1,x-pvval);

			if(nxval!=inf && pvval!=-1) add(1,nxval-pvval);

			rem(0,x);
		}
		else
		{
			auto it = st1.upper_bound(x);
			
			ll nxval = inf;
			if(it!=st1.end()) nxval = *it;

			it = st1.lower_bound(x);
			ll pvval = -1;
			if(it!=st1.begin())
			{
				it--;
				pvval = *it;
			}

			if(nxval!=inf) add(1,nxval-x);
			if(pvval!=-1)  add(1,x-pvval);

			if(nxval!=inf && pvval!=-1) rem(1,nxval-pvval);

			add(0,x);
		}

		if(sz(st1)!=0 && sz(st2)!=0) ans = *st1.rbegin() - *st1.begin() - *st2.rbegin();
		else ans=0;
		ansf.pb(ans);
	}

	assert(sz(ansf)==q+1);
	rep(i,0,sz(ansf)) cout<<ansf[i]<<"\n";	

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