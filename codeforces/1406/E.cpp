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
const ll N = 1e5 , M = (ll)sqrt(N)+2 , maxQ = 10000-1;
vi primes;
ll cntQ = 0;
set<ll> st;
ll act = 9931;
bool isPrime(ll n)
{
	for(ll i = 2;i*i<=n;i++) if(n%i==0) return false;
	return true;
}

ll n;
void init()
{
	for(int i=2;i<=n;i++) if(isPrime(i)) primes.pb(i);
	return ;
}


ll query(char c,ll v)
{
	assert(cntQ<maxQ);
	cout<<c<<" "<<v<<"\n"<<flush; cntQ++;
	ll x;cin>>x;
	assert(x!=-1);
	return x;
}

// ll query(char c,ll v)
// {
// 	assert(cntQ<maxQ);
	
// 	ll x = 0;	
// 	for(ll i = v;i<=n;i+=v)
// 	{
// 		if(st.find(i)!=st.end())
// 		{
// 			x++;
// 			if(c=='B' && i!=act)
// 			{
// 				st.erase(i);
// 				// if(v*v>n) cout<<i<<" ";
// 			} 
// 		} 
// 	}

// 	assert(x!=-1);
// 	cntQ++;

// 	return x;
// }


int solve()
{

	cin>>n;
	init();
	ll ans  = 1;

	rep(i,1,n+1) st.insert(i);

	ll idx = 0;
	while(idx<sz(primes) && primes[idx]*primes[idx]<=n)
	{
		ll  p = primes[idx++];
		// whatis(p);
		query('B',p);

		ll cur = p;
		while(cur*p<=n) cur*=p;
		while(cur>1)
		{
			ll x = query('A',cur);
			if(x>=1)
			{
				ans*=cur;
				break;
			}
			cur/=p;
		}
	}

	// all(it,st)cout<<*it<<" ";
	// cout<<"\n";

	ll tot = query('A',1ll);
	// whatis(tot);
	while(idx<sz(primes))
	{
		ll R = min(sz(primes),idx+100);
		ll sum = 0;
		rep(i,idx,R)
		{
			ll p = primes[i];
			// whatis(p);
			sum+=query('B',p);
		}



		ll totNow = query('A',1ll);
		// whatis(totNow);
		ll cons = R-idx;
		if(totNow>tot-cons || sum>cons)
		{
			rep(i,idx,R)
			{
				ll p = primes[i];
				ll x = query('B',p);
				if(x!=0)
				{
					ans*=p;
					break;
				}
			}
			break;
		}
		else tot-=cons;

		idx = R;
	}

	// whatis(idx);
	// whatis(sz(primes));
	cout<<"C "<<ans<<"\n"<<flush;



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