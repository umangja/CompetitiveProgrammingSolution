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
	ll n;cin>>n;
	vi a(n);
	vi par(n,-1);
	ll pos=1;
	rep(i,0,n) cin>>a[i];

	vi lf;
	ll prev = -1;
	ll st = -1;
	ll d=0;
	vi deg(n,0);
	set<ll> sst;
	rep(i,0,n)
	{
		if(a[i]==1)
		{
			if(st!=-1)
			{
				// cout<<"ok\n";
				deg[st]++;
				deg[i]++;

				// whatis(a[i]);
				// whatis(st);

				par[i]=st;

				d++;
				st=-1;
			}
			else lf.pb(i);
		} 
		else 
		{
			if(prev == -1) prev = i,st=i;
			else
			{
				// cout<<"ok\n";

				sst.insert(i);
				sst.insert(prev);

				deg[i]++;
				deg[prev]++;

				par[i]=prev;	
				prev=i;
				
				d++;
			} 
		}
	}

	if(prev==-1)
	{
		cout<<"NO";
		return 0;
	}

	if(st!=-1 && sz(lf))
	{
		// cout<<"ok\n";
		ll cur = lf[sz(lf)-1];
		lf.pop_back();

		deg[st]++;
		deg[cur]++;

		par[cur]=st;

		d++;
		st=-1;
	}

	// debug_v(par);
	
	// whatis(prev);
	// whatis(deg[prev]);
	// whatis(sz(lf));

	ll cnt=0;
	rep(i,0,sz(lf))
	{
		ll cur = lf[i];
		if(deg[prev]+1<=a[prev])
		{
			deg[prev]++;
			deg[cur]++;
			par[cur]=prev;
			if(cnt==0) d++,cnt=1;
		}
		else
		{
			sst.erase(prev);

			if(sst.empty())
			{
				pos=0;
				cout<<"NO";
				return 0;
			} 
			else prev = *sst.begin();
			i--;
		}
	}




	if(pos==0) cout<<"NO";
	else 
	{
		cout<<"YES "<<d<<"\n";
		cout<<n-1<<"\n";
		rep(i,0,n) if(par[i]!=-1) cout<<i+1<<" "<<par[i]+1<<"\n";
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