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

ll check(vi a)
{
	rep(i,0,sz(a)) if(a[i]!=i+1) return 0;
	return 1;
}

int solve()
{
	ll n;cin>>n;
	vi a(n);
	rep(i,0,n) cin>>a[i];

	if(check(a))
	{
		cout<<"0";
		return 0;
	}

	vvi ansf;

	while(!check(a))
	{
		vector<pii> temp;
		rep(i,0,n)
		{
			ll j = i+1;
			while(j<n && a[j]==a[j-1]+1) j++;
			temp.pb(mp(i,j-1));
			i=j-1;
		}

		// debug_vp(temp);


		vi ans;
		ll m = sz(temp);
		if(a[temp[m-1].S]==n)
		{
			ll sr = a[temp[m-2].S]+1;
			ll j = 0;
			while(j<m && a[temp[j].F]!=sr) j++;
			assert(j!=m);

			
			ll sum=0;
			rep(i,0,j) sum+=temp[i].S-temp[i].F+1;
			
			ans.pb(sum);
			ans.pb(temp[j].S-temp[j].F+1);
			
			sum=0;
			rep(i,j+1,m-1) sum+=temp[i].S-temp[i].F+1;
			
			ans.pb(sum);
			ans.pb(temp[m-1].S-temp[m-1].F+1);
		}
		else
		{
			ll sr = a[temp[m-1].S]+1;
			ll j = 0;
			while(j<m && a[temp[j].F]!=sr) j++;
			assert(j!=m);
			// whatis(j);

			ll sum=0;
			rep(i,0,j) sum+=temp[i].S-temp[i].F+1;
			ans.pb(sum);

			ans.pb(temp[j].S-temp[j].F+1);
			
			sum=0;
			rep(i,j+1,m) sum+=temp[i].S-temp[i].F+1;
			ans.pb(sum);
			
		}

		// debug_v(ans);

		vi newarray;
		ll j = n-1;
		repr(i,sz(ans)-1,-1)
		{
			ll siz = ans[i];
			rep(k,j-siz+1,j+1) newarray.pb(a[k]);
			j-=siz;
		}

		vi temp2;
		rep(i,0,sz(ans)) if(ans[i]) temp2.pb(ans[i]);

		ansf.pb(temp2);

		a=newarray;		
		// debug_v(a);
		// assert(sz(a)==n);
	}

	assert(check(a));
	cout<<sz(ansf)<<"\n";
	rep(i,0,sz(ansf))
	{
		vi temp2 = ansf[i];
		cout<<sz(temp2)<<" ";
		rep(j,0,sz(temp2)) cout<<temp2[j]<<" ";
		cout<<"\n";
	}


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