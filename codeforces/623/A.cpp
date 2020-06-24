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

ll n,m;
vvi adj;
void lost()
{
	cout<<"No\n";
	exit(0);
}
int solve()
{
	cin>>n>>m;

	if(m==0)
	{
		if(n==1) cout<<"Yes\n"<<"a";
		else if(n==2) cout<<"Yes\n"<<"ac"<<"\n";
		else lost();
		return 0;
	}

	adj.assign(n,vi ());
	rep(i,0,m)
	{
		ll x,y;cin>>x>>y;
		x--,y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	rep(i,0,n) adj[i].pb(i);

	rep(i,0,n) sort(adj[i].begin(), adj[i].end());

	ll num = 0;
	map<ll,ll> b;
	rep(i,0,n)
	{
		if(b.find(i)!=b.end()) continue;
		else
		{
			b[i]=num++;
			rep(j,0,n) if(i!=j && adj[i]==adj[j]) b[j]=b[i];
		} 
	} 
	if(num>3) lost();
	rep(i,0,n) if(b.find(i)==b.end()) lost();

	// rep(i,0,n) cout<<b[i]<<" ";

	map<ll,char> c;
	ll ok=0;
	rep(i,0,n)
	{
		set<ll> st;
		rep(j,0,sz(adj[i])) st.insert(b[adj[i][j]]);
		if(sz(st)==3)
		{
			c[b[i]]='b';
			all(it,st)
			{
				if(c.find(*it)==c.end())
				{
					if(ok==0) c[*it]='a',ok=1;
					else c[*it]='c';
				} 
			} 
			break;
		} 
	}


	if(sz(c)==0)
	{
		c[0]='a';
		c[1]='c';
		c[2]='b';
	} 

	string ans = "";
	rep(i,0,n) ans+=c[b[i]];
	cout<<"Yes\n"<<ans<<"\n";

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