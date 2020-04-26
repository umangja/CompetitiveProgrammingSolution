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
const ll M = 2019,mod = 2019;
ll inv_10  = 0;

ll modInverse(ll a, ll m) 
{ 
    a = a%m; 
    for (ll x=1; x<m; x++)  if ((a*x) % m == 1)  return x;
    return -1; 
} 
		
int solve()
{
	string s;cin>>s;
	ll n = sz(s);

	inv_10 = modInverse(10ll,M);
	// whatis(inv_10);

	vi dp1(M,0);
	vi dp2(M,0);

	ll ans=0;

	ll mm = 2019 * 205;
	vi vec_mod(mm);
	rep(i,0,mm) vec_mod[i] = i%M;	

	rep(i,0,n)
	{
		rep(m,0,M)
		{
			if(i==0) dp2[m] = ((s[i]-'0')==m);
			else
			{
				ll d = (s[i]-'0');
				ll k;
				if(m-d>=0) k = m-d;
				else k = M+m-d;
				k = vec_mod[k*inv_10];
				dp2[m] = dp1[k] + (d==m);
			} 
		}
		ans+=dp2[0];
		rep(m,0,M) dp1[m]=dp2[m];
	}

	cout<<ans<<"\n";





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