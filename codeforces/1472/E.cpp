/*input
1

5
10 20
5 15
15 5
8 10
9 7


3
3 4
5 4
3 3
3
1 3
2 2
3 1
4
2 2
3 1
6 3
5 4
4
2 2
2 3
1 1
4 4

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

void fun(vector<pair<pii,ll>> &a,vi &ans)
{
	ll n = sz(a);
	sort(a.begin(), a.end());
	vector<ll> wIdx(n);
	ll mnVal = inf,mnIdx = -1;

	// rep(i,0,n) cout<<a[i].F.F<<" "<<a[i].F.S<<"\n"; cout<<"\n\n";

	rep(i,0,n)
	{
		ll idx = lower_bound(a.begin(), a.end(),mp(mp(a[i].F.F,-1ll),-1ll)) - a.begin()-1;
		if(idx>=0)
		{
			ll posAnsIdx = wIdx[idx];
			if(a[posAnsIdx].F.S < a[i].F.S) ans[a[i].S] = a[posAnsIdx].S+1;
		}

		if(a[i].F.S < mnVal)
		{
			mnVal = a[i].F.S;
			mnIdx = i;
		}

		wIdx[i] = mnIdx;
	}

	return ;

}


void fun2(vector<pair<pii,ll>> &a,vi &ans)
{
	ll n = sz(a);
	sort(a.begin(), a.end());

	// rep(i,0,n) cout<<a[i].F.F<<" "<<a[i].F.S<<" "<<a[i].S+1<<"\n"; 
	// cout<<"\n\n";
	
	vector<ll> wIdx(n);
	ll mnVal = inf,mnIdx = -1;
	rep(i,0,n)
	{

		if(a[i].F.S < mnVal)
		{
			mnVal = a[i].F.S;
			mnIdx = i;
		}

		wIdx[i] = mnIdx;
	}

	rep(i,0,n)
	{
		ll idx = lower_bound(a.begin(), a.end(),mp(mp(a[i].F.S,-1ll),-1ll)) - a.begin()-1;
		if(idx>=0)
		{
			ll posAnsIdx = wIdx[idx];
			if(a[posAnsIdx].F.S < a[i].F.F) ans[a[i].S] = a[posAnsIdx].S+1;
		}
	}

	return ;

}



int solve()
{
	ll n;cin>>n;
	vector<pair<pii,ll>> a(n);
	rep(i,0,n)
	{
		cin>>a[i].F.F>>a[i].F.S;
		a[i].S = i;
	} 

	vi ans(n,-1);

	fun(a,ans);
	fun2(a,ans);
	
	rep(i,0,n) cout<<ans[i]<<" "; cout<<"\n";


	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
	
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);

	ll test_cases=1;
	cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	//cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}