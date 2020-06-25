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

vvi fun(ll k)
{
	vvi ans;
	if(k==0)
	{
		vi t;
		t.pb(1);
		ans.pb(t);
		return ans;
	}

	if(k==1)
	{
		vi t1 = {1,1};
		vi t2 = {1,-1};
		ans.pb(t1);
		ans.pb(t2);

		return ans;
	}

	vvi prev=fun(k-1);

	for(ll i=0;i<sz(prev);i+=2)
	{
		vi t1,t2;
		rep(j,0,sz(prev[i])) t1.pb(prev[i][j]);
		rep(j,0,sz(prev[i+1])) t2.pb(prev[i+1][j]);

		// debug_v(t1);
		// debug_v(t2);

		
		vi t;
		rep(j,0,sz(t1)) t.pb(t1[j]);
		rep(j,0,sz(t2)) t.pb(t2[j]);
		ans.pb(t);

		t.clear();
		rep(j,0,sz(t1)) t.pb(-1*t1[j]);
		rep(j,0,sz(t2)) t.pb(t2[j]);
		ans.pb(t);

		t.clear();
		rep(j,0,sz(t1)) t.pb(t2[j]);
		rep(j,0,sz(t2)) t.pb(t1[j]);
		ans.pb(t);

		t.clear();
		rep(j,0,sz(t1)) t.pb(-1*t2[j]);
		rep(j,0,sz(t2)) t.pb(t1[j]);
		ans.pb(t);
	}

	return ans;

}

int solve()
{
	string s;cin>>s;
	ll n = sz(s);
	vi fq(26,0);
	ll o=0,e=0;
	rep(i,0,n) fq[s[i]-'a']++;
	rep(i,0,26) if(fq[i]&1) o++; else e++;


	while(o>1)
	{
		ll id1=-1,id2=-1;
		rep(i,0,26) if(fq[i]&1) {id1=i; break;}
		repr(i,25,-1) if(fq[i]&1) {id2=i; break;}
		
		if(id1!=-1) fq[id1]++,fq[id2]--,o-=2;

	}


	string ansl = "",ansr = "";
	rep(i,0,26)
	{
		rep(j,0,fq[i]/2) ansl+=(char)('a'+i);
		rep(j,0,(fq[i])/2) ansr+=(char)('a'+i);
	}

	rep(i,0,26) if(fq[i]&1) ansl+=(char)('a'+i);
	reverse(ansr.begin(), ansr.end());
	string ans = ansl+ansr;
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