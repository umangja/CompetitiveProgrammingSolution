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

#define debug(x)     cout << #x << "\n" << x << endl;
#define debug_p(x)   cout << #x << "\n" << x.F << "\n" << x.S << endl;
#define debug_v(x)   {cout << #x << "\n"; for (auto ioi : x) cout << ioi << "\n"; cout << endl;}
#define debug_vp(x)  {cout << #x << "\n"; for (auto ioi : x) cout << '[' << ioi.F << "\n" << ioi.S << ']'; cout << endl;}
#define debug_v_v(x) {cout << #x << "/*\n"; for (auto ioi : x) { for (auto ioi2 : ioi) cout << ioi2 << "\n"; cout << '\n';} cout << "*/" << #x << endl;}


void bubbleSort(vi &arr, ll n)  
{  
    ll i, j;  
    for (i = 0; i < n-1; i++) for (j = 0; j < n-i-1; j++)  if (arr[j] > arr[j+1])  swap(arr[j], arr[j+1]);  
} 


ll fun(vi v)
{
	bubbleSort(v,4);
	ll s = accumulate(v.begin(), v.end(),0ll);
	if(s==4*(v[3]-v[0]) && s==2*(v[1]+v[2])) return 1;
	else return 0;
}

int solve()
{
	ll n;cin>>n;
	if(n==0)
	{
		cout<<"YES\n"<<1<<"\n"<<1<<"\n"<<3<<"\n"<<3<<"\n";
		return 0;
	}
	else if(n==4)
	{
		vi v(4);
		rep(i,0,n) cin>>v[i];
		if(fun(v)) cout<<"YES\n";
		else cout<<"NO\n";
	}
	else if(n==3)
	{
		vi a(3);
		rep(i,0,n) cin>>a[i];

		rep(i,1,2000)
		{
			vi v = a;
			v.pb(i);
			if(fun(v))
			{
				cout<<"YES\n"<<i<<"\n";
				return 0;
			}
		}

		cout<<"NO\n";
	}
	else if(n==2)
	{
		vi a(2);
		rep(i,0,n) cin>>a[i];

		rep(i,1,1501) rep(j,i,1501)
		{
			vi v = a;
			v.pb(i);
			v.pb(j);
			if(fun(v))
			{
				cout<<"YES\n"<<i<<"\n"<<j<<"\n";
				return 0;
			}
		}

		cout<<"NO\n";
	}
	else
	{
		ll x;cin>>x;
		vi a;
		rep(i,x,3*x+1) rep(j,i,3*x+1)
		{
			vi v = a;
			v.pb(x);
			v.pb(i);
			v.pb(j);
			v.pb(3*x);
			if(fun(v))
			{
				cout<<"YES\n"<<i<<"\n"<<j<<"\n"<<3*x<<"\n";
				return 0;
			}
		}

		if(x%3==0)
		{
			rep(i,x/3,x) rep(j,i,x)
			{
				vi v = a;
				v.pb(x/3);
				v.pb(i);
				v.pb(j);
				v.pb(x);
				if(fun(v))
				{
					cout<<"YES\n"<<x/3<<"\n"<<i<<"\n"<<j<<"\n";
					return 0;
				}
			}
		}

		rep(i,1,2000)
		{
			rep(j,i,2000)
			{
				vi v = a;
				v.pb(i);
				v.pb(j);
				v.pb(x);
				v.pb(3*i);
				if(fun(v))
				{
					cout<<"YES\n"<<i<<"\n"<<3*i<<"\n"<<j<<"\n";
					return 0;
				}
			}
		}

		cout<<"NO\n";
		return 0;
	}
	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

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