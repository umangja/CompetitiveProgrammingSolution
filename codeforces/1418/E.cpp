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
const ll mod = 998244353;
const ll N = 2e5+5;
vi fact_mod(N),inv_fact_mod(N);

ll power(ll x,ll y)
{
	ll ans=1;
	while(y)
	{
		if(y&1) ans = (ans*x)%mod;
		y>>=1;
		x=(x*x)%mod;
	}
	return ans;
}

ll inv(ll n)
{
	return power(n,mod-2);
}

void init()
{
	fact_mod[0]=inv_fact_mod[0]=1;
	rep(i,1,N) fact_mod[i] = (fact_mod[i-1]*i)%mod,inv_fact_mod[i] = (inv_fact_mod[i-1]*inv(i))%mod;

	rep(i,1,N) assert((fact_mod[i]*inv_fact_mod[i])%mod==1);

}

ll ncr(ll n,ll r)
{
	if(r<=n && n>=0 && r>=0)
	{
		ll ans = fact_mod[n];
		ans = (ans*inv_fact_mod[n-r])%mod;
		ans = (ans*inv_fact_mod[r])%mod;
		return ans;
	}
	else return 0;
}

ll nSr(ll n,ll k)
{
	ll ans=0;
	rep(i,0,k+1)
	{
		ll temp_ans = (ncr(k,i)*power(k-i,n))%mod;
		ans = (ans+(i%2==0?1:-1)*temp_ans+mod)%mod;
	}
	ans = (ans*inv_fact_mod[k])%mod;
	return ans;
}



int solve()
{
	ll n,m;cin>>n>>m;
	vi d(n),a(m),b(m);
	rep(i,0,n) cin>>d[i];
	rep(i,0,m) cin>>a[i]>>b[i];
	
	sort(d.begin(), d.end());
	
	vi pf(n);
	rep(i,0,n) pf[i]=((i-1>=0?pf[i-1]:0)+d[i])%mod;

	rep(i,0,m)
	{
		ll idx = lower_bound(d.begin(), d.end(),b[i]) - d.begin();
		
		ll small = idx;
		ll big = n-small;
		if(a[i]>big)
		{
			cout<<"0\n";
			continue;
		}

		ll sumbig = pf[n-1] - (idx-1>=0?pf[idx-1]:0);
		
		sumbig%=mod;
		sumbig+=mod;
		sumbig%=mod;

		ll sumsmall = (idx-1>=0?pf[idx-1]:0);
	
		// whatis(big);

		// whatis(sumbig);		
		// whatis(sumsmall);


		ll temp1 = (((big-a[i])*sumbig)%mod * inv(big))%mod;
		ll temp2 = (((big-a[i]+1)*sumsmall)%mod * inv(big+1))%mod;

		// whatis(temp1);
		// whatis(temp2);

		cout<<(temp1+temp2)%mod<<"\n";
	}

	return 0;
}

int main()
{
	init();

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