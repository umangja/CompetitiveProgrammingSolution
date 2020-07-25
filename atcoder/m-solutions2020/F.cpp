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

// up left dwn right
vpii dir = {mp(0,1),mp(-1,0),mp(0,-1),mp(1,0)};
map<char,ll> m;
vector<vector<pii>> planes(4,vpii ());
ll ans = inf;

bool cmp(const pii &a,const pii &b)
{
	if(a.S==b.S) return a.F<b.F;
	return a.S<b.S;
}

void fun()
{

	// rep(i,0,4) debug_vp(planes[i]);
	// cout<<"\n";

	// u,d
	unordered_map<ll,set<ll>> st;
	rep(i,0,sz(planes[2])) st[planes[2][i].F].insert(planes[2][i].S);
	rep(i,0,sz(planes[0]))
	{
		ll x = planes[0][i].F;
		ll y = planes[0][i].S;

		auto it = st[x].ubnd(y);
		if(it!=st[x].end()) ans=min(ans,(*it-y)*5);
	}

	// whatis(ans);

	sort(planes[0].begin(), planes[0].end(),cmp);
	sort(planes[1].begin(), planes[1].end(),cmp);

	unordered_map<ll, set<pii> > dif;
	rep(i,0,sz(planes[1])) dif[planes[1][i].F-planes[1][i].S].insert(planes[1][i]);
	ll j=0;
	rep(i,0,sz(planes[0]))
	{
		ll x = planes[0][i].F;
		ll y = planes[0][i].S;
		// debug_p(planes[0][i]);
		// debug_p(planes[1][j]);

		while(j<sz(planes[1]) && planes[1][j].S<y) dif[planes[1][j].F-planes[1][j].S].erase(planes[1][j]),j++;
		auto it = dif[x-y].ubnd(mp(x,-1ll));
		if(it!=dif[x-y].end()) ans=min(ans,10*(it->F-x));
	}
	// whatis(ans);
	return ;
}

int solve()
{
	ll n;cin>>n;
	rep(i,0,n)
	{
		ll x,y;cin>>x>>y;
		char c;cin>>c;
		planes[m[c]].pb(mp(x,y));
	}


	rep(i,0,4) sort(planes[i].begin(), planes[i].end());
	rep(i,0,4)
	{
		fun();
		vpii temp = planes[3];
		repr(j,3,0) planes[j]=planes[j-1];
		planes[0]=temp;
		rep(j,0,4) rep(k,0,sz(planes[j])) swap(planes[j][k].F,planes[j][k].S),planes[j][k].F*=-1;

	}

	if(ans==inf) cout<<"SAFE";
	else cout<<ans;

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

	m['U'] = 0;
	m['L'] = 1;
	m['D'] = 2;
	m['R'] = 3;


	ll test_cases=1;
	//cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	//cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}