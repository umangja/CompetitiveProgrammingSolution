/*input
4
2
3 5 1 2
3
1 1 8 8 64 64
2
1 1 2 4
5
1 2 3 4 5 6 7 14 3 11

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
#define debug_v_v(x) {cout << #x << "/*\n"; for (auto ioi : x) { for (auto ioi2 : ioi) cout << ioi2 << " "; cout << '\n';} cout << "*/" << #x << endl;

int solve()
{
	ll n;cin>>n;
	vi a(2*n);
	rep(i,0,2*n) cin>>a[i];

	multiset<ll,greater<ll>> st;
	rep(i,0,2*n) st.insert(a[i]);


	
	ll cnt=0;
	for(ll x : st)
	{
		if(cnt==0) cnt^=1; 
		else
		{
			multiset<ll> st2(st.begin(), st.end());
			vpii ans;

			ll d1 = *st.begin();
			ll d2 = x;
			ll sum = d1+d2;


			while( (st2.find(d2)!=st2.end()) && (st2.find(d1)!=st2.end()) && (sz(st2)%2)==0 ) {
				
				ans.pb({d1,d2});

				// for(auto x1 :st2 ) cout<<x1<<" "; cout<<"\n";
				// cout<<d1<<" "<<d2<<"\n";

				if(st2.find(d1)!=st2.end()){
					st2.erase(st2.find(d1));
				}
				else break;

				if(st2.find(d2)!=st2.end()){
					st2.erase(st2.find(d2));
				}
				else break;

				sum = max(d1,d2);
				if(sz(st2)>0) 
				{
					d1 = *st2.rbegin();
					d2 = sum-d1;
					// cout<<d1<<" "<<d2<<"\n";
				}
				else break;
			}

			if(sz(st2)==0)
			{
				cout<<"YES\n";
				assert(sz(ans)>=1);
				cout<<ans[0].F+ans[0].S<<"\n";
				rep(i,0,sz(ans)) cout<<ans[i].F<<" "<<ans[i].S<<"\n";
				return 0;
			}
		}
	}

	cout<<"NO\n";





	// 1 2 3 3 4 5 6 7 11 14
	// 1 + 3 = 4 + 2 = 6 + 5 =  11 + 3 = 14 + 7 = 21
	// 


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