/*input
2
4
40 56 48 40 80 56 80 48
6
240 154 210 162 174 154 186 240 174 186 162 210

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
	ll pos=1;
	vi d(2*n);
	vi a;
	map<ll,ll> cnt,vis;
	rep(i,0,2*n) cin>>d[i],cnt[d[i]]++;

	rep(i,0,2*n){
		if(cnt[d[i]]!=2 || (d[i]%2==1)){
			pos=0;
			break;
		}
		else{
			if(vis[d[i]]==0){
				a.pb(d[i]);
				vis[d[i]]=1;
			}
		} 
	}

	if(pos==1){
		assert(sz(a)==n);
		sort(a.begin(), a.end(),greater<ll> ());
		// debug_v(a);
		vi dd(n,0);
		rep(i,1,n){
			if((a[i-1]-a[i])%2==1) pos=0;
			if(pos==1){
				ll dif = a[i-1] - a[i];
				// whatis(dif);
				ll mul = (2*(n-i));
				// whatis(mul);
				if(dif%mul!=0) pos=0;
				else dd[i] = dif/mul; 
			}
		} 

		// debug_v(dd);

		{
			ll i = n-1;
			ll dif = a[n-1];
			ll mul = 2;
			ll sum = 0;
			for(int j = 1;j<n;j++){
				sum+=dd[j]*mul;
				// whatis(sum);
				mul+=2;
			} 
			// whatis(sum);
			// whatis(dif);
			dif-=sum;
			mul = n;
			if(dif<=0 || dif%(2*mul)!=0 ) pos=0;
			else dd[i] = dif/mul;

		}


	}

	cout<<(pos==1?"Yes\n":"No\n");

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