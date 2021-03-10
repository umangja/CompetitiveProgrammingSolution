/*input
5
1 2 5 4 3

7
2 5 7 3 1 4 6



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
	ll n;cin>>n;
	vi a(n);
	rep(i,0,n) cin>>a[i];
	vi L(n,0),R(n,0);
	for(int i=0;i<n;i++){
		ll j = i+1;
		while(j<n && a[j]>a[j-1]) j++;
		for(ll k = i; k<j; k++) L[k] = k - i;
		i = j-1;
	}

	for(int i=0; i<n; i++){
		ll j = i+1;
		while(j<n && a[j]<a[j-1]) j++;
		for(ll k = i; k<j; k++) R[k] = j -1 -k;
		i = j-1;
	}

	// debug_v(L);
	// debug_v(R);

	ll mx = -1,times = 0;
	for(ll i=0;i<n;i++){
		ll j = i+1;
		while(j<n && a[j] > a[j-1]) j++;
		ll temp = j-i-1;
		if(temp>mx){
			mx = temp;
			times = 1;
		}
		else if(temp==mx){
			times++;
		}
		i = j-1;
	}
	reverse(a.begin(), a.end());
	for(ll i=0;i<n;i++){
		ll j = i+1;
		while(j<n && a[j] > a[j-1]) j++;
		ll temp = j-i-1;
		if(temp>mx){
			mx = temp;
			times = 1;
		}
		else if(temp==mx){
			times++;
		}
		i = j-1;
	}

	// cout<<mx<<" "<<times<<"\n";



	ll ans=0;
	for(ll i=0;i<n;i++){
		ll b = max(L[i],R[i]);
		ll s = min(L[i],R[i]);

		if(b==s){
			if(b<mx) continue;
			else{
				if(times>2) continue;
				else if(b%2==1) continue;
				else{
					// cout<<i+1<<"\n";
					ans++;
				} 
			}
		}
		// else if(b%2==1) continue;
		// else{
		// 	if(b<mx) continue;
		// 	else{
		// 		if(b%2==1) continue;
		// 		else{
		// 			cout<<i<<"\n";
		// 			ans++;
		// 		} 	
		// 	}			
		// }


	}

	cout<<ans<<"\n";

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
