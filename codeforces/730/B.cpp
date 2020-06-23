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
ll n,k;
ll cnt;

char query(ll i,ll j)
{
	assert(cnt+1<=k);
	cnt++;
	cout<<"? "<<i+1<<" "<<j+1<<"\n"<<flush;
	char x;cin>>x;
	return x;
}

void print(ll mn,ll mx)
{
	cout<<"! "<<mn+1<<" "<<mx+1<<"\n"<<flush;
	return ;
}

int solve()
{
	cin>>n;
	k = (3*n+1)/2-2;
	cnt=0;

	if(n==1) {print(0,0); return 0;}

	vi mx,mn;
	for(ll i=0;i<n;i+=2)
	{
		if(i+1==n)
		{
			mx.pb(i);
			mn.pb(i);
			continue;
		}

		ll j = i+1;
		char x = query(i,j);
		if(x=='>')
		{
			mx.pb(i);
			mn.pb(j);
		}
		else if(x=='<')
		{
			mx.pb(j);
			mn.pb(i);
		}
		else 
		{
			mx.pb(i);
			mn.pb(i);
		}
	}

	while(sz(mx)>=2)
	{
		vi mxt,mnt;
		for(ll idx=0;idx<sz(mx);idx+=2)
		{
			ll i = mx[idx];
			ll j = (idx+1<sz(mx)?mx[idx+1]:mx[idx-1]);
			if(idx+1==sz(mx))
			{
				mxt.pb(mx[idx]);
				continue;
			}
			char x = query(i,j);
			if(x=='>') mxt.pb(i);
			else  mxt.pb(j);
		}

		for(ll idx=0;idx<sz(mn);idx+=2)
		{
			ll i = mn[idx];
			ll j = (idx+1<sz(mn)?mn[idx+1]:mn[idx-1]);
			if(idx+1==sz(mn))
			{
				mnt.pb(mn[idx]);
				continue;
			}

			char x = query(i,j);
			if(x=='>') mnt.pb(j);
			else  mnt.pb(i);
		}

		mn = mnt;
		mx = mxt;
	}

	print(mn[0],mx[0]);
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