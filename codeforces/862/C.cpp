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

ll N = 1e6-3*1e5;
int solve()
{
	ll n,x;
	cin>>n>>x;
	ll dup=n;

	list<ll> ans;	
	if(x==0)
	{
		if(n==2)
		{
			cout<<"NO\n";
			return 0;
		}

		rep(i,0,n/4)
		{
			assert((N^(N+1)^(N+2)^(N+3))==0);
			rep(j,0,4) ans.pb(N++);
		}

		n%=4;

		if(n==1) ans.pb(0);
		else if(n==2)
		{
			ans.pop_front();
			ans.pop_front();
			ans.pop_front();
			ans.pop_front();


			ans.pb(1);
			ans.pb(2);
			ans.pb(3);

			ans.pb((1<<19)|1);
			ans.pb((1<<18)|2);
			ans.pb((1<<19)|(1<<18)|3);

		}
		else if(n==3)
		{
			ans.pb(1);
			ans.pb(2);
			ans.pb(3);

		} 

		cout<<"YES\n";
		all(it,ans) cout<<*it<<" ";

		return 0;
	}

	if(x!=0) n--,ans.pb(x);

	rep(i,0,n/4)
	{
		assert((N^(N+1)^(N+2)^(N+3))==0);
		rep(j,0,4) ans.pb(N++);
	} 

	n%=4;
	// whatis(n);
	if(n==1) ans.pb(0);
	else if(n==2) 
	{
		ans.pop_front();
		ans.pb((1<<19)|x);
		ans.pb((1<<18)|x);
		ans.pb((1<<19)|(1<<18)|x);
	}
	else if(n==3)
	{
		// whatis(sz(ans));
		ans.pb((1<<17));
		ans.pb((1<<18));
		ans.pb((1<<17)|(1<<18));
	}

	assert(sz(ans)==dup);
	
	ll t=0;
	all(it,ans) t^=(*it);
	// whatis(t);
	if(t==x)
	{
		cout<<"YES\n";
		all(it,ans) cout<<*it<<" ";
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