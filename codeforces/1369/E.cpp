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
unordered_set<ll> food;
unordered_set<ll> child;
vector<unordered_set<ll>> siz;
priority_queue<pii,vpii,greater<pii>> pq;
vi w;
vi vis;
vpii b;

vi ans;


void fun()
{
	vi del_child;
	ll go=0;

	while(!pq.empty())
	{
		pii p = pq.top();
		pq.pop();

		if(p.F<0 || food.find(p.S)==food.end()) continue;
		ll fd = p.S;
		if( w[fd]>=sz(siz[fd]) )
		{
			food.erase(fd);
			go=1;
			all(it2,siz[fd])
			{
				if(vis[*it2]==0)
				{
					vis[*it2]=1,ans.pb(*it2);
					del_child.pb(*it2);
				} 
			} 
			break;
		}
	}

	set<ll> ch;

	for(auto x:del_child) 
	{
		siz[b[x].F].erase(x);
		siz[b[x].S].erase(x);							
		ch.insert(b[x].F);
		ch.insert(b[x].S);

	}

	for(auto x:ch) pq.push(mp(w[x]-sz(siz[x]),x));
	if(go==1) fun();
	return ;
}

int solve()
{
	ll n,m;cin>>n>>m;
	
	w.resize(n);
	b.resize(m);
	siz.resize(n);
	vis.assign(m,0);

	rep(i,0,n) cin>>w[i],food.insert(i);
	rep(i,0,m)
	{
		child.insert(i);
		ll x,y;cin>>x>>y;
		x--,y--;
		if(x>y) swap(x,y);

		b[i] = mp(x,y);
		siz[x].insert(i);
		siz[y].insert(i);
	}

	rep(i,0,n) pq.push(mp(w[i]-sz(siz[i]),i));

	fun();
	reverse(ans.begin(), ans.end());
	if(sz(ans)==m) { cout<<"ALIVE\n"; rep(i,0,m) cout<<ans[i]+1<<" ";} 
	else cout<<"DEAD\n";

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