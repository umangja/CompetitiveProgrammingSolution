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
const ll N = 2e5+5;
vi power3(20);
vi good;

ll fun(ll n)
{
	vi ans;
	ll k=1;
	repr(i,19,-1)
	{
		ll t = n/power3[i];
		if(t>=2) k=0;
	 	ans.pb(t);
		n-=t*power3[i];
	}

	return k;
}

int solve()
{
	ll n;cin>>n;
	cout<<*lower_bound(good.begin(), good.end(),n)<<"\n";
	// vi rep = fun(n);

	// debug_v(rep);

	// ll ans = n;
	// ll carry=0;
	// ll cnt=0;
	// ll mx = -1;
	// repr(i,sz(rep)-1,-1)
	// {
	// 	ll t = rep[i];
	// 	if(t>0) mx=max(mx,cnt);
	// 	ll tot =  t+carry;

	// 	if(tot<=1)
	// 	{
	// 		carry=0;
	// 		cnt++;
	// 	}
	// 	else
	// 	{
	// 		ll add = 3 - tot%3;
	// 		if(add==3) add=0;
	// 		// whatis(cnt);
	// 		// whatis(add);
	// 		ans+=add*power3[cnt];
	// 		tot = tot+add;
	// 		assert(tot%3==0);
	// 		carry = tot/3;
	// 		cnt++;
	// 	}
	// }

	// rep = fun(ans);
	// debug_v(rep);
	// // ll temp_ans = power3[mx+1];
	// // ans=min(ans,temp_ans);
	// assert(carry==0);
	// cout<<ans<<"\n";



	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	power3[0]=1;
	rep(i,1,20) power3[i] = power3[i-1]*3;   

	rep(i,1,N) if(fun(i)) good.pb(i);


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