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

const ll mod = 1e9+7;
ll power(ll x,ll y)
{
	x%=mod;
	if(x<0) x+=mod;
	x%=mod;

	// y%=(mod-1) //valid only if mod is prime number; 

	ll ans=1;
	while(y)
	{
		if(y&1)
		{
			ans = (ans*x)%mod;
		} 
		y>>=1;
		x=(x*x)%mod;
	}
	return ans;
}

int solve()
{
	ll n;cin>>n;
	ll tot=0;

	vpii v(n);
	map<pii,ll> cnt;
	
	rep(i,0,n)
	{
		ll x,y;
		cin>>x>>y;

		if(x==0 && y==0)
		{
			tot++;
			continue;
		} 

		ll g = __gcd(x,y);
		x/=g;
		y/=g;


		if(x<0 && y<0) x*=-1,y*=-1;
		if(x<0 && y>0) x*=-1,y*=-1; 

		if(x==0) cnt[mp(1ll,x)]++;
		else if(y==0) cnt[mp(0ll,1ll)]++;
		else cnt[mp(y,x)]++;
	}

	ll ans=1;

	// all(it,cnt) cout<<(*it).F.F<<" "<<(*it).F.S<<"\n";
	map<pii,ll> vis;
	all(it,cnt)
	{
		pii m1 = it->F;

		pii m2;

		if(m1.F==0) m2=mp(1ll,0ll);
		else if(m1.S==0) m2=mp(0ll,1ll);
		else 
		{
			if(m1.F>0) m2=mp(-1*m1.S,m1.F);
			else if(m1.F<0) m2=mp(m1.S,-1*m1.F);
		}


		if(vis[m1]==1 || vis[m2]==1) continue;
		vis[m1]=1;
		vis[m2]=1;


		ll temp = ((power(2,cnt[m1]) + power(2,cnt[m2]))%mod - 1+mod)%mod;
		ans*=temp;
		ans%=mod;
	}

	cout<<((ans-1+tot+mod)%mod+mod)%mod<<"\n";

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