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
	ll a,b,k;cin>>a>>b>>k;

	if(k==0){
		// equals
		
		string ans = "";
		rep(i,0,b) ans+='1';
		rep(i,0,a) ans+='0';
		cout<<"Yes\n";
		cout<<ans<<"\n"<<ans<<"\n";
		return 0;
	}


	vvi num(2,vi (2,0));
	num[0][0] = num[1][0] = a;
	num[0][1] = num[1][1] = b;


	vi ans1,ans2;

	if(k>a+b-2 || ((b==1 || a==0) && k!=0) ){
		cout<<"No\n";
		return 0;
	}

	ans1.pb(1); num[0][1]--;
	ans2.pb(1); num[1][1]--;

	num[0][1]--;
	num[1][1]--;

	num[0][0]--;
	num[1][0]--;

	ans1.pb(1); 
	ans2.pb(0);


	rep(i,0,k-1){
		if(num[0][0]>0 && num[1][0]>0) {
			ans1.pb(0);
			ans2.pb(0);
			num[0][0]--;
			num[1][0]--;
		}
		else if(num[0][1]>0 && num[1][1]>0) {
			ans1.pb(1);
			ans2.pb(1);
			num[0][1]--;
			num[1][1]--;
		}
		else {
			assert(0);
		}
	}

	ans1.pb(0);
	ans2.pb(1);

	assert(num[1][0]==num[0][0]);
	assert(num[1][1]==num[0][1]);

	assert(sz(ans1)+num[0][0] + num[0][1] == a+b);


	rep(i,0,2){
		while(num[0][i]>0 && num[1][i]>0){
			ans1.pb(i);
			ans2.pb(i);

			num[0][i]--;
			num[1][i]--;
		}
	}

	assert(sz(ans1)==sz(ans2));
	// assert(sz(ans1)==(a+b));



	cout<<"Yes\n";
	rep(i,0,sz(ans1)) cout<<ans1[i]; 
	cout<<"\n";
	rep(i,0,sz(ans2)) cout<<ans2[i]; 
	cout<<"\n";




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