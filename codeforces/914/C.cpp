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

const ll N = 1000+5,mod = 1e9+7;
ll ft[N];
ll k;
ll dp[1000+5][2][1000+5][2];
vi num;
ll fun(ll pos,ll f,ll cnt,ll g1) //f==0 means abi tak ki same digits h 
{
	if(pos==sz(num))
	{
		// whatis(g1);
		// whatis(cnt);
		ll req = ft[cnt]+(g1);
		return dp[pos][f][cnt][g1]=(req==k);
	}

	if(dp[pos][f][cnt][g1]!=-1) return dp[pos][f][cnt][g1]; 

	ll lim = 1;
	if(f==0) lim=num[pos];
	ll ans = 0;
	rep(i,0,lim+1)
	{
		ll nf = 1;
		ll ng1 = 1;
		if(f==0 && i==lim) nf=0;

		if(g1==1) ng1=1;
		else
		{
			if(i==0) ng1=0;
			else if(pos==sz(num)-1) ng1=0;
			else ng1=1;
		}
		ans = (ans+fun(pos+1,nf,cnt+i,ng1))%mod;
	}

	return dp[pos][f][cnt][g1] = ans;
}

pair<string,ll> div(string &s)
{
	ll rem = 0;
	string ans = "";
	rep(i,0,sz(s))
	{
		ll dd = s[i]-'0';
		ll cur = 10*rem+dd;
		ans += (char)(cur/2+'0');
		rem  = cur%2;
	}

	return mp(ans,rem);
}

int solve()
{
	ft[0] = inf;
	ft[1] = 0;
	rep(i,2,N) ft[i] = ft[__builtin_popcount((unsigned int)i)]+1;

	memset(dp,-1,sizeof dp);
	string n;
	cin>>n>>k;

	rep(i,0,sz(n))
	{
		assert(n[i]-'0'<=1);
		num.pb(n[i]-'0');
	} 
	cout<<fun(0ll,0ll,0ll,0)<<"\n";
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