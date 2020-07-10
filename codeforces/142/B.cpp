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
const ll N = 1005;
ll dx[]   = {2,-2};
ll dy[]   = {1,-1};
ll n,m;
vvi col(N,vi (N,-1));
ll check(ll x,ll y)
{
	if(x>=0 && y>=0 && x<n && y<m && col[x][y]==-1) return 1;
	return 0;
}

void bfs(ll u,ll v,ll c,ll &cnt0,ll &cnt1)
{

	queue< pair<pii,ll> > q;
	q.push(mp(mp(u,v),c));

	while(!q.empty())
	{
		pair<pii,ll> p = q.front();
		q.pop();

		if(col[p.F.F][p.F.S]!=-1) continue;
		col[p.F.F][p.F.S]=p.S;
		u = p.F.F;
		v = p.F.S;
		c = p.S;

		// cout<<u<<" "<<v<<" "<<c<<"\n";

		if(c==0) cnt0++;
		else cnt1++;


		rep(i,0,2) rep(j,0,2) 
		{
			ll x = u+dx[i];
			ll y = v+dy[j];
			if(check(x,y)) q.push(mp(mp(x,y),c^1));
		}

		rep(i,0,2) rep(j,0,2)
		{
			ll x = u+dy[j];
			ll y = v+dx[i];
			if(check(x,y)) q.push(mp(mp(x,y),c^1));
		}

	}

	return ;
}

int solve()
{
	cin>>n>>m;
	ll ans=0;
	rep(i,0,n) rep(j,0,m) if(col[i][j]==-1) {
		ll cnt0=0,cnt1=0;
		bfs(i,j,0,cnt0,cnt1);
		ans+=max(cnt0,cnt1);
	}

	cout<<ans<<"\n";



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
	//cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	//cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}