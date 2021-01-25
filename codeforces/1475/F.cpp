/*input
3
3
110
001
110

000
000
000
3
101
010
101

010
101
010
2
01
11

10
10

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

ll n;
vvi a,b;

void optCol(vvi &dup,ll j)
{
	for(int i=0;i<n;i++) dup[i][j]^=1;
}

void optRow(vvi &dup,ll i)
{
	for(int j=0;j<n;j++) dup[i][j]^=1;
}

int solve()
{
	cin>>n;
	a.assign(n,vi (n,0));
	b.assign(n,vi (n,0));
	rep(i,0,n)
	{
		string s;cin>>s;
		rep(j,0,n) a[i][j] = s[j]-'0';
	}	

	rep(i,0,n)
	{
		string s;cin>>s;
		rep(j,0,n) b[i][j] = s[j]-'0';
	}	

	ll pos = 0;

	vvi dup = a;
	for(int j=0;j<n;j++) if(dup[0][j]!=b[0][j]) optCol(dup,j);

	ll pos1=1;
	for(int i=1;i<n;i++)
	{
		ll dif = 0;
		for(int j=0;j<n;j++) if(dup[i][j]!=b[i][j]) dif++;
		if(dif==0 || dif==n) continue;
		else pos1=0; 
	}

	dup = a;

	for(int i=0;i<n;i++) if(dup[i][0]!=b[i][0]) optRow(dup,i);

	ll pos2=1;
	for(int j=1;j<n;j++)
	{
		ll dif = 0;
		for(int i=0;i<n;i++) if(dup[i][j]!=b[i][j]) dif++;
		if(dif==0 || dif==n) continue;
		else pos2=0; 
	}

	if(pos1==1 || pos2==1) cout<<"YES\n";
	else cout<<"NO\n";

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
	cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	//cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}