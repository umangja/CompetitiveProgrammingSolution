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
	string a,b,c;cin>>a>>b>>c;
	
	vi fq(26,0);
	rep(i,0,sz(a)) fq[a[i]-'a']++;

	vi fqb(26,0);
	rep(i,0,sz(b)) fqb[b[i]-'a']++;


	vi fqc(26,0);
	rep(i,0,sz(c)) fqc[c[i]-'a']++;

	ll ansx=0,ansy=0,ans=0;
	rep(x,0,sz(a))
	{
		vi temp(26);
		ll ok=1;
		rep(i,0,26)
		{
			if(fq[i]>=x*fqb[i]) temp[i] = fq[i]-x*fqb[i];
			else ok=0;
		}

		if(ok)
		{
			ll y = inf;
			rep(i,0,26) if(fqc[i]!=0) y=min(y,temp[i]/fqc[i]);
			if(x+y>ans && ok==1)
			{
				ans=x+y;
				ansx=x;
				ansy=y;
			}
		}

	}
	string ansf="";
	rep(i,0,ansx) ansf+=b;
	rep(i,0,ansy) ansf+=c;

	rep(i,0,26)
	{
		fq[i]-=ansx*fqb[i]+ansy*fqc[i];
		rep(j,0,fq[i]) ansf+=(char)(i+'a');
	} 

	cout<<ansf<<"\n";

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