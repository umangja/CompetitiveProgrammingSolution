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
const ll N = 3e3+5;
map<string,ll> ha;
map<ll,string> hashr;
vi a;
int solve()
{
	ll n;cin>>n;
	a.resize(n);
	vvi cnt(N,vi ());
	rep(i,0,n)
	{
		string s;cin>>s;
		ha[s]=i;
		hashr[i]=s;
		cin>>a[i];
		cnt[a[i]].pb(i);
	}


	ll pos=1;

	ll mx = 2*n;
	vi order;
	vi h(n);

	rep(i,0,n)
	{
		rep(j,0,sz(cnt[i]))
		{
			ll person = cnt[i][j];
			// whatis(person);
			h[person]=mx;
			ll cnt2=0;
			ll idx = (sz(order)==0?0:-1);
			
			rep(k,0,sz(order))
			{
				if(h[order[k]]>mx) cnt2++;
				if(cnt2==i)
				{
					idx=i;
					break;
				} 
			}
			// whatis(idx);
			if(idx==-1 && cnt2==i) idx = sz(order);
			if(idx==-1)
			{
				cout<<"-1\n";
				return 0;
			} 
			else order.insert(order.begin()+idx,person);
		}
		mx--;
	}


	if(!pos) cout<<"-1";
	else
	{
		rep(i,0,sz(order))
		{
			ll p = order[i];
			cout<<hashr[p]<<" "<<h[p]<<"\n";
		}
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