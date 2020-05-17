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
	string s;
	cin>>s;

	ll n = sz(s);

	vvi pos(3,vi ());
	rep(i,0,n) pos[s[i]-'1'].pb(i);
	rep(i,0,3) if(sz(pos[i])==0) { cout<<"0\n"; return 0;}

	ll ans = n;
	rep(i,0,sz(pos[0]))
	{
		ll p = pos[0][i];
		ll p1 = -1;
		ll idx = upper_bound(pos[1].begin(), pos[1].end(),p) - pos[1].begin();
		if(idx<sz(pos[1]))
		{
			p1 = pos[1][idx];
			ll p2 = -1; 
			ll idx2 = upper_bound(pos[2].begin(), pos[2].end(),p) - pos[2].begin();
			if(idx2<sz(pos[2])) 
			{
				p2 = pos[2][idx2];
				ans=min(ans,max({p,p1,p2}) - min({p,p1,p2})+1);
			}

			idx2--;
			if(idx2>=0)
			{
				p2 = pos[2][idx2];
				ans=min(ans,max({p,p1,p2}) - min({p,p1,p2})+1);
			}

		} 

		idx--;
		if(idx>=0)
		{
			p1 = pos[1][idx]; 
			ll p2 = -1; 
			idx = upper_bound(pos[2].begin(), pos[2].end(),p) - pos[2].begin();
			// cout<<p1<<" "<<p2<<" "<<p<<"\n";
			if(idx<sz(pos[2]) )
			{
				p2 = pos[2][idx];
				ans=min(ans,max({p,p1,p2}) - min({p,p1,p2})+1);
			}

			idx--;
			if(idx>=0)
			{
				p2 = pos[2][idx];
				ans=min(ans,max({p,p1,p2}) - min({p,p1,p2})+1);
			}

		}

	}	

	cout<<ans<<"\n";

	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

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