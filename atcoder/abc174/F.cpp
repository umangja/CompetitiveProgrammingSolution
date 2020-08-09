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
const ll N = 5e5+1000;
ll n,q;
vi c;
vi bit(N,0);

void add(ll idx,ll val)
{
	for(ll i = idx+1;i<N;i+=(i&-i)) bit[i]+=val;
	return ;
}

ll sum(ll idx)
{
	ll ans=0;
	for(ll i = idx+1;i>0;i-=(i&-i)) ans+=bit[i];
	return ans;
}

ll rangeSum(ll L,ll R)
{
	if(L==0) return sum(R);
	else  return sum(R)-sum(L-1);
}


int solve()
{
	cin>>n>>q;
	c.clear();   
	c.resize(n); 
	rep(i,0,n) cin>>c[i];

	vector< pair<pii,ll> > query(q); // [R,L],index

	rep(i,0,q)
	{
		cin>>query[i].F.S>>query[i].F.F;
		query[i].F.S--;
		query[i].F.F--;
		query[i].S=i;
	}

	sort(query.begin(), query.end());
	ll r = -1;
	vi last(n+10,-1);
	vi ans(q);
	rep(i,0,q)
	{
		while(r<query[i].F.F)
		{
			r++;
			ll prev = last[c[r]];
			last[c[r]]=r;
			if(prev!=-1) add(prev,-1);
			add(r,1);
		}

		assert(r==query[i].F.F);

		ll L = query[i].F.S;
		ll R = query[i].F.F;

		ans[query[i].S] = rangeSum(L,R);
	}

	rep(i,0,q) cout<<ans[i]<<"\n";

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