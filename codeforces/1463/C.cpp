/*input
8
3
1 5
3 0
6 4
3
1 5
2 4
10 -5
5
2 -5
3 1
4 1
5 1
6 1
4
3 3
5 -3
9 2
12 0
8
1 1
2 -6
7 2
8 3
12 -9
14 2
18 -1
23 9
5
1 -4
4 -7
6 -1
7 -3
8 -7
2
1 2
2 -2
6
3 10
5 5
8 0
12 -4
14 -7
19 -5

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

ll check(ll L,ll R,ll x)
{
	if(L>R) swap(L,R);
	return x>=L && x<=R;
}

int solve()
{
	ll n;cin>>n;
	vpii a(n);
	rep(i,0,n) cin>>a[i].F>>a[i].S;
	sort(a.begin(), a.end());

	vi isGood(n,0);
	vpii X(n);
	vpii T(n);

	ll pos=0,t=0,k = 0;
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		if(a[i].F>=t)
		{
			isGood[i]=1;
			ll dist = abs(pos-a[i].S);
			T[i] = mp(a[i].F,a[i].F+dist);
			X[i] = mp(pos,a[i].S);
			pos = a[i].S;
			t = T[i].S;
			k=i;
		}
		else isGood[i]=0;

		ll XL = X[k].F;
		ll XR = X[k].S;

		ll TL = T[k].F;
		ll TR = T[k].S;

		if(a[i].F>TL)
		{
			ll d = a[i].F-TL;
			if(XL<XR) XL+=d;
			else XL-=d;
		}

		if( i+1<n && a[i+1].F<TR ) 
		{
			ll d = TR-a[i+1].F;
			if(XR>XL) XR-=d;
			else XR+=d;
		}
		// whatis(a[i+1].F);
		// whatis(TR);
		// cout<<XL<<" "<<XR<<"\n";
		ans+=check(XL,XR,a[i].S);
	}

	// debug_v(isGood);
	// debug_vp(T);
	// debug_vp(X);



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
	cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	//cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}