/*input
5
1 2 1 2 1 

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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define debug(x)     cout << #x << " " << x << endl;
#define debug_p(x)   cout << #x << " " << x.F << " " << x.S << endl;
#define debug_v(x)   {cout << #x << " "; for (auto ioi : x) cout << ioi << " "; cout << endl;}
#define debug_vp(x)  {cout << #x << " "; for (auto ioi : x) cout << '[' << ioi.F << " " << ioi.S << ']'; cout << endl;}
#define debug_v_v(x) {cout << #x << "/*\n"; for (auto ioi : x) { for (auto ioi2 : ioi) cout << ioi2 << " "; cout << '\n';} cout << "*/" << #x << endl;}
const ll SMax = 5e6+5;
int solve()
{
	ll n;cin>>n;
	// n = 2e5+5;
	vpii a(n);
	rep(i,0,n){
		cin>>a[i].F;
		// a[i].F = rng()%(SMax/2);
		a[i].S = i;
	} 
	sort(a.begin(), a.end());

	vector<vector<pii>> sum(SMax, vpii ());

	n = min(n,10000ll);

	int pos = 0;
	ll ans[4];
	for(int i=0; i<n && pos==0; i++){
		for(int j=i+1; j<n && pos==0; j++){
			ll s = a[i].F+a[j].F;
			sum[s].pb(mp(a[i].S,a[j].S));
			for(int k=0; k<sz(sum[s])-1; k++){
				ans[0] = sum[s][k].F;
				ans[1] = sum[s][k].S;
				ans[2] = sum[s][sz(sum[s])-1].F;
				ans[3] = sum[s][sz(sum[s])-1].S;
				if(ans[0]!=ans[1] && ans[0]!=ans[2] && ans[0]!=ans[3] && ans[1]!=ans[2] && ans[1]!=ans[3] && ans[2]!=ans[3]) pos=1;
			}
		}
	}

	if(pos) {
		cout<<"YES\n";
		cout<<ans[0]+1<<" "<<ans[1]+1<<" "<<ans[2]+1<<" "<<ans[3]+1<<"\n";
	}
	else cout<<"NO\n";

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
	// cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	//cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}