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
ll n,k,l;
vi d;

ll fun(ll t)
{
	t%=2*k;
	ll add = t;
	if(add>k)
	{
		add=(add-k);
		add = k-add;
	}

	return add; 
}

int solve()
{
	cin>>n>>k>>l;
	d.resize(n+2);
	d[0]  = -inf;
	rep(i,1,n+1) cin>>d[i];
	d[n+1]= -inf;

	rep(i,0,n+2)
	{
		if(d[i]>l)
		{
			cout<<"NO\n";
			return 0;
		} 
	}

	vector<ll> safe;
	rep(i,0,n+2) if(d[i]+k<=l) safe.pb(i);
	// debug_v(safe);
	rep(i,0,sz(safe)-1)
	{
		ll cur  = safe[i];
		ll next = safe[i+1];

		ll st = k;
		rep(j,cur,next)
		{
			st%=(2*k);
			if(d[j+1]+fun(st+1)<=l) st++;
			else
			{
				// high tide
				if( (j==cur && st<k ) || (j>cur && st<=k) ) 
				{
					cout<<"NO\n";
					return 0;
				}
				else //low tide
				{
					// wait
					ll val = l - d[j+1];
					// whatis(val);
					st = k+(k-val);
				}


			}
		}

	}

	cout<<"YES\n";

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
	cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	//cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}